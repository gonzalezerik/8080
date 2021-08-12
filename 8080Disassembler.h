/* Read code into a buffer 
    Get a pointer to the beggning of the buffer 
    Use the byte at the pointer to determine the opcode
    Print out the name of the opcode using the bytes after the opcode as data, if applicable
    Advance the pointer the number of bytes used by that instruction (1, 2, or 3 bytes)
    If not at the end of the buffer, go to step 3
*/
#include <cpu.h>

int Disassemble8080(unsigned char *codebuffer, int pc){
    unsigned char *code = &codebuffer[pc];

    int opbytes = 1;
    printf("%04x ", pc);
    switch(*code){

    }
}