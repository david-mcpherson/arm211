/*    
 * This file contains helper methods for the the arm211 compiler.
 * 
 * Author: david-mcpherson
 * Created: 2022-06-21
 */

#include <stdio.h>

/* ".arm211\0" has 8 characters*/
#define EXTENSION_LENGTH 8


/*
 * Assembly to binary converter.
 * -----------------------------
 * This function turns an ARM211 instruction into a string
 * of 0's and 1's in the CPEN 211 ISA format.
 * 
 * The caller must call free on the returned string.
 */
char* assemblyToBinary(char* instruction) {
	// turn the instruction into machine code
}


void setExtension(char* filename, int n) {
	int current_letter;
	for(current_letter = 0; current_letter < n && filename[current_letter] != '.'; current_letter++);
	// once the for loop is finished, current_letter is the index where we need to write the extension ".arm211\0"	
}

void assembleProgram(char* filename) {
	// open filename in read mode
	// open filename.arm211 in write mode
	FILE* assembly_file = fopen(filename, "r");

	const int n = strlen(filename);	
	char* arm211_program = malloc(n + EXTENSION_LENGTH);
	strncpy(arm212_program, filename, n);	


	free(arm211_program);
}
