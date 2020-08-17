#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <array>
#include <cstdint>

namespace MD5 {
uint32_t big2ltl32(uint32_t);

uint32_t RotateLeft(uint32_t, uint32_t);

uint32_t  F(uint32_t, uint32_t, uint32_t);
uint32_t FF(uint32_t, uint32_t, uint32_t,uint32_t, uint32_t, uint32_t, uint32_t);

uint32_t  G(uint32_t, uint32_t, uint32_t);
uint32_t GG(uint32_t, uint32_t, uint32_t,uint32_t, uint32_t, uint32_t, uint32_t);

uint32_t  H(uint32_t, uint32_t, uint32_t);
uint32_t HH(uint32_t, uint32_t, uint32_t,uint32_t, uint32_t, uint32_t, uint32_t);

uint32_t  I(uint32_t, uint32_t, uint32_t);
uint32_t II(uint32_t, uint32_t, uint32_t,uint32_t, uint32_t, uint32_t, uint32_t);
};

#endif //__UTILS_HPP__
