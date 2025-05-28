#include "memory.hpp"
#include <stdexcept>
#include <iostream>

Memory::Memory() {
    ram.resize(0x2000000);
}

uint32_t Memory::Read32(uint32_t address) {
    if (address + 3 >= ram.size())
        throw std::out_of_range("Read out of bounds");
    return (ram[address] << 24) | (ram[address + 1] << 16) | (ram[address + 2] << 8) | ram[address + 3];
}

void Memory::Write32(uint32_t address, uint32_t value) {
    if (address + 3 >= ram.size())
        throw std::out_of_range("Write out of bounds");
    ram[address] = (value >> 24) & 0xFF;
    ram[address + 1] = (value >> 16) & 0xFF;
    ram[address + 2] = (value >> 8) & 0xFF;
    ram[address + 3] = value & 0xFF;
}
