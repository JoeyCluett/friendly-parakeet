#ifndef __JJC__CONSTANTS__H__
#define __JJC__CONSTANTS__H__

/*
    Addressing modes of 6502

    Immediate
        operand is contained in the second byte of the address
         - dest = i2

    Absolute
        address is given in next two bytes: little endian
         - dest = mem[i2|(i3<<8)]

    Zero Page
        second byte is index into zero page (high order bits are 0x00)
         - dest = mem[i2]

    Accumulator
        one byte instruction operating on accumulator

    Zero Page, X
    Zero Page, Y
        second byte is added to index and low order result is 
        used to index into zero page
         - dest = mem[(i2 + Index) & 0xFF]

    Absolute, X
    Absolute, Y
        2nd and 3rd byte are used as 16-bit address + index reg
         - dest = mem[(i2 | i3<<8) + Index]

    (IND,X) - Indexed Indirect
        dest = mem[mem[X+i2 & 0xFF] | (i3<<8)]

    (IND,Y) - Indirect Indexed
        dest = mem[(mem[i2] + mem[i3+1]<<8) + Y]

*/

typedef int32_t   reg_t;
typedef uint8_t   byte_t;
typedef bool      flag_t;

// list of opcodes for 6502

namespace _6502 {

    const byte_t BRK       = 0x00;
    const byte_t ORA_IND_X = 0x01;

    // NA block
    const byte_t NA_0x02   = 0x02;
    const byte_t NA_0x03   = 0x03;
    const byte_t NA_0x04   = 0x04;

    const byte_t ORA_Z_PG  = 0x05;
    const byte_t ASL_Z_PG  = 0x06;

    // NA block
    const byte_t NA_0x07   = 0x07;

    const byte_t PHP       = 0x08;
    const byte_t ORA_IMM   = 0x09;
    const byte_t ASL_A     = 0x0A;
    
    // NA block
    const byte_t NA_0x0B   = 0x0B;
    const byte_t NA_0x0C   = 0x0C;

    const byte_t ORA_ABS   = 0x0D;
    const byte_t ASL_ABS   = 0x0E;

    const byte_t NA_0x0F   = 0x0F;

} // end of _6502 namespace

#endif // __JJC__CONSTANTS__H__