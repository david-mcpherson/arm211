/**
 * @brief Determines whether the move function is 
 * a MOV_REG instruction
 * 
 * @param binary 
 * @param assembly 
 * @return true if the assembly is for MOV_REG
 * @return false if the assembly is for MOV_IMM
 */
bool movReg(char* binary, char* assembly) {

}


/**
 * @brief Set the Rn field of a binary instruction.
 * 
 * @param binary 
 * @param assembly 
 */
void setRn(char* binary, char* assembly) {

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

}


/**
 * @brief Sets the Rd, shift and Rm fields of an instruction.
 * 
 * @param binary 
 * @param assembly 
 */
void setRdShiftRm(char* binary, char* assembly) {

}


/**
 * @brief Set the binary[7:0] to Rd + 5-bit immediate
 * 
 * @param binary 
 * @param assembly 
 */
void setMemAddress(char* binary, char* assembly) {

}