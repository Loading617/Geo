#include "cpu.hpp"
#include <iostream>

void CPU::ConnectMemory(Memory* mem) {
    memory = mem;
}

void CPU::Step() {
    uint32_t instruction = memory->Read32(pc);
    std::cout << "Fetched instruction: 0x" << std::hex << instruction << " at PC: 0x" << pc << std::endl;
    pc += 4;
}

