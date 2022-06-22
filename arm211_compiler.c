/*
Compiler for CPEN 211 ISA (a subset of ARMv7)

This program takes assembly files as arguments and creates machine code files
in the format of the CPEN 211 ISA.

author: 		david-mcpherson
created: 		20-June-2022
last updated:	20-June-2022
*/

/* PSEUDOCODE:
main:
For each file in argv:
	For each line in file:
		compileLine()

compileLine(line):
	int encoding;
	operation = line[0:2]
	switch(operation)
		get the first five bits of the instruction
		get the last 11 bits from a helper function



*/

#include "arm211_compiler.h"

int main(int argc, char** argv) {
	for (int filenum = 1; filenum < argc; filenum++) {
		assembleProgram(argv[i]);
	}
	return 0;
}

