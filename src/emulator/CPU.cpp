#include "CPU.hpp"
#include <iostream>

CPU::CPU(Memory& mem) : memory(mem) {}
void CPU::reset() {
    pc = 0x80000000;
    memory.reset();
    reset();
}

void CPU::reset() {
    pc = 0x80000000;
    msr = 0;
    for (auto &reg : registers) reg = 0;
}

void CPU::load_program(const std::vector<uint32_t>& program) {
    std::cout << "Loaded program with " << program.size() << " instructions.\n";
}

void CPU::execute_instruction() {
    uint32_t instruction = fetch();
    decode_execute(instruction);
}

uint32_t CPU::fetch() {
    return 0x60000000;
}

void CPU::decode_execute(uint32_t instruction) {
    switch (instruction) {
        case 0x60000000:
            std::cout << "Executed NOP\n";
            break;
        default:
            std::cout << "Unknown instruction: " << std::hex << instruction << "\n";
            break;
    }
}
