#include <iostream>
#include "file_to_memory.hpp"

void file_to_memory(const std::string &file, System &s){
  s.pc = 0x10000000;
  s.npc = 0x10000004;
  s.nnpc = 0x10000008;

  std::ifstream infile(file, std::ios::in | std::ios::binary | std::ios::ate); //passing command line paramter into binary_input file
  if(infile.is_open()){
    std::streampos size;
    char* memblock;
    size = infile.tellg(); //size of file
    memblock = new char[size]; //store size in memblock
    infile.seekg(0, std::ios::beg);
    infile.read(memblock, size);
    infile.close();
    //for loop for putting each byte into to RAM vector
    uint32_t bin_8;
    for(uint32_t i = 0, addr = 0x10000000; i < size; i++, addr++){
      bin_8 = memblock[i];
      s.ram[addr] = bin_8&0xFF;
    }

    delete[] memblock;
  }
  else{
    std::cout << "Error: unable to open file" << std::endl;
    exit(2);
  }
}
