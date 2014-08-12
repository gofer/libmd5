#include <iostream>
#include <string>
#include <md5.hpp>

int main(void) {
	MD5::md5_init();
	
	MD5::Hash  *hash = new MD5::Hash;
	std::string *dst = new std::string();
	
	std::string *src1 = new std::string("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
	MD5::hash(src1, hash);
	MD5::to_string(hash, dst);
	std::cout << *dst << std::endl;
	delete src1;
	std::cout << "d174ab98d277d9f5a5611c2c9f419d9f" << std::endl;
	std::cout << std::endl;
	
	std::string *src2 = new std::string("12345678901234567890123456789012345678901234567890123456789012345678901234567890");
	MD5::hash(src2, hash);
	MD5::to_string(hash, dst);
	std::cout << *dst << std::endl;
	delete src2;
	std::cout << "57edf4a22be3c955ac49da2e2107b67a" << std::endl;
	
	std::cout << std::endl;
	
	std::string *src3 = new std::string("The quick brown fox jumps over the lazy dog");
	MD5::hash(src3, hash);
	MD5::to_string(hash, dst);
	std::cout << *dst << std::endl;
	delete src3;
	std::cout << "9e107d9d372bb6826bd81d3542a419d6" << std::endl;
	
	std::cout << std::endl;
	
	std::string *src4 = new std::string("The quick brown fox jumps over the lazy dog.");
	MD5::hash(src4, hash);
	MD5::to_string(hash, dst);
	std::cout << *dst << std::endl;
	delete src4;
	std::cout << "e4d909c290d0fb1ca068ffaddf22cbd0" << std::endl;
	
	delete dst;
	delete hash;
	
	return 0;
}
