#ifndef EMULATOR_HPP
#define EMULATOR_HPP

#include "CPU.hpp"
#include "Memory.hpp"

class Emulator {
public:
    Emulator();
    void load_game(const std::vector<uint8_t>& rom_data);
    void run();

private:
    Memory memory;
    CPU cpu;
};

#endif
