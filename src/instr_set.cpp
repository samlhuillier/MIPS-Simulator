#include <iostream>
#include "instr_set.hpp"

void sign_extend_16bit(uint32_t &number){
  uint32_t copy_number = number;
  uint32_t sign_bit = (copy_number >> 15)& 1;
  if (sign_bit==1){
    number = number + 0xFFFF0000;
  }
}

void sign_extend_byte(uint32_t &number){
  uint32_t copy_number = number;
  uint32_t sign_bit = (copy_number >> 7)& 1;
  if (sign_bit==1){
    number = number + 0xFFFFFF00;
  }
}

void instructions(Instr_def &i, System &sys){
  if(i.type == 'R'){
    if(i.funct == 0x20){
      add(sys, i.rs, i.rt, i.rd);
      return;
    }
    else if(i.funct == 0x21){
      addu(sys, i.rs, i.rt, i.rd);
      return;
    }
    else if(i.funct == 0x24){
      and_(sys, i.rs, i.rt, i.rd);
      return;
    }
    else if(i.funct == 0x1A){
      div(sys, i.rs, i.rt);
      return;
    }
    else if(i.funct == 0x1B){
      divu(sys, i.rs, i.rt);
      return;
    }
    else if(i.funct == 0x09){
      jalr(sys, i.rs, i.rt, i.rd);
      return;
    }
    else if(i.funct == 0x08){
      jr(sys, i.rt);
      return;
    }
    else if(i.funct == 0x10){
      mfhi(sys, i.rd);
      return;
    }
    else if(i.funct == 0x012){
      mflo(sys, i.rd);
      return;
    }
    else if(i.funct == 0x11){
      mthi(sys, i.rs);
      return;
    }
    else if(i.funct == 0x13){
      mtlo(sys, i.rs);
      return;
    }
    else if(i.funct == 0x18){
      mult(sys, i.rs, i.rt);
      return;
    }
    else if(i.funct == 0x19){
      multu(sys, i.rs, i.rt);
      return;
    }
    else if(i.funct == 0x25){
      or_(sys, i.rs, i.rt, i.rd);
      return;
    }
    else if(i.funct == 0x00){
      sll(sys, i.rt, i.rd, i.shamt);
      return;
    }
    else if(i.funct == 0x04){
      sllv(sys, i.rs, i.rt, i.rd);
      return;
    }
    else if(i.funct == 0x2A){
      slt(sys, i.rs, i.rt, i.rd);
      return;
    }
    else if(i.funct == 0x2B){
      sltu(sys, i.rs, i.rt, i.rd);
      return;
    }
    else if(i.funct == 0x03){
      sra(sys, i.rt, i.rd, i.shamt);
      return;
    }
    else if(i.funct == 0x07){
      srav(sys, i.rs, i.rt, i.rd);
      return;
    }
    else if(i.funct == 0x02){
      srl(sys, i.rt, i.rd, i.shamt);
      return;
    }
    else if(i.funct == 0x06){
      srlv(sys, i.rs, i.rt, i.rd);
      return;
    }
    else if(i.funct == 0x22){
      sub(sys, i.rs, i.rt, i.rd);
      return;
    }
    else if(i.funct == 0x23){
      subu(sys, i.rs, i.rt, i.rd);
      return;
    }
    else if(i.funct == 0x26){
      xor_(sys, i.rs, i.rt, i.rd);
      return;
    }
  }
  else if(i.type == 'J'){
    if(i.opcode == 0x02){
      j(sys, i.address);
      return;
    }
    else if(i.opcode == 0x03){
      jal(sys, i.address);
      return;
    }
  }
  else if(i.type == 'I'){
    if(i.opcode == 0x08){
      addi(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x09){
      addiu(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x0C){
      andi(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x04){
      beq(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x01){
      if(i.rt == 0x01){
        bgez(sys, i.rs, i.immediate);
      }
      else if(i.rt == 0x11){
        bgezal(sys, i.rs, i.immediate);
      }
      else if(i.rt == 0x00){
        bltz(sys, i.rs, i.immediate);
      }
      else if(i.rt == 0x10){
        bltzal(sys, i.rs, i.immediate);
      }
    }
    else if(i.opcode == 0x07){
      bgtz(sys, i.rs, i.immediate);
    }
    else if(i.opcode == 0x06){
      blez(sys, i.rs, i.immediate);
    }
    else if(i.opcode == 0x05){
      bne(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x20){
      lb(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x24){
      lbu(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x21){
      lh(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x25){
      lhu(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x0F){
      lui(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x23){
      lw(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x22){
      lwl(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x26){
      lwr(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x0D){
      ori(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x28){
      sb(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x29){
      sh(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x0A){
      slti(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x0B){
      sltiu(sys, i.rs, i.rt, i.immediate);
    }
    else if(i.opcode == 0x2B){
      sw(sys, i.rs, i.rt, i.immediate);
    }
  }
  else{
    throw -12;
  }
}

////// R-TYPE INSTRUCTIONS //////
void add(System &s, const uint32_t &rs, const uint32_t &rt, const uint64_t &rd){
  int32_t temp_answer = s.regs[rs]+s.regs[rt];
  int32_t signed_rs = s.regs[rs];
  int32_t signed_rt = s.regs[rt];
  if (signed_rt>0 && signed_rs>0){
    if (temp_answer<=0){
      throw -10;
    }
  }
  else if (signed_rs<0 && signed_rt<0){
    if (temp_answer>=0){
      throw -10;
    }
  }
  s.regs[rd] = temp_answer;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;
}
void addu(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd){
  s.regs[rd] = s.regs[rs] + s.regs[rt];
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void and_(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd){
  s.regs[rd] = s.regs[rs] & s.regs[rt];
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void div(System &s, const uint32_t &rs, const uint32_t &rt){
  int32_t signed_rs = s.regs[rs];
  int32_t signed_rt = s.regs[rt];
  if (signed_rt != 0){
    s.lo = signed_rs / signed_rt;
    s.hi = signed_rs % signed_rt;
  }
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void divu(System &s, const uint32_t &rs, const uint32_t &rt){
  if (s.regs[rt]!= 0){
    s.lo = s.regs[rs]/s.regs[rt];
    s.hi = s.regs[rs]%s.regs[rt];
  }
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void jalr(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd){//DO AFTER DOING J-TYPE INSTRUCTIONS
  s.regs[rd] = s.npc;
  uint32_t effective_address = s.regs[rs];
  //now we execute next instruction in delay slot
  s.npc = s.npc + 4;
  s.nnpc = effective_address;
}
void jr(System &s, const uint32_t &rs){

  uint32_t effective_address = s.regs[rs];
  if (effective_address&3!=0){
    throw -11;
  }
  s.npc = s.npc + 4;
  s.nnpc = effective_address;

}
void mfhi(System &s, const uint32_t &rd){
  s.regs[rd] = s.hi;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void mflo(System &s, const uint32_t &rd){
  s.regs[rd] = s.lo;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void mthi(System &s, const uint32_t &rs){
  s.hi = s.regs[rs];
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void mtlo(System &s, const uint32_t &rs){
  s.lo = s.regs[rs];
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void mult(System &s, const uint32_t &rs, const uint32_t &rt){
  uint64_t temp_rs = rs;
  uint64_t temp_rt = rt;
  uint64_t answer = temp_rs * temp_rt;
  s.hi = answer >> 32;
  s.lo = answer & 0xFFFFFFFF;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void multu(System &s, const uint32_t &rs, const uint32_t &rt){
  uint64_t temp_rs = rs;
  uint64_t temp_rt = rt;
  uint64_t answer = temp_rs * temp_rt;
  s.hi = answer >> 32;
  s.lo = answer & 0xFFFFFFFF;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void or_(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd){
  s.regs[rd] = s.regs[rt] | s.regs[rs];
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void sll(System &s, const uint32_t &rt, const uint32_t &rd, const uint32_t &shamt){
  s.regs[rd] = s.regs[rt]<<shamt;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void sllv(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd){
  s.regs[rd] = s.regs[rt]<<s.regs[rs];
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void slt(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd){
  int32_t signed_rs = s.regs[rs];
  int32_t signed_rt = s.regs[rt];
  if (signed_rs<signed_rt){
    s.regs[rd] = 1;
  }
  else {
    s.regs[rd] = 0;
  }
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void sltu(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd){
  if (s.regs[rs]<s.regs[rt]){
    s.regs[rd] = 1;
  }
  else {
    s.regs[rd] = 0;
  }
  s.npc = s.npc + 4;
}
void sra(System &s, const uint32_t &rt, const uint32_t &rd, const uint32_t &shamt){
  int32_t signed_rt = s.regs[rt];
  s.regs[rd] = signed_rt>>shamt;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void srav(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd){
  int32_t signed_rt = s.regs[rt];
  s.regs[rd] = signed_rt>>s.regs[rs];
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void srl(System &s, const uint32_t &rt, const uint32_t &rd, const uint32_t &shamt){
  s.regs[rd] = s.regs[rt]>>shamt;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void srlv(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd){
  s.regs[rd] = s.regs[rt]>>s.regs[rs];
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void sub(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd){
  int32_t temp_answer = s.regs[rs] - s.regs[rt];
  int32_t signed_rs = s.regs[rs];
  int32_t signed_rt = s.regs[rt];
  if (signed_rs > 0 && signed_rt < 0){
    if (temp_answer<=0){
      throw -10;
    }
  }
  else if (signed_rs<0 && signed_rt>0){
    if (temp_answer>=0){
      throw -10;
    }

  }
  s.regs[rd] = temp_answer;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void subu(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd){
  s.regs[rd] = s.regs[rs] - s.regs[rt];
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void xor_(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd){
  s.regs[rd] = s.regs[rt]^s.regs[rs];
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
/////////////////////////////////
////// J-TYPE INSTRUCTIONS //////
////////////////////////////////
void j(System &s, const uint32_t &address){
  uint32_t effective_address = address<<2;
  //now the delay slot needs to be executed
  s.npc = s.npc + 4;
  s.nnpc = ((s.pc & 0xF0000000) + effective_address);


}
void jal(System &s, const uint32_t &address){
  s.regs[31] = s.npc;
  uint32_t effective_address = address<<2;
  s.npc = s.npc + 4;
  s.nnpc = ((s.pc & 0xF0000000) + effective_address);

}
/////////////////////////////////
////// I-TYPE INSTRUCTIONS //////
////////////////////////////////
void addi(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  sign_extend_16bit(immediate);
  int32_t temp_answer = s.regs[rs]+immediate;
  int32_t signed_rs = s.regs[rs];
  int32_t signed_immediate = immediate;
  if (signed_immediate>0 && signed_rs>0){
    if (temp_answer<=0){
      throw -10;
    }
  }
  else if (signed_rs<0 && signed_immediate<0){
    if (temp_answer>=0){
      throw -10;
    }
  }
  s.regs[rt] = temp_answer;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void addiu(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  sign_extend_16bit(immediate);
  s.regs[rt] = s.regs[rs]+immediate;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void andi(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  s.regs[rt] = s.regs[rs] & immediate;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;


}
void beq(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t new_immediate = immediate <<2;
  if (s.regs[rs]==s.regs[rt]){
    s.npc = s.npc + 4;
    s.nnpc = s.npc + new_immediate;
  }
  else {
    s.npc = s.npc + 4;
  }
}
void bgez(System &s, const uint32_t &rs, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t new_immediate = immediate <<2;
  int32_t signed_rs = s.regs[rs];
  if (signed_rs>=0){
    s.npc = s.npc + 4;
    s.nnpc = s.npc + new_immediate;
  }
  else {
    s.npc = s.npc + 4;
  }
}
void bgezal(System &s, const uint32_t &rs, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t new_immediate = immediate <<2;
  s.regs[31] = s.npc;
  int32_t signed_rs = s.regs[rs];
  if (signed_rs>= 0){
    s.npc = s.npc + 4;
    s.nnpc = s.npc + new_immediate;
  }
  else {
    s.npc = s.npc + 4;
  }
}
void bgtz(System &s, const uint32_t &rs, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t new_immediate = immediate <<2;
  int32_t signed_rs = s.regs[rs];
  if (signed_rs>0){
    s.npc = s.npc + 4;
    s.nnpc = s.npc + new_immediate;
  }
  else {
    s.npc = s.npc + 4;
  }
}
void blez(System &s, const uint32_t &rs, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t new_immediate = immediate <<2;
  int32_t signed_rs = s.regs[rs];
  if (signed_rs<=0){
    s.npc = s.npc + 4;
    s.nnpc = s.npc + new_immediate;
  }
  else {
    s.npc = s.npc + 4;
  }
}
void bltz(System &s, const uint32_t &rs, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t new_immediate = immediate <<2;
  int32_t signed_rs = s.regs[rs];
  if (signed_rs<0){
    s.npc = s.npc + 4;
    s.nnpc = s.npc + new_immediate;
  }
  else {
    s.npc = s.npc + 4;
  }
}
void bltzal(System &s, const uint32_t &rs, uint32_t &immediate){//branch less than 0 and link
  sign_extend_16bit(immediate);
  uint32_t new_immediate = immediate <<2;
  s.regs[31] = s.npc;
  int32_t signed_rs = s.regs[rs];
  if (signed_rs< 0){
    s.npc = s.npc + 4;
    s.nnpc = s.npc + new_immediate;
  }
  else {
    s.npc = s.npc + 4;
  }
}
void bne(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t new_immediate = immediate <<2;
  if (s.regs[rs]!= s.regs[rt]){

    s.npc = s.npc + 4;
    s.nnpc = s.npc + new_immediate;
  }
  else {
    s.npc = s.npc + 4;
  }
}
void lb(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t byte_address = s.regs[rs]+immediate;
  if (!((byte_address>=0x10000000 & byte_address<0x11000000)|(byte_address>=0x20000000 & byte_address<0x24000000)|(byte_address>=0x30000000 & byte_address<0x30000004))){//subject to minor clarification
    //outside range so memory Error
    throw -11;
  }
  if (byte_address>=0x30000000 & byte_address<0x30000004){
    if (byte_address&0x3 != 3){
      throw -11;
    }
    char value_in;
    value_in = std::getchar();
    if (std::cin.eof()){
      value_in = 0xFF;
    }
    if (!std::cin.good()){
      throw -21;
    }
    if (value_in==-1){
      s.regs[rt] = 0xFFFFFFFF;
    }
    else{
      s.regs[rt]=value_in&0xFF;
    }
    s.npc = s.npc + 4;
    return;
  }
  uint32_t byte_result = s.ram[byte_address];
  sign_extend_byte(byte_result);
  s.regs[rt]= byte_result;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void lbu(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t byte_address = s.regs[rs]+immediate;
  if (!((byte_address>=0x10000000 & byte_address<0x11000000)|(byte_address>=0x20000000 & byte_address<0x24000000)|(byte_address>=0x30000000 & byte_address<0x30000004))){//subject to minor clarification
    //outside range so memory Error
    throw -11;
  }
  if (byte_address>=0x30000000 & byte_address<0x30000004){
    if (byte_address&0x3 != 3){
      throw -11;
    }
    char value_in;
    value_in = std::getchar();
    if (std::cin.eof()){
      value_in = 0xFF;
    }
    if (!std::cin.good()){
      throw -21;
    }
    if (value_in==-1){
      s.regs[rt] = 0xFFFFFFFF;
    }
    else{
      s.regs[rt]=value_in&0xFF;
    }
    s.npc = s.npc + 4;
    s.nnpc = s.nnpc + 4;

    return;
  }
  uint32_t byte_answer = s.ram[byte_address];
  s.regs[rt]= byte_answer;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void lh(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t effective_address = s.regs[rs]+immediate;
  uint32_t lower_byte, higher_byte;
  if (effective_address&1!=0){
    throw -11;
  }
  if (!((effective_address>=0x10000000 && effective_address<0x11000000-0x1)||(effective_address>=0x20000000 && effective_address<0x24000000-0x1)||(effective_address>=0x30000000 && effective_address<0x30000003))){//subject to minor clarification
    //outside range so memory Error
    throw -11;
  }

  if (effective_address>=0x30000000 && effective_address<0x30000004){
    if (effective_address&3 != 2){
      throw -11;
    }
    char value_in;
    value_in = std::getchar();
    if (std::cin.eof()){
      value_in = 0xFF;
    }
    if (!std::cin.good()){
      throw -21;
    }
    if (value_in==-1){
      s.regs[rt] = 0xFFFFFFFF;
    }
    else{
      s.regs[rt]=value_in&0xFF;
    }
    s.npc = s.npc + 4;
    s.nnpc = s.nnpc + 4;

    return;
  }

  higher_byte = s.ram[effective_address];
  lower_byte = s.ram[effective_address+1];

  uint32_t answer = (higher_byte<<8)+lower_byte;
  sign_extend_16bit(answer);
  s.regs[rt]=answer;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;


}
void lhu(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t effective_address = s.regs[rs]+immediate;
  uint32_t lower_byte, higher_byte;
  if (effective_address&1!=0){
    throw -11;
  }
  if (!((effective_address>=0x10000000 && effective_address<0x11000000-0x1)||(effective_address>=0x20000000 && effective_address<0x24000000-0x1)||(effective_address>=0x30000000 && effective_address<0x30000003))){//subject to minor clarification
    //outside range so memory Error
    throw -11;
  }

  if (effective_address>=0x30000000 && effective_address<0x30000004){
    if ((effective_address&3) != 2){
      throw -11;
    }
    char value_in;
    value_in = std::getchar();
    if (std::cin.eof()){
      value_in = 0xFF;
    }
    if (!std::cin.good()){
      throw -21;
    }
    if (value_in==-1){
      s.regs[rt] = 0xFFFFFFFF;
    }
    else{
      s.regs[rt]=value_in&0xFF;
    }
    s.npc = s.npc + 4;
    s.nnpc = s.nnpc + 4;

    return;
  }

  higher_byte = s.ram[effective_address];
  lower_byte = s.ram[effective_address+1];

  uint32_t answer = (higher_byte<<8)+lower_byte;
  s.regs[rt]=answer;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void lui(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  if (rs != 0){
    throw -12;
  }
  s.regs[rt] = immediate<<16;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void lw(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t effective_address = s.regs[rs]+immediate;
  //checking within range:
  if (effective_address&0x3 != 0x0){
    throw -11;
  }
  if (!((effective_address>=0x10000000 && effective_address<0x11000000-0x3)||(effective_address>=0x20000000 && effective_address<0x24000000-0x3)||(effective_address>=0x30000000))){//subject to minor clarification
    //outside range so memory Error
    throw -11;
  }
  if (effective_address==0x30000000){
    char user_input = std::getchar();

    if (!std::cin.good()){
      //io error:
      throw -21;
    }
    if (std::cin.eof()){
      s.regs[rt]=0xFFFFFFFF;
      return;
    }
    else {
      s.regs[rt] = user_input&0xFF;
    }
    s.npc = s.npc + 4;
    s.nnpc = s.nnpc + 4;
  }
  //no need for sign extension
  //now we just load each byte
  uint32_t answer = s.ram[effective_address]<<24+s.ram[effective_address+1]<<16+s.ram[effective_address+2]<<8+s.ram[effective_address+3];
  s.regs[rt]=answer;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;



}
void lwl(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t effective_address = s.regs[rs]+immediate;
  if (!((effective_address>=0x10000000 & effective_address<0x11000000)|(effective_address>=0x20000000 & effective_address<0x24000000)|(effective_address>=0x30000000 & effective_address<0x30000004))){//subject to minor clarification
    //outside range so memory Error
    throw -11;
  }
  if (effective_address&3==0){
    uint32_t answer = s.ram[effective_address]<<24+s.ram[effective_address+1]<<16+s.ram[effective_address+2]<<8+s.ram[effective_address+3];
    s.regs[rt]=answer;
  }
  else if (effective_address&3 == 1){
    uint32_t answer = s.ram[effective_address]<<24+s.ram[effective_address+1]<<16+s.ram[effective_address+2]<<8;
    s.regs[rt]=answer + s.regs[rt]&0xFF;
  }
  else if (effective_address&3 == 2){
    uint32_t answer = s.ram[effective_address]<<24+s.ram[effective_address+1]<<16;
    s.regs[rt]=answer + s.regs[rt]&0xFFFF;
  }
  else if (effective_address&3 == 3){
    uint32_t answer = s.ram[effective_address]<<24;
    s.regs[rt]=answer + s.regs[rt]&0xFFFFFF;
  }
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;
}
void lwr(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t effective_address = s.regs[rs]+immediate;
  if (!((effective_address>=0x10000000 & effective_address<0x11000000)|(effective_address>=0x20000000 & effective_address<0x24000000)|(effective_address>=0x30000000 & effective_address<0x30000004))){//subject to minor clarification
    //outside range so memory Error
    throw -11;
  }
  if (effective_address&3==0){
    uint32_t answer = s.ram[effective_address];
    s.regs[rt]=s.regs[rt]&0xFFFFFF00+answer;
  }
  else if (effective_address&3 == 1){
    uint32_t answer = s.ram[effective_address]+s.ram[effective_address-1]<<8;
    s.regs[rt]=s.regs[rt]&0xFFFF0000+answer;
  }
  else if (effective_address&3 == 2){
    uint32_t answer = s.ram[effective_address]+s.ram[effective_address-1]<<8+s.ram[effective_address-2]<<16;
    s.regs[rt]=s.regs[rt]&0xFF000000+answer;
  }
  else if (effective_address&3 == 3){
    uint32_t answer = s.ram[effective_address]+s.ram[effective_address-1]<<8+s.ram[effective_address-2]<<16+s.ram[effective_address-3]<<24;
    s.regs[rt]=s.regs[rt]&0x00000000+answer;
  }
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;
}
void ori(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  s.regs[rt]=s.regs[rs]|immediate;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;
}
void sb(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t byte_address = s.regs[rs]+immediate;
  if (!((byte_address>=0x20000000 && byte_address<0x24000000)||(byte_address>=0x30000004 && byte_address<0x30000008))){//subject to minor clarification
    //outside range so memory Error
    throw -11;
  }
  char actual_byte = s.regs[rt]&0xFF;
  if (byte_address>=0x30000004 & byte_address<0x30000008){
    if (byte_address&3 != 3){
      throw -11;
    }
    std::putchar(actual_byte);
    if (!std::cout.good()){
      throw -21;
    }
    s.npc = s.npc + 4;
    s.nnpc = s.nnpc + 4;
    return;
  }

  s.ram[byte_address]=actual_byte;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void sh(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t effective_address = s.regs[rs]+immediate;
  if (effective_address&1!=0){
    throw -11;
  }
  uint32_t lower_byte, higher_byte;
  if (!((effective_address>=0x20000000 && effective_address<0x24000000-0x1)||(effective_address>=0x30000004 && effective_address<0x30000007))){//subject to minor clarification
    //outside range so memory Error
    throw -11;
  }
  lower_byte = s.regs[rt]&0xFF;
  higher_byte = s.regs[rt]&0xFF00;
  if (effective_address>=0x30000004 && effective_address<0x30000008){
    if (effective_address&3 != 2){
      throw -11;
    }
    std::putchar(lower_byte);
    if (!std::cout.good()){
      throw -21;
    }
    s.npc = s.npc + 4;
    s.nnpc = s.nnpc + 4;
    return;
  }

  s.ram[effective_address]=higher_byte;
  s.ram[effective_address+1]=lower_byte;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;


}
void slti(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  sign_extend_16bit(immediate);
  int32_t contents = s.regs[rs];
  if (contents < immediate){
    s.regs[rt] = 1;
  }
  else {
    s.regs[rt] = 0;
  }
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;

}
void sltiu(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t contents = s.regs[rs];
  if (contents < immediate){
    s.regs[rt] = 1;
  }
  else {
    s.regs[rt] = 0;
  }
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;
}
void sw(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate){
  sign_extend_16bit(immediate);
  uint32_t effective_address = s.regs[rs]+immediate;
  uint32_t answer = s.regs[rt];
  //MUST BE NATURALLY ALLIGNED:
  if (effective_address & 3 != 0){
    throw -11;
  }
  //address in right place
  if (!((effective_address>=0x20000000 && effective_address<0x24000000-0x3)||(effective_address==0x30000004))){
    throw -11;
  }
  if (effective_address>=0x30000004 && effective_address<0x30000008){
    if (effective_address&3 != 0){
      throw -11;
    }
    std::putchar(answer&0xFF);
    if (!std::cout.good()){
      throw -21;
    }
    s.npc = s.npc + 4;
    s.nnpc = s.nnpc + 4;
    return;
  }
  s.ram[effective_address]=(answer&0xFF000000)>>24;
  s.ram[effective_address+1]=(answer&0x00FF0000)>>16;
  s.ram[effective_address+2]=(answer&0x0000FF00)>>8;
  s.ram[effective_address+3]=(answer)&0xFF;
  s.npc = s.npc + 4;
  s.nnpc = s.nnpc + 4;
}
