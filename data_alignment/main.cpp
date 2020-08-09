#include <iostream>
#include <climits>

struct bc_1
{
	int a : 1;
	int b : 1;
};

struct bc_2
{
	int a : 31;
	int b : 1;
};

struct bc_3
{
	int a : 32;
	int b : 1;
};

struct bc_4
{
	int a : 31;
	int b : 2;
};

struct bc_5
{
	int a : 32;
	int b : 32;
};

/*struct bc_6
{
	int a : 40; // ERROR: integer only can have up to 32 bytes.
	int b : 32;
};

struct bc_7
{
	int a : 63; // ERROR: integer only can have up to 32 bytes
	int b : 1;
};*/

int main( int argc, char * argv[] )
{
	std::cout << "CHAR_BIT = " << CHAR_BIT;
	std::cout << " => sizeof(int) = " << sizeof( int ) << " bytes" << std::endl;

	std::cout << "1,  1:  " << sizeof( struct bc_1 ) << " bytes" << std::endl;
	std::cout << "31, 1:  " << sizeof( struct bc_2 ) << " bytes" << std::endl;
	std::cout << "32, 1:  " << sizeof( struct bc_3 ) << " bytes" << std::endl;
	std::cout << "31, 2:  " << sizeof( struct bc_4 ) << " bytes" << std::endl;
	std::cout << "32, 32: " << sizeof( struct bc_5 ) << " bytes" << std::endl;
	//std::cout << "40, 32: " << sizeof( struct bc_6 ) << " bytes" << std::endl;
	//std::cout << "63, 1:  " << sizeof( struct bc_7 ) << " bytes" << std::endl;

	std::cin.get();
}