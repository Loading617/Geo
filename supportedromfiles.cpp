#include "supported rom files"

#define ROM_SUPPORTED_EXTENSIONS ".ciso"
#define ROM_SUPPORTED_EXTENSIONS ".iso"
#define ROM_SUPPORTED_EXTENSIONS ".nkit.iso"
#define ROM_SUPPORTED_EXTENSIONS ".rvz"

void load_rom(const char *rom_file) {
    // Load the ROM file into memory
    // ...
}

int main() {
    // Check if the provided ROM file is supported
    const char *supported_files = SUPPORTED_ROM_FILES;
    const char *extension = strrchr(rom_file, '.');
    if (extension && strstr(supported_files, extension + 1)) {
        load_rom(rom_file);
        // Start the game
    } else {
        std::cerr << "Error: Unsupported ROM file format." << std::endl;
        return 1;
    }