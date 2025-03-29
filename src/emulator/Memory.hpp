#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <cstdint>
#include <vector>

class Memory {
public:
    Memory();
    ~Memory();

    uint8_t read8(uint32_t address);
    uint16_t read16(uint32_t address);
    uint32_t read32(uint32_t address);
    
    void write8(uint32_t address, uint8_t value);
    void write16(uint32_t address, uint16_t value);
    void write32(uint32_t address, uint32_t value);

    void load_bios(const std::vector<uint8_t>& bios_data);
    void reset();

private:
    std::vector<uint8_t> ram;
    std::vector<uint8_t> bios;
};

#endif
