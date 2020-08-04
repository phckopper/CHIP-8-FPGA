#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "VCPU.h"
#include "verilated.h"

extern void tick(VCPU *tb);
extern void reset(VCPU *tb);
extern void dump_regs(VCPU *tb);
extern void dump_mem(VCPU *tb);
extern void dump_state(VCPU *tb);

#define N_CYCLES 10

void test_jmp(VCPU *tb) {
    for(size_t i = 0; i < N_CYCLES; i++) {
        uint16_t addr = rand() % (1 << 12); 
        // loads a jump into memory
        tb->CPU__DOT__memory[0] = (1 << 4) | (addr >> 8);
        tb->CPU__DOT__memory[1] = addr & 0xFF;
        reset(tb);
        tick(tb); tick(tb); tick(tb); // cycles through state machine
        if(tb->CPU__DOT__pc != addr) {
            printf("FAIL! Jumping to %x set PC to %x\n", addr, tb->CPU__DOT__pc);
            return;
        }
    }
    printf("Passed JMP!\n");
}

void test_se(VCPU *tb) {
    // test against
    for(size_t i = 0; i < N_CYCLES/2; i++) {
        uint8_t vx = rand() % (1 << 4); // selects random Vx register
        uint8_t kk = rand() % (1 << 8); // tests a random value
        // loads a SE into memory
        tb->CPU__DOT__memory[0] = (3 << 4) | vx;
        tb->CPU__DOT__memory[1] = kk;
        tb->CPU__DOT__vx[vx] = kk;
        reset(tb);
        tick(tb); tick(tb); tick(tb); // cycles through state machine
        if(tb->CPU__DOT__pc != 4) {
            printf("FAIL! SE V%X to %x set PC to %x\n", vx, kk, tb->CPU__DOT__pc);
            return;
        }
    }
    // test for
    for(size_t i = 0; i < N_CYCLES/2; i++) {
        uint8_t vx = rand() % (1 << 4); // selects random Vx register
        uint8_t kk = rand() % (1 << 8); // tests a random value
        // loads a SE into memory
        tb->CPU__DOT__memory[0] = (3 << 4) | vx;
        tb->CPU__DOT__memory[1] = kk;
        tb->CPU__DOT__vx[vx] = !kk;
        reset(tb);
        tick(tb); tick(tb); tick(tb); // cycles through state machine
        if(tb->CPU__DOT__pc != 2) {
            printf("FAIL! SE V%X to %x set PC to %x\n", vx, kk, tb->CPU__DOT__pc);
            return;
        }
    }
    printf("Passed SE!\n");
}

void test_sne(VCPU *tb) {
    // test against
    for(size_t i = 0; i < N_CYCLES/2; i++) {
        uint8_t vx = rand() % (1 << 4); // selects random Vx register
        uint8_t kk = rand() % (1 << 8); // tests a random value
        // loads a SE into memory
        tb->CPU__DOT__memory[0] = (4 << 4) | vx;
        tb->CPU__DOT__memory[1] = kk;
        tb->CPU__DOT__vx[vx] = kk;
        reset(tb);
        tick(tb); tick(tb); tick(tb); // cycles through state machine
        if(tb->CPU__DOT__pc != 2) {
            printf("FAIL! SNE V%X to %x set PC to %x\n", vx, kk, tb->CPU__DOT__pc);
            return;
        }
    }
    // test for
    for(size_t i = 0; i < N_CYCLES/2; i++) {
        uint8_t vx = rand() % (1 << 4); // selects random Vx register
        uint8_t kk = rand() % (1 << 8); // tests a random value
        // loads a SE into memory
        tb->CPU__DOT__memory[0] = (4 << 4) | vx;
        tb->CPU__DOT__memory[1] = kk;
        tb->CPU__DOT__vx[vx] = !kk;
        reset(tb);
        tick(tb); tick(tb); tick(tb); // cycles through state machine
        if(tb->CPU__DOT__pc != 4) {
            printf("FAIL! SNE V%X to %x set PC to %x\n", vx, kk, tb->CPU__DOT__pc);
            return;
        }
    }
    printf("Passed SNE!\n");
}

