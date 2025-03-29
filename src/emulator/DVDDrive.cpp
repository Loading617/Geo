#include "DVDDrive.hpp"
#include "Emulator.hpp"
#include <iostream>
#include <fstream>

DVDDrive::DVDDrive() : disc_loaded(false) {}

bool DVDDrive::load_disc(const std::string& filepath) {
    std::ifstream file(filepath, std::ios::binary);
    
    if (!file) {
        std::cerr << "Failed to open disc image: " << filepath << "\n";
        return false;
    }

    disc_data = std::vector<uint8_t>((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    disc_loaded = true;

    std::cout << "Loaded GameCube disc: " << filepath << " (" << disc_data.size() / (1024 * 1024) << " MB)\n";
    return true;
}

std::vector<uint8_t> DVDDrive::read_sector(uint32_t sector, uint32_t count) {
    if (!disc_loaded) {
        std::cerr << "No disc loaded!\n";
        return {};
    }

    uint32_t offset = sector * 2048;
    uint32_t size = count * 2048;

    if (offset + size > disc_data.size()) {
        std::cerr << "Read out of bounds: sector " << sector << "\n";
        return {};
    }

    return std::vector<uint8_t>(disc_data.begin() + offset, disc_data.begin() + offset + size);
}

void DVDDrive::eject() {
    if (disc_loaded) {
        std::cout << "Disc ejected.\n";
        disc_data.clear();
        disc_loaded = false;
    }
}

Emulator::Emulator() : cpu(memory) {}

bool Emulator::load_game(const std::string& filepath) {
    return dvd_drive.load_disc(filepath);
}

void Emulator::run() {
    if (!dvd.read_sector(0.1).empty()) {
        std::cout << "Executing game from DVD ...\n";
        cpu.execute_instruction();
    } else {
        std::cerr << "No game loaded!\n";
    }
}