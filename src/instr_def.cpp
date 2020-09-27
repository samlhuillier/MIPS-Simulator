#include "instr_def.hpp"

Instr_def define_instruction(const System &s){
  Instr_def instruction;
  uint32_t bin_32 = 0;
  uint32_t bin_8;
  int j = s.pc + 4;
  for(int i = s.pc; i < j; i++){
    bin_32 = bin_32 << 8;
    bin_8 = s.ram[i];
    bin_32 = bin_32 + bin_8;
  }
  instruction.opcode = (bin_32 >> 26) & 0x0000003F;
  if(instruction.opcode == 0){ //r-type instruction
    instruction.type = 'R';
    instruction.rs = (bin_32 >> 21) & 0x0000001F;
    instruction.rt = (bin_32 >> 16) & 0x0000001F;
    instruction.rd = (bin_32 >> 11) & 0x0000001F;
    instruction.shamt = (bin_32 >> 6) & 0x0000001F;
    instruction.funct = bin_32 & 0x0000003F;
  }
  else if(instruction.opcode == 0x02 || instruction.opcode == 0x03){ //j-type instruction
    instruction.type = 'J';
    instruction.address = bin_32 & 0x03FFFFFF;
  }
  else{ //i-type instruction
    instruction.type = 'I';
    instruction.rs = (bin_32 >> 21) & 0x1F;
    instruction.rt = (bin_32 >> 16) & 0x1F;
    instruction.immediate = bin_32 & 0x0000FFFF;
  }

  return instruction;
}
