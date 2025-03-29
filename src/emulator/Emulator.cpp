#include "Emulator.hpp"
#include <iostream>

Emulator::Emulator() : cpu(memory) {}

void Emulator::load_game(const std::vector<uint8_t>& rom_data) {
    memory.load_bios(rom_data);
}

void Emulator::run() {
    cpu.execute_instruction();
}
