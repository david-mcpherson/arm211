/*
 * Compiles one or more files written in CPEN 211 ISA (simplified ARMv7)
 * 
 * This program takes assembly files as arguments and creates machine code files
 * in the format of the CPEN 211 ISA.
 * 
 * author: 		david-mcpherson
 * created: 	20-June-2022
 * last updated 26-June-2022
 */


#include "arm211_compiler.h"


int main(int argc, char** argv) {
	for(int program_num = 0; program_num < argc; program_num++) {
		assembleProgram(argv[program_num];
	}
	return 0;
}
