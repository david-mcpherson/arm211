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
|BLE <label>                         |   001     |   xx  |   100     |   #<8-bit address>            |   ++PC += (N^V &#124; Z) ? #<8-bit immediate> : 0;

## Project status
This project has been abandoned. Its purpose was to design a faster version of the functioning CPU I made in school.
See the functioning implementation here: https://github.com/david-mcpherson/David-Programming-Projects/tree/main/verilog%20computer




## Development status
main is done.
assembleProgram is done.
assembleInstruction is done.
string-manipulation is done.

TODO: finish tokens.h


## Testing status
Nothing has been tested yet.
Files should be tested in the following order:
	1. string-manip.h
	2. tokens.h
	3. label-structs.h
	4. assembleInstruction
    5. assembleProgram
    6. main  


