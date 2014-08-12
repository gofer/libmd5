#ifndef __MD5_HPP__
#define __MD5_HPP__

#include <array>
#include <string>

namespace MD5 {
	const uint32_t BITS_PER_BYTE = 8;

	union _UINT64_T {
		uint64_t i;
		unsigned char s[64/BITS_PER_BYTE];
	};

	union _UINT32_T {
		uint32_t i;
		unsigned char s[32/BITS_PER_BYTE];
	};
	
	typedef std::array<_UINT32_T, 4> Hash;
	
	void md5_init();
	
	Hash hash(const std::string&);
	std::string to_string(const Hash&);
	
	int hash(const std::string*, Hash*);
	int to_string(const Hash*, std::string*);
};

#endif
