# CPEN 211 ISA

| Instruction                        |   OPCODE  |   OP  |   [10:8]  |   [7:0]                       |   Operation description
|------------------------------------|-----------|-------|-----------|-------------------------------|--------------------------------
|MOV Rn, #<8-bit immediate>          |   110     |   10  |   Rn      |   #<8-bit immediate>          |   Rn = #<8-bit immediate>
|MOV Rd, Rm {shift operation}        |   110     |   00  |   xxx     |   {Rd, shift, Rm}             |   Rd = Rm-shifted
|ADD Rd, Rn, Rm {shift operation}    |   101     |   00  |   Rn      |   {Rd, shift, Rm}             |   Rd = Rn + Rm-shifted
|CMP Rn, Rm {shift operation}        |   101     |   01  |   Rn      |   {xxx, shift, Rm}            |   Update status flags
|AND Rd, Rn, Rm {shift operation}    |   101     |   10  |   Rn      |   {Rd, shift, Rm}             |   Rd = Rn & Rm-shifted
|MVN Rd, Rm {shift operation}        |   101     |   11  |   xxx     |   {Rd, shift, Rm}             |   Rd = ~ Rm-shifted
|LDR Rd, [Rn, #<5 bit immediate>]    |   011     |   00  |   Rn      |   {Rd, #<5-bit immediate>}    |   Rd = mem[Rn + #<5-bit immediate>]
|STR Rd, [Rn, #<5 bit immediate>]    |   100     |   00  |   Rn      |   {Rd, #<5-bit immediate>}    |   mem[Rn + #<5-bit immediate>] = Rd
|HALT                                |   111     |   xx  |   xxx     |   xxxx-xxxx                   |   go to halt state
|B <label>                           |   001     |   xx  |   000     |   #<8-bit address>            |   ++PC += #<8-bit immediate>
|BEQ <label>                         |   001     |   xx  |   001     |   #<8-bit address>            |   ++PC += (Z)       ? #<8-bit immediate> : 0;
|BNE <label>                         |   001     |   xx  |   010     |   #<8-bit address>            |   ++PC += (~Z)      ? #<8-bit immediate> : 0;
|BLT <label>                         |   001     |   xx  |   011     |   #<8-bit address>            |   ++PC += (N^V)     ? #<8-bit immediate> : 0;
|BLE <label>                         |   001     |   xx  |   100     |   #<8-bit address>            |   ++PC += (N^V | Z) ? #<8-bit immediate> : 0;


## Development status
main is implemented.
assembleProgram needs to current address and label-map and pass them to assembleInstruction.
assembleInstruction is in-progress.
	1. Branches need to set the label address.
	2. MOV needs to check for MOV-IMM or MOV-REG
		2.1 Need to convert from "Rn" to binary
		2.2 Need to convert from #<decimal number> to 8-bit immediate
	3. ALU instructions need to be fully implemented.
	4. Memory instructions are in-progress. 
	5. HALT is implemented.
	6. Creating new labels needs to be implemented.


## Testing status
Nothing has been tested yet.
Function should be tested in the following order:
	1. toUpper
	2. setExtension
	3. assembleInstruction
	4. assembleProgram
	5. main  

