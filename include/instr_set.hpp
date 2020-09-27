#ifndef INSTR_SET_HPP
#define INSTR_SET_HPP

#include <iostream>
#include "instr_def.hpp"

void sign_extend_16bit(uint32_t &number);
void sign_extend_byte(uint32_t &number);
void instructions(Instr_def &instr_in, System &sys);
////// R-TYPE INSTRUCTIONS //////
void add(System &s, const uint32_t &rs, const uint32_t &rt, const uint64_t &rd);
void addu(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd);
void and_(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd);
void div(System &s, const uint32_t &rs, const uint32_t &rt);
void divu(System &s, const uint32_t &rs, const uint32_t &rt);
void jalr(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd);
void jr(System &s, const uint32_t &rt);
void mfhi(System &s, const uint32_t &rd);
void mflo(System &s, const uint32_t &rd);
void mthi(System &s, const uint32_t &rs);
void mtlo(System &s, const uint32_t &rs);
void mult(System &s, const uint32_t &rs, const uint32_t &rt);
void multu(System &s, const uint32_t &rs, const uint32_t &rt);
void or_(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd);
void sll(System &s, const uint32_t &rt, const uint32_t &rd, const uint32_t &shamt);
void sllv(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd);
void slt(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd);
void sltu(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd);
void sra(System &s, const uint32_t &rs, const uint32_t &rd, const uint32_t &shamt);
void srav(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd);
void srl(System &s, const uint32_t &rs, const uint32_t &rd, const uint32_t &shamt);
void srlv(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd);
void sub(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd);
void subu(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd);
void xor_(System &s, const uint32_t &rs, const uint32_t &rt, const uint32_t &rd);
////// I-TYPE INSTRUCTIONS //////
void addi(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void addiu(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void andi(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void beq(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void bgez(System &s, const uint32_t &rs, uint32_t &immediate);
void bgezal(System &s, const uint32_t &rs, uint32_t &immediate);
void bltz(System &s, const uint32_t &rs, uint32_t &immediate);
void bltzal(System &s, const uint32_t &rs, uint32_t &immediate);
void bgtz(System &s, const uint32_t &rs, uint32_t &immediate);
void blez(System &s, const uint32_t &rs, uint32_t &immediate);
void bne(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void lb(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void lbu(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void lh(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void lhu(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void lui(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void lw(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void lwl(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void lwr(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void ori(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void sb(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void sh(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void slti(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void sltiu(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
void sw(System &s, const uint32_t &rs, const uint32_t &rt, uint32_t &immediate);
  ////// J-TYPE INSTRUCTIONS //////
void j(System &s, const uint32_t &address);
void jal(System &s, const uint32_t &address);

#endif
