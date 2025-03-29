#include "Memory.hpp"
#include <iostream>
#include <cstring>

Memory::Memory() : ram(0x01800000, 0), bios(0x00100000, 0) {
    reset();
}

Memory::~Memory() {}

void Memory::reset() {
    std::fill(ram.begin(), ram.end(), 0);
    std::cout << "Memory reset.\n";
}

uint8_t Memory::read8(uint32_t address) {
    if (address < 0x01800000) {
        return ram[address];
    } else if (address >= 0xFFF00000) {
        return bios[address - 0xFFF00000];
    } else {
        std::cerr << "Unhandled read8 from address: " << std::hex << address << "\n";
        return 0;
    }
}

uint16_t Memory::read16(uint32_t address) {
    return (read8(address) << 8) | read8(address + 1);
}

uint32_t Memory::read32(uint32_t address) {
    return (read16(address) << 16) | read16(address + 2);
}

void Memory::write8(uint32_t address, uint8_t value) {
    if (address < 0x01800000) {
        ram[address] = value;
    } else {
        std::cerr << "Unhandled write8 to address: " << std::hex << address << "\n";
    }
}

void Memory::write16(uint32_t address, uint16_t value) {
    write8(address, value >> 8);
    write8(address + 1, value & 0xFF);
}

void Memory::write32(uint32_t address, uint32_t value) {
    write16(address, value >> 16);
    write16(address + 2, value & 0xFFFF);
}

void Memory::load_bios(const std::vector<uint8_t>& bios_data) {
    if (bios_data.size() > bios.size()) {
        std::cerr << "BIOS file too large!\n";
        return;
    }
    std::copy(bios_data.begin(), bios_data.end(), bios.begin());
    std::cout << "BIOS loaded.\n";
}
