#ifndef INSTR_DEF_HPP
#define INSTR_DEF_HPP

#include <iostream>
#include "file_to_memory.hpp"

struct Instr_def{
  char type;
  uint32_t opcode;
  uint32_t rs;
  uint32_t rt;
  uint32_t rd;
  uint32_t shamt;
  uint32_t funct;
  uint32_t immediate;
  uint32_t address;
};

Instr_def define_instruction(const System &s);

#endif