void test_sevxvy(VCPU *tb) {
    // test against
    for(size_t i = 0; i < N_CYCLES/2; i++) {
        uint8_t vx = rand() % (1 << 4); // selects random Vx register
        uint8_t vy = rand() % (1 << 4); // selects random Vy register
        uint8_t kk = rand() % (1 << 8); // tests a random value
        while(vx == vy) vy = rand() % (1 << 4);
        // loads a SE into memory
        tb->CPU__DOT__memory[0] = (5 << 4) | vx;
        tb->CPU__DOT__memory[1] = vy << 4;
        tb->CPU__DOT__vx[vx] = kk;
        tb->CPU__DOT__vx[vy] = kk;
        reset(tb);
        tick(tb); tick(tb); tick(tb); // cycles through state machine
        if(tb->CPU__DOT__pc != 4) {
            printf("FAIL! SE V%X to %x and V%X to %x set PC to %x\n", vx, kk, vy, !kk, tb->CPU__DOT__pc);
            return;
        }
    }
    // test for
    for(size_t i = 0; i < N_CYCLES/2; i++) {
        uint8_t vx = rand() % (1 << 4); // selects random Vx register
        uint8_t vy = rand() % (1 << 4); // selects random Vy register
        uint8_t kk = rand() % (1 << 8); // tests a random value
        while(vx == vy) vy = rand() % (1 << 4);
        // loads a SE into memory
        tb->CPU__DOT__memory[0] = (5 << 4) | vx;
        tb->CPU__DOT__memory[1] = vy << 4;
        tb->CPU__DOT__vx[vx] = !kk;
        tb->CPU__DOT__vx[vy] = kk;
        reset(tb);
        tick(tb); tick(tb); tick(tb); // cycles through state machine
        if(tb->CPU__DOT__pc != 2) {
            printf("FAIL! SE V%X to %x and V%X to %x set PC to %x\n", vx, kk, vy, !kk, tb->CPU__DOT__pc);
            return;
        }
    }
    printf("Passed SE (VxVy)!\n");
}

void test_vxkk(VCPU *tb) {
    for(size_t i = 0; i < N_CYCLES; i++) {
        uint8_t vx = rand() % (1 << 4); // selects random Vx register
        uint8_t kk = rand() % (1 << 8); // tests a random value
        // loads a vxkk into memory
        tb->CPU__DOT__memory[0] = (6 << 4) | vx;
        tb->CPU__DOT__memory[1] = kk;
        tb->CPU__DOT__vx[vx] = !kk;
        reset(tb);
        tick(tb); tick(tb); tick(tb); // cycles through state machine
        if(tb->CPU__DOT__vx[vx] != kk) {
            printf("FAIL! Setting V%X to %x set to %x instead\n", vx, kk, tb->CPU__DOT__vx[vx]);
            return;
        }
    }
    printf("Passed VXKK!\n");
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    VCPU *tb = new VCPU;
    reset(tb);

    test_jmp(tb); // 1nnn
    test_se(tb);  // 3xkk
    test_sne(tb); // 4xkk
    test_sevxvy(tb); // 5xy0
    test_vxkk(tb); // 6xkk

    /*  
    reset(tb);
    dump_mem(tb);
    for(size_t i = 0; i < N_CYCLES; i++) {
        printf("Cycle=%u PC=%d IR=%04x\n", i, tb->CPU__DOT__pc, tb->CPU__DOT__ir);
        dump_state(tb);
        dump_regs(tb);
        printf("Mem_out %02x\n", tb->CPU__DOT__mem_out);
        printf("--------------------\n");
        tick(tb);
    }
    */

}
