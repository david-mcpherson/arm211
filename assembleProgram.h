/*    
 * This file contains helper methods for the the arm211 assembler.
 * 
 * Author: david-mcpherson
 * Created: 2022-06-21
 * Updated: 2022-06-27
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "label_structs.h"
#include "tokens.h"

#define EXTENSION_LENGTH 	8
#define INSTUCTION_LENGTH	16
#define ALL_ZERO			"0000000000000000"
#define ASCII_LETTER_PREFIX	96
#define ASCII_LETTER_ID		31
#define ALPHABET_LENGTH		26


/*
 * Takes a filename for a CPEN 211 assembly file and creates the corresponding
 * machine code, outputting it to a .arm211 file.
 */
void assembleProgram(char* filename) {
	/* We need to create a string to store the output filename. */
	const int n = strlen(filename);	
	char* arm211_program = malloc(n + EXTENSION_LENGTH);
	strncpy(arm212_program, filename, n);	

	/* When assembling, we need to turn labels into addresses.
	 * This means we need to store the current address, and we need to
	 * map labels to addresses. */
	struct LabelMap label_map;
	unsigned int current_address = 0;
	unsigned int num_labels = 0;

	/* This function reads from the input file, and outputs to an output file */
	FILE* input_file = fopen(filename, "r");
	FILE* output_file = fopen(arm211_program, "w"); 
	free(arm211_program);

	char next_letter;
	int fail = 0;
	int line_num = 0;

	/* Read input_file one line at a time */	
	while ((next_letter) = (char)fgetc(input_file) != EOF) {
		char next_instruction[MAX_INSTRUC_LENGTH + 1];
		char binary_instruction[BINARY_LENGTH];
		int letter_num = 0;
		line_num++;

		/* Fetch the next instruction one letter at a time */
		while ((next_letter) = (char)fgetc(input_file) != '\0' 
					&& next_letter != EOF 
					&& letter_num < MAX_INSTRUC_LENGTH) {
			next_instrucion[letter_num++] = next_letter;
		}

		/* Throw an error if one of the lines was too long */
		if (letter_num == MAX_INSTRUC_LENGTH) {
			fprintf(stderr, "ERROR: Instruction at line %d is too long!\n", line_num);
			break;
		}
	
		/* Assemble the next instruction */	
		next_instruction[letter_num] = '\0';
		assembleInstruction(binary_instruction, next_instruction, &fail, label_map, &current_address, &num_labels);
		
		/* Throw an error if parsing failed */
		if (fail) {
			fprintf(stderr, "ERROR: Instruction at line %d cannot be parsed!\n", line_num);
			break;
		}
			
		/* Write the instruction to the output file) */
		fprintf(output_file, binary_instruction);
	}

	/* Close the file streams. */
	fclose(input_file);
	fclose(output_file);
}
