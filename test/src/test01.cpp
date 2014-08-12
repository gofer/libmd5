#include <iostream>
#include <string>
#include <md5.hpp>

void test1() {
	std::string src = "";
	std::string dst = MD5::to_string( MD5::hash(src) );
	std::cout << dst << std::endl;
}

void test2() {
	std::string src = "a";
	std::string dst = MD5::to_string( MD5::hash(src) );
	std::cout << dst << std::endl;
}

void test3() {
	std::string src = "abc";
	std::string dst = MD5::to_string( MD5::hash(src) );
	std::cout << dst << std::endl;
}

void test4() {
	std::string src = "message digest";
	std::string dst = MD5::to_string( MD5::hash(src) );
	std::cout << dst << std::endl;
}

void test5() {
	std::string src = "abcdefghijklmnopqrstuvwxyz";
	std::string dst = MD5::to_string( MD5::hash(src) );
	std::cout << dst << std::endl;
}

int main(void) {
	MD5::md5_init();
	
	test1();
	
	test2();
	
	test3();
	
	test4();
	
	test5();
	
	return 0;
}
