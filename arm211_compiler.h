/*    
 * This file contains helper methods for the the arm211 compiler.
 * 
 * Author: david-mcpherson
 * Created: 2022-06-21
 */


#include <stdio.h>

#define EXTENSION_LENGTH 	8
#define MAX_INSTRUC_LENGTH 	40 
#define BINARY_LENGTH		16

/*
 * Assembly to binary converter.
 * -----------------------------
 * This function turns an ARM211 instruction into a string
 * of 0's and 1's in the CPEN 211 ISA format.
 * 
 * The caller must call free on the returned string.
 */
void assembleInstruction(char* binary, char* assembly) {
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

	char next_letter;
	int status_code = (int)'a';
	int line_num = 0;

	/* Read input_file one line at a time */	
	while ((next_letter) = (char)fgetc(input_file) != EOF) {
		char next_instruction[MAX_INSTRUC_LENGTH + 1];
		char binary_instruction[BINARY_LENGTH];
		int letter_num = 0;
		line_num++;

		/* Fetch the next instruction one letter at a time */
		while ((next_letter) = (char)fgetc(input_file) != '\0' && next_letter != EOF && letter_num < MAX_INSTRUC_LENGTH) {
			next_instrucion[letter_num++] = next_letter;
		}

		/* Throw an error if one of the lines was too long */
		if (letter_num == MAX_INSTRUC_LENGTH) {
			fprintf(stderr, "ERROR: Instruction at line %d is too long!", line_num);
			fclose(input_file);
			fclose(output_file);
			return;
		}
	
		/* Assemble the next instruction */	
		next_instruction[letter_num] = '\0';
		assembleInstruction(binary_instruction, next_instruction);
		
		/* Write the instruction to the output file) */
		fprintf(output_file, binary_instruction);
	}

	/* We're now done assembling, and just need to close the file streams. */
	fclose(input_file);
	fclose(output_file);
}
