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

#define EXTENSION_LENGTH 	8
#define INSTUCTION_LENGTH	16
#define ALL_ZERO			"0000000000000000"
#define ASCII_LETTER_PREFIX	96
#define ASCII_LETTER_ID		31
#define ALPHABET_LENGTH		26


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
		strncpy(binary+8, label_map->getAddress(assembly[2]);
	} else if (assembly[0] == 'M' && assembly[1] == 'O' && assembly[2] == 'V') {	// MOV 
		strncpy(binary, "110", 3);
		
		/* Need to check whether the instruction is MOV_IMM or MOV_REG*/
		// TODO if (toks[2][0] == 'R') MOV_REG; else MOV_IMM;

	} else if (assembly[0] == 'L' && assembly[1] == 'D' && assembly[2] == 'R'		// LDR/STR
			|| assembly[0] == 'S' && assembly[1] == 'T' && assembly[2] == 'R') {
		strncpy(binary, (assembly[0] == 'L') ? "011" : "100", 3);
		// TODO: binary[10:8] = Rn
		// TODO: binary[7:0] = Rd + #<5-bit immediate>

	} else if (~(possible_label_length = labelLength(assembly)) {					// LABEL DECLARATION
		assembly[possible_label_length] = '\0';	
	} else {	
		/* ParseError: No instruction found. */
		*error_number = 1;
	}
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
