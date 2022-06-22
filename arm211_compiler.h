/*    
 * This file contains helper methods for the the arm211 compiler.
 * 
 * Author: david-mcpherson
 * Created: 2022-06-21
 */

#include <stdio.h>

/* ".arm211\0" has 8 characters*/
#define EXTENSION_LENGTH 8

/* The longest posible instruction is "BEQ <label>; and we assume that <label> has a reasonable length. */
#define MAX_INSTRUC_LENGTH 40 

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


/*
 * Add the ".arm211" extension to a filename.
 * Removes any existing extensions.
 */
void setExtension(char* filename, int n) {
	int target_letter;
	for (target_letter = 0; target_letter < n && filename[target_letter] != '.'; target_letter++);
	strcpy(filename + target_letter, ".arm211\0");
}


/*
 * Takes a filename for a CPEN 211 assembly file and creates the corresponding
 * machine code, outputting it to a .arm211 file.
 */
void assembleProgram(char* filename) {
	/* We need to create a string to store the output filename. */
	const int n = strlen(filename);	
	char* arm211_program = malloc(n + EXTENSION_LENGTH);
	strncpy(arm212_program, filename, n);	
	
	/* This function reads from the input file, and outputs to an output file */
	FILE* input_file = fopen(filename, "r");
	FILE* output_file = fopen(arm211_program, "w"); 
	free(arm211_program);
	
	/* Iterate through input_file, one line at a time.
		With each line, we compile it to CPEN 211 binary,
		and write it to output_file.
	 */		

}
