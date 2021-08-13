#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct Mem{
    uint8_t memory[1024 * 64];

}mem;

struct CPU {
    uint16_t pc, sp;
    uint8_t a, b, c, d, e, h, l; //registers //A for accumulator

    // flags
    uint8_t S : 1; //set if result is negative, Sign bit
    uint8_t Z : 1; //set if the result is 0, Zero bit
    uint8_t P : 1; //set if the number of 1 bits in the result is even, Parity Bit
    uint8_t C : 1;  //carry flag
    uint8_t AC : 1; //aux carry


    //uint16_t pc, sp;


} cpu;
