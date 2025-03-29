#include "JIT.hpp"
#include <sys/mman.h>
#include <iostream>
#include <cstring>

JIT::JIT() {}

JIT::~JIT() {
    for (auto& [pc, func] : block_cache) {
        munmap(reinterpret_cast<void*>(func), 4096);
    }
}

uint8_t* JIT::allocate_executable_memory(size_t size) {
    void* mem = mmap(nullptr, size, PROT_READ | PROT_WRITE | PROT_EXEC, 
                     MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mem == MAP_FAILED) {
        std::cerr << "Failed to allocate JIT memory!\n";
        return nullptr;
    }
    return reinterpret_cast<uint8_t*>(mem);
}

JIT::JITFunction JIT::compile_block(uint32_t pc) {
    if (block_cache.find(pc) != block_cache.end()) {
        return block_cache[pc];
    }

    uint8_t* code = allocate_executable_memory(4096);
    if (!code) return nullptr;

    size_t offset = 0;

    code[offset++] = 0xC3;

    JITFunction func = reinterpret_cast<JITFunction>(code);
    block_cache[pc] = func;

    std::cout << "Compiled block at PC: 0x" << std::hex << pc << "\n";
    return func;
}

void JIT::execute_block(uint32_t pc) {
    if (auto iter = block_cache.find(pc); iter != block_cache.end()) {
        iter->second();
    } else {
        JITFunction func = compile_block(pc);
        if (func) func();
    }
}
