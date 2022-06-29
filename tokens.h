#include <string.h>


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
 * @brief Set the Rn field of a binary instruction.
 * 
 * @param binary 
 * @param assembly 
 */
void setRn(char* binary, char* assembly) {
    switch (assembly[5]) {
        case '0': strncpy(binary + 5, "000", 3); break;
        case '1': strncpy(binary + 5, "001", 3); break;
        case '2': strncpy(binary + 5, "010", 3); break;
        case '3': strncpy(binary + 5, "011", 3); break;
        case '4': strncpy(binary + 5, "100", 3); break;
        case '5': strncpy(binary + 5, "101", 3); break;
        case '6': strncpy(binary + 5, "110", 3); break;
        case '7': strncpy(binary + 5, "111", 3); break;
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
 * @brief Sets the Rd, shift and Rm fields of an instruction.
 * 
 * @param binary 
 * @param assembly 
 */
void setRdShiftRm(char* binary, char* assembly) {
    // TODO: implement this method.
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
