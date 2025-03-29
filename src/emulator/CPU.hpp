#ifndef CPU_HPP
#define CPU_HPP

#include "Memory.hpp"
#include <cstdint>
#include <vector>

class CPU {
public:
    CPU();
    CPU(Memory& mem);
    void reset();
    void load_program(const std::vector<uint32_t>& program);
    void execute_instruction();

private:
    Memory& memory;
    uint32_t registers[32];
    uint32_t pc;
    uint32_t msr;

    uint32_t fetch();
    void decode_execute(uint32_t instruction);
};

#endif
