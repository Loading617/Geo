#include <Core/Core.h>
#include "cpu/cpu.hpp"
#include "memory/memory.hpp"

using namespace Upp;

CONSOLE_APP_MAIN {
    StdLogSetup(LOG_COUT);
    LOG("Starting Geo Emulator");

    CPU cpu;
    Memory mem;

    cpu.ConnectMemory(&mem);
    
    for (int i = 0; i < 10; ++i) {
        cpu.Step();
    }
}

