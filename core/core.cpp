#include <stdexcept>
#include <string>

#include "core.h"

reg_t core_65C816::getReg(RegId id) {
    switch(id) {
        case RegId::A:
            return (this->r_Accumulator & 0x000000FF);
        case RegId::B:
            return ((this->r_Accumulator >> 8) & 0x000000FF);
        case RegId::C:
            return this->r_Accumulator;
        case RegId::DBR:
            return this->r_DataBank;
        case RegId::D:
            return this->r_Direct;
        case RegId::DL:
            return (this->r_Direct & 0x000000FF);
        case RegId::DH:
            return ((this->r_Direct >> 8) & 0x000000FF);
        case RegId::K:
            return this->r_ProgramBank;
        case RegId::PC:
            return this->r_ProgramCounter;
        case RegId::PCL:
            return (this->r_ProgramCounter & 0x000000FF);
        case RegId::PCH:
            return ((this->r_ProgramCounter >> 8) & 0x000000FF);
        case RegId::P:
            return this->r_ProcessorStatus;
        case RegId::S:
            return this->r_StackPointer;
        case RegId::SL:
            return (this->r_StackPointer & 0x000000FF);
        case RegId::SH:
            return ((this->r_StackPointer >> 8) & 0x000000FF);
        case RegId::X:
            return this->r_XIndex;
        case RegId::XL:
            return (this->r_XIndex & 0x000000FF);
        case RegId::XH:
            return ((this->r_XIndex >> 8) & 0x000000FF);
        case RegId::Y:
            return this->r_YIndex;
        case RegId::YL:
            return (this->r_YIndex & 0x000000FF);
        case RegId::YH:
            return ((this->r_YIndex >> 8) & 0x000000FF);
        default:
            throw std::runtime_error("UNKNOWN VALUE IN core_68C816::getReg");
    }
}

// extract a specific bit from the processor status register
flag_t core_65C816::getFlag(FlagId id) {
    switch(id) {
        case FlagId::b:
            return (1 << 4) & this->r_ProcessorStatus ? SET : RESET;
        case FlagId::c:
            return (1 << 0) & this->r_ProcessorStatus ? SET : RESET;
        case FlagId::d:
            return (1 << 3) & this->r_ProcessorStatus ? SET : RESET;
        case FlagId::e:
            return (1 << 0 /*?*/) & this->r_ProcessorStatus ? SET : RESET; // equals c-flag via XCE instruction
        case FlagId::i:
            return (1 << 2) & this->r_ProcessorStatus ? SET : RESET;
        case FlagId::m:
            return (1 << 5) & this->r_ProcessorStatus ? SET : RESET;
        case FlagId::n:
            return (1 << 7) & this->r_ProcessorStatus ? SET : RESET;
        case FlagId::v:
            return (1 << 6) & this->r_ProcessorStatus ? SET : RESET;
        case FlagId::x:
            return (1 << 4) & this->r_ProcessorStatus ? SET : RESET;
        case FlagId::z:
            return (1 << 1) & this->r_ProcessorStatus ? SET : RESET;
        default:
            throw std::runtime_error("UNKNOWN VALUE IN core_65C816::getFlag");
    }
}

