#include <cmath>
#include <md5.hpp>
#include "md5_utils.hpp"

namespace MD5 {
static std::array<uint64_t, 64> T;

void md5_init() {
	for(int i=0; i<64; ++i)
		T[i] = ::fabs(::sin( static_cast<double>(i+1) )) * 0x100000000;
}

uint32_t big2ltl32(uint32_t p) {
	_UINT32_T t;
	t.i = p;
	std::swap(t.s[0], t.s[3]);
	std::swap(t.s[1], t.s[2]);
	p = t.i;
	return p;
}

uint32_t RotateLeft(uint32_t x, uint32_t y)
	{return (x << y) | (x >> (32-y));}

uint32_t  F(uint32_t X, uint32_t Y, uint32_t Z) {return ((X & Y) | ((~X) & Z));}
uint32_t FF(uint32_t a, uint32_t b, uint32_t c,uint32_t d, uint32_t x_k, uint32_t s, uint32_t i) 
	{return b + RotateLeft((a + F(b,c,d) + x_k + static_cast<uint32_t>(T[i-1])), s);}

uint32_t  G(uint32_t X, uint32_t Y, uint32_t Z) {return ((X & Z) | (Y & (~Z)));}
uint32_t GG(uint32_t a, uint32_t b, uint32_t c,uint32_t d, uint32_t x_k, uint32_t s, uint32_t i) 
	{return b + RotateLeft((a + G(b,c,d) + x_k + static_cast<uint32_t>(T[i-1])), s);}

uint32_t  H(uint32_t X, uint32_t Y, uint32_t Z) {return X ^ Y ^ Z;}
uint32_t HH(uint32_t a, uint32_t b, uint32_t c,uint32_t d, uint32_t x_k, uint32_t s, uint32_t i) 
	{return b + RotateLeft((a + H(b,c,d) + x_k + static_cast<uint32_t>(T[i-1])), s);}

uint32_t  I(uint32_t X, uint32_t Y, uint32_t Z) {return Y ^ (X | (~Z));}
uint32_t II(uint32_t a, uint32_t b, uint32_t c,uint32_t d, uint32_t x_k, uint32_t s, uint32_t i) 
	{return b + RotateLeft((a + I(b,c,d) + x_k + static_cast<uint32_t>(T[i-1])), s);}
};
