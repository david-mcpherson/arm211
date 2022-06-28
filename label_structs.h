/*
 * This file contains structs that allow branch labels
 * to be mapped to memory addresses.
 */


/* We need a way to map labels to memory addresses. */
struct LabelAddressPair {
	char label[MAX_INSTRUC_LENGTH];
	unsigned address;
};


/* This struct is a wrapper for a list of label address pairs.
 * It implements basic map operations. */
struct LabelMap {
	struct LabelAddressPair[] label_list;
	int size;
	void* contains(struct LabelAddressPair[] label_list, char* search_label);
	void* getAddress(struct LabelAddressPair[] label_list, char* search_label, int size);
	void* addLabel(struct LabelAddressPair[] label_list, struct LabelAddressPair new_label, int size);
};


/* Scans label map. Returns the index off the label if present.
 * Returns -1 if the label is not present. */
int findLabel(char* label, struct LabelMap *label_map) {
	for (int i = 0; i < label_map->size; i++)
		if (!strcmp(label, label_map->label_list[i].label))
			return i;
	return -1;
}


/* Returns the address of a label in a label map. 
 * This address is a multiple of 16, so the last 4 bits
 * will be 0000.
 *
 * If the label does not exist, then the function returns -1,
 * so the last 4 bits will be 1111. */
unsigned labelToAddress(char* label, struct LabelMap *label_map) {
	int idx = findLabel(label, label_map);

	/* Need to confirm that the label exists. If it doesn't, then idx will be -1 and ~idx will be false. */
	return ~idx ? label_map->label_list[idx].address : (unsigned)(-1);
}


/* Adds a label-address pair to the map. 
 * Increments the map's size. 
 * 
 * TODO add error-checking to assert label_map->size < MAX_LINES */
void addLabelAddressPair(struct LabelAddressPair new_label, struct LabelMap *label_map) {
	label_map->label_list[label_map->size++] = new_label;
}


/* Constructor for LabelMap.
 * Initializes all fields. */
struct LabelMap newLabelMap() {
	return struct LabelMap {
		struct LabelAddressPair[MAX_LINES],
		0,
		&containsLabel,
		&labelToAddress,
		&addLabelAddressPair
	}; 
}


/* Returns the length of the label. 
 * If the instruction isn't a label declaration, then returns -1. */
int labelLength(char* instruction) {
	for (int i = 0; instruction[i] != '\n' && instruction[i] != ' ' && instruction[i] != EOF) {
		if (instruction[i] == ':') return i;
	}
	return -1;
}
