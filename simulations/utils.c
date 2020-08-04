#include <stdlib.h>

#include "VCPU.h"
#include "verilated.h"

const uint8_t FETCH_1 = 0, FETCH_2 = 1, DECODE = 2, EXECUTE = 3;

void tick(VCPU *tb) {
    tb->eval();
    tb->clk = 1;
    tb->eval();
    tb->clk = 0;
    tb->eval();
}

void reset(VCPU *tb) {
    tb->rst = 1;
    tick(tb);
    tb->rst = 0;
}

void dump_regs(VCPU *tb) {
    for(size_t i = 0; i < 16; i++) {
        printf("V%x=%d\t", i, tb->CPU__DOT__vx[i]);
    }
    printf("\n");
}

void dump_mem(VCPU *tb) {
    for(size_t i = 0; i < 32; i++) {
        printf("%x ", tb->CPU__DOT__memory[i]);
    }
    printf("\n");
}

void dump_state(VCPU *tb) {
    switch(tb->CPU__DOT__state) {
        case FETCH_1: printf("FETCH_1\n"); break;
        case FETCH_2: printf("FETCH_2\n"); break;
        case DECODE: printf("DECODE\n"); break;
        case EXECUTE: printf("EXECUTE\n"); break;
        default: printf("Unknown state! %d\n", tb->CPU__DOT__state);
    }
}

