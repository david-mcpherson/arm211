
/*
 * Assembly to binary converter.
 * -----------------------------
 * This function turns an ARM211 instruction into a string
 * of 0's and 1's in the CPEN 211 ISA format.
 * 
 * If there's a parse error, then error_number will be set to 1.
 */
void assembleInstruction(char* binary, char* assembly, int* error_number, struct LabelMap* label_map, int* addr, int* instruc_num) {
	normalizeInstruction(assembly);
	strncpy(binary, ALL_ZERO, INSTRUCTION_LENGTH);
	int possible_label_length;

	if (!strncmp(assembly, "HALT", 4)) {	// HALT
		strncpy(binary, "111", 3);	
	} else if (assembly[0] == 'B') {		// BRANCH 
		strncpy(binary, "001", 3);
		char* label;

		/* Unconditional branch */		
		if (binary[1] == ' ') {
			strncpy(binary+5, "000", 3);
			label = assembly + 2;			// Unconditional branches have a 1-letter code and a space before the label	
		}
		/* Conditional branches */
		else { 
			switch((int)assembly[1] * 26 + (int)assembly[2]) {
 				case (int)'E' * 26 + (int)'Q':	strncpy(binary+5, "001", 3); break; 	// BEQ	
 				case (int)'N' * 26 + (int)'E':	strncpy(binary+5, "010", 3); break; 	// BNE	
 				case (int)'L' * 26 + (int)'T':	strncpy(binary+5, "011", 3); break; 	// BLT	
 				case (int)'L' * 26 + (int)'E':	strncpy(binary+5, "100", 3); break; 	// BLE	
 				default: *error_number = 1; return;
			};
			label = assembly + 4;			// Conditional branches have a 3-letter code plus a space before the label
		}
		/* Need to turn the label into a binary address */
		strncpy(binary+8, label_map->getAddress(assembly[2]));
	} else if (assembly[0] == 'M' && assembly[1] == 'O' && assembly[2] == 'V') {	// MOV 
		strncpy(binary + 5, "110", 3);
		setReg(binary, assembly[5]);

		/* Need to check whether the instruction is MOV_IMM or MOV_REG*/
		if (movReg(assembly)) {				// MOV_REG
			strncpy(binary + 3, "10", 2);
			setImmediate(binary, assembly);
		} else {							// MOV_IMM
			strncpy(binary + 3, "00", 2);
			setRdShiftRm(binary, assembly);
		}

	} else if (!strncmp(assembly, "ADD", 3) || !strncmp(assembly, "CMP", 3) || !strncmp(assembly, "ADD", 3) || !strncmp(assembly, "MVN", 3)) {
		strncpy(binary, "101", 3);
		setOP(binary, assembly);
		setRdShiftRm(binary, assembly);
	} else if (assembly[0] == 'L' && assembly[1] == 'D' && assembly[2] == 'R'		// LDR/STR
			|| assembly[0] == 'S' && assembly[1] == 'T' && assembly[2] == 'R') {
		strncpy(binary, (assembly[0] == 'L') ? "011" : "100", 3);
		setReg(binary + RN_OFFSET, assembly[ARG1]);    // set Rn
		setMemAddress(binary, assembly);
	} else if (~(possible_label_length = labelLength(assembly))) {					// LABEL DECLARATION
		assembly[possible_label_length] = '\0';	
	} else {	
		/* ParseError: No instruction found. */
		*error_number = 1;
	}
}

