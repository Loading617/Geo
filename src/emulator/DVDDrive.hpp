#ifndef DVDDRIVE_HPP
#define DVDDRIVE_HPP

#include "CPU.hpp"
#include "Memory.hpp"
#include "DVDDrive.hpp"

#include <vector>
#include <cstdint>
#include <string>

class DVDDrive {
public:
    DVDDrive();
    bool load_disc(const std::string& filepath);
    std::vector<uint8_t> read_sector(uint32_t sector, uint32_t count);
    void eject();

private:
    std::vector<uint8_t> disc_data;
    bool disc_loaded;
    Memory memory;
    CPU cpu;
    DVDDrive dvd;
};

#endif
