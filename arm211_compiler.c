/*
 * Compiles one or more files written in CPEN 211 assembly (simplified ARMv7)
 * into machine code for the CPEN 211 ISA.
 *
 * Author: david-mcpherson
 * Created: 2022-06-21
 */

#include "arm211_compiler.h"

int main(int argc, char** argv) {
	for(int program_num = 0; program_num < argc; program_num++) {
		assembleProgram(argv[program_num];
	}
	return 0;
}
