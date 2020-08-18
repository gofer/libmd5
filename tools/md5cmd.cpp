#include <iostream>
#include <string>
#include <md5.hpp>

int main(int argc, char** argv) {
	std::string src, dst;
	
	MD5::md5_init();
	
	std::cin >> src;
	
	dst = MD5::to_string( MD5::hash(src) );
	
	std::cout << dst << std::endl;
	
	return 0;
}
