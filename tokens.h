#include <string.h>

#define NO_SHIFT	"00"
#define LSL			"01"
#define LSR			"10"
#define ASR			"11"


/**
 * @brief Determines whether the move function is 
 * a MOV_REG instruction
 * 
 * @param binary 
 * @param assembly 
 * @return true if the instruction is MOV_REG
 * @return false if the instruction is MOV_IMM
 */
bool movReg(char* binary, char* assembly) {
    char* curr_letter = assembly;
    while (*curr_letter != ',')
        curr_letter++;

    return *(++curr_letter) == 'R';
}


/**
 * @brief Set a reg field of a binary instruction.
 * 
 * @param binary points to the MSB of the binary reg 
 * @param reg is a single char containing a digit 
 */
void setReg(char* binary, char reg) {
    switch (reg) {
        case '0': strncpy(binary, "000", 3); break;
        case '1': strncpy(binary, "001", 3); break;
        case '2': strncpy(binary, "010", 3); break;
        case '3': strncpy(binary, "011", 3); break;
        case '4': strncpy(binary, "100", 3); break;
        case '5': strncpy(binary, "101", 3); break;
        case '6': strncpy(binary, "110", 3); break;
        case '7': strncpy(binary, "111", 3); break;
        default: fprintf(stderr, "ERROR: The CPEN 211 ISA only supports registers R0-R7!\n");
    };
}


/**
 * @brief Set the ALU OP.
 * ADD: 00
 * CMP: 01
 * AND: 10
 * MVN: 11
 * 
 * @param binary 
 * @param assembly 
 */
void setOP(char* binary, char* assembly) {
    binary[3] = (assembly[1] == 'N' || assembly[2] == 'N') ? '1' : '0';
    binary[4] = (assembly[2] == 'D') ? '0' : '1';
}


/**
 * @brief Set the 8-bit immediate field of an instruction.
 * 
 * @param binary 
 * @param assembly 
 */
void setImmediate(char* binary, char* assembly) {
    /* Sample instruction: 
     *      MOV R0,#211     
     * There are 8 chars before the immediate starts. */ 
    int imm = atoi(assembly+8);

    /* We iterate through each of the 8 binary digits from binary[7] to binary[0].
     * We determine whether this bit is 1 or 0 by ANDing the bit with the immediate. 
     *
     * Example: i = 0  -->  2 << (7 - 1) == 1000_0000 
     * Example: i = 7  -->  2 << (7 - 7) == 0000_0001 */
    for (int i = 0; i < 8; i++) {
        binary[i + 8] = (imm & 2 << (7 - i)) ? '1' : '0';
    }
}


/**
 * @brief Sets the shift bits. If the shift argument is invalid
 * then NO_SHIFT is set.
 * 
 * @param binary start of the binary instruction
 * @param shift_arg points to the start of the shift argument
 * 
 * TODO: implement error checking
 */
void setShift(char* binary, char* shift_arg) {
    char shift_encoding[2];
    
    if (shift_arg[0] == 'L' && shift_arg[2] == 'L') {
        strncmp(shift_encoding, LSL, 2);
    } else if (shift_arg[0] = 'L' && shift_arg == 'R') {
        strncmp(shift_encoding, LSR, 2);
    } else if (shift_arg[0] = 'A' && shift_arg == 'R') {
        strncmp(shift_encoding, ASR, 2);
    } else { 
        strncmp(shift_encoding, NO_SHIFT, 2)
    }
}


/**
 * @brief Sets the Rd, shift and Rm fields of an instruction.
 * 
 * @param binary 
 * @param assembly 
 */
void setRdShiftRm(char* binary, char* assembly) {
    // TODO: implement this method.
    // sample instruction: MOV R2,R1,R3,LSL#1

    if (assembly[0] == 'C') {
        setReg(binary + RN_OFFSET, assembly[ARG1];  // set Rn
        setReg(binary + RM_OFFSET, assembly[ARG2];  // set Rm
        
    } else {
        setReg(binary + RD_OFFSET, assembly[ARG1];  // set Rd
        setReg(binary + RN_OFFSET, assembly[ARG2];  // set Rn
        setReg(binary + RM_OFFSET, assembly[ARG3];  // set Rm
        setShift(binary, assembly + ARG4); 
    }
}


/**
 * @brief Set the binary[7:0] to Rd + 5-bit immediate
 * 
 * @param binary 
 * @param assembly 
 */
void setMemAddress(char* binary, char* assembly) {
    // TODO: implement this method.
}

