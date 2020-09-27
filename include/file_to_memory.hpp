#ifndef FILE_TO_MEMORY_HPP
#define FILE_TO_MEMORY_HPP

#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>
#include <bitset>

struct System{
    uint32_t pc;
  	uint32_t npc;
    uint32_t nnpc;
    std::vector<uint32_t> ram;
  	std::vector<uint32_t> regs;
    uint32_t hi;
    uint32_t lo;
};

void file_to_memory(const std::string &file, System &s);

#endif
