
/*
 * Formats an instruction to make it easier to parse.
 * --------------------------------------------------
 * Sets all letters to upper-case, and removes spaces
 * that are adjacent to commas.
 */
void normalizeInstruction(char* s) {
	int char_index = 0;
	char* next_char = s;
	while (*next_char) {
		/* If if next_letter is a lowercase letter then make it uppercase */
		if (*next_char & ASCII_LETTER_PREFIX && *next_char & ASCII_LETTER_ID <= 26)		
			*next_char = toupper(*next_char);
		
		/* Need to remove unnecessary spaces */
		if (char_index != 4 && *next_char == ' ') {
			strcpy(next_char, next_char + 1);
		}

		char_index++;
		next_char++;
	}
}


/*
 * Sets a list of string tokens using comma-serparated arguments.
 */
void setTokens(char** toks, char* args) {
	//TODO: implement this method.	
}


/*
 * Adds the ".arm211" extension to a filename.
 * Removes any existing extensions.
 */
void setExtension(char* filename, int n) {
	int target_letter;
	for (target_letter = 0; target_letter < n && filename[target_letter] != '.'; target_letter++);
	strcpy(filename + target_letter, ".arm211\0");
}



