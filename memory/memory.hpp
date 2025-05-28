#pragma once
#include <cstdint>
#include <vector>

class Memory {
public:
    Memory();
    uint32_t Read32(uint32_t address);
    void Write32(uint32_t address, uint32_t value);

private:
    std::vector<uint8_t> ram;
};
