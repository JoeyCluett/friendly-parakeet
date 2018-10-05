/*
    This file exists solely to define execution 
    of 6502 opcodes. it is up to the runtime to 
    set flags on supersets of this cpu
*/

#include "core.h"
#include "constants.h"
#include <string>
#include <stdexcept>

inline void core_65C816::execute6502_instruction(void) {
    byte_t opcode = memory[r_ProgramCounter];

    switch(opcode) {
        case _6502::BRK: // 0x00
            r_ProcessorStatus |= (1 << 4); // b flag is 4th bit
            pushByte((r_ProgramCounter >> 8) & 0xFF);
            pushByte((r_ProgramCounter >> 0) & 0xFF);
            pushByte(r_ProcessorStatus & 0xFF); // more flags in 65C816 mode

            // load the interrupt vector
            {
                u_int16_t tmp = *(u_int16_t*)&memory[0xFFFE];
                r_ProgramCounter = tmp;
            }
            break;

        case _6502::ORA_IND_X: // 0x01
            {
                int index = r_XIndex + memory[r_ProgramCounter + 1];
                u_int16_t addr = *(u_int16_t*)&memory[index & 0xFF];

                r_Accumulator |= memory[addr];
                r_Accumulator &= 0xFF;
            }
            r_ProgramCounter += 2;
            break;

        case _6502::NA_0x02: // 0x02
        case _6502::NA_0x03: // 0x03
        case _6502::NA_0x04: // 0x04
            throw std::runtime_error("UNKNOWN OPCODE " + std::to_string((int)opcode));
            break;

        case _6502::ORA_Z_PG: // 0x05
            r_Accumulator |= memory[memory[r_ProgramCounter + 1]];
            r_Accumulator &= 0xFF;
            r_ProgramCounter += 2;
            break;

        case _6502::ASL_Z_PG: // 0x06
            
            break;

        case _6502::NA_0x07: // 0x07
            throw std::runtime_error("UNKNOWN OPCODE " + std::to_string((int)opcode));
            break;

        case _6502::PHP: // 0x08
            break;

        case _6502::ORA_IMM: // 0x09
            break;

        case _6502::ASL_A: // 0x0A
            break;

        case _6502::NA_0x0B: // 0x0B
        case _6502::NA_0x0C: // 0x0C
            throw std::runtime_error("UNKNOWN OPCODE " + std::to_string((int)opcode));
            break;

        case _6502::ORA_ABS: // 0x0D
            break;

        case _6502::ASL_ABS: // 0x0E
            break;

        case _6502::NA_0x0F: // 0x0F
            throw std::runtime_error("UNKNOWN OPCODE " + std::to_string((int)opcode));
            break;

        default:
            throw std::runtime_error("UNKNOWN OPCODE " + std::to_string((int)opcode));
            break;
    }

}
