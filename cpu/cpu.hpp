#pragma once

#include "../memory/memory.hpp"

class CPU {
public:
    void ConnectMemory(Memory* memory);
    void Step();
private:
    Memory* memory;
    uint32_t pc = 0x80000000;
};
