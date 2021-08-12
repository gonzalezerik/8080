#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct CPU {
    uint16_t pc, sp;
    uint8_t a, b, c, d, e, h, l; //registers

    // flags
    bool sf : 1, zf : 1, hf : 1, pf : 1, cf : 1, iff : 1;

} cpu;