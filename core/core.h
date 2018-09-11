#ifndef __JJC__CORE__H__
#define __JJC__CORE__H__

#include <stdint.h>

typedef int32_t   reg_t;
typedef uint8_t   byte_t;
typedef bool      flag_t;

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
    reg_t r_StackPointer;
    reg_t r_XIndex;
    reg_t r_YIndex;

public:
    reg_t  getReg(RegId id);
    flag_t getFlag(FlagId id);

};

#endif // __JJC__CORE__H__