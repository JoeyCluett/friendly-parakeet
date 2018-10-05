#ifndef __JJC__CORE__H__
#define __JJC__CORE__H__

#include <vector>
#include <stdint.h>
#include "constants.h" // typedefs and opcodes

#define SET true
#define RESET false

enum class RegId : int {
    A = 0, B, C, DBR, D, DL, DH, K, 
    PC, PCL, PCH, P, S, SL, SH, X, 
    XL, XH, Y, YL, YH
};

enum class FlagId : int {
    b = 0, c, d, 
    e, i, m, n, v, 
    x, z    
};

class core_65C816 {
private:
    reg_t r_Accumulator;
    reg_t r_DataBank;
    reg_t r_Direct;
    reg_t r_ProgramBank;
    reg_t r_ProgramCounter;
    reg_t r_ProcessorStatus;
    reg_t r_StackPointer = 0x100; // at least in 6502 mode, stack always starts here
    reg_t r_XIndex;
    reg_t r_YIndex;

    std::vector<byte_t> memory;
    void pushByte(byte_t b);

public:
    reg_t getReg(RegId id);
    bool  getFlag(FlagId id);
    void  execute6502_instruction(void);
};

#endif // __JJC__CORE__H__
// i never finish anythi