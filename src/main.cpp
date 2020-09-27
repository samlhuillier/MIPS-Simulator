#include <iostream>
#include <string>
#include "instr_set.hpp"

int main(int argc, char **argv){
  //check if a binary file has been inputted
  try{
    if(argc != 2){
      std::cout << "Error: An incorrect number of files has been inputted" << std::endl;
      std::exit(1);
    }
    //create memory, allocate memory to appropriate RAM size
    System s;
    uint32_t npc_prev = 0;
    s.ram.resize(0x30000008);
    s.regs.resize(32);

    file_to_memory(argv[1], s);

    while(true){
      if(s.pc == 0){
        uint32_t out = s.regs[2] & 0xFF;
        std::exit(out);
      }
      else if((s.pc < 0x10000000) || (s.pc >= 0x20000000)){
        throw -11;
      }

      s.regs[0] = 0;
      npc_prev = s.npc;
      //s.nnpc is set during the instructions
      Instr_def instruction = define_instruction(s);
      instructions(instruction, s);
      s.pc = npc_prev;
      if (s.npc+4 !=s.nnpc){
        s.npc = s.nnpc;
      }
    }
  }
  catch(const int exception){
    if(exception == -10){
      std::exit(-10); //Arithmetic exception
    }
    else if(exception == -11){
      std::exit(-11); //Memory exception
    }
    else if(exception == -12){
      std::exit(-12); //Invalid instruction
    }
  }
  catch(...){
    std::exit(-20); //Internal error
  }
}
