#ifndef JIT_HPP
#define JIT_HPP

#include <unordered_map>
#include <vector>
#include <cstdint>

class JIT {
public:
    JIT();
    ~JIT();

    using JITFunction = void(*)();
    
    JITFunction compile_block(uint32_t pc);
    void execute_block(uint32_t pc);

private:
    std::unordered_map<uint32_t, JITFunction> block_cache;
    uint8_t* allocate_executable_memory(size_t size);
};

#endif
