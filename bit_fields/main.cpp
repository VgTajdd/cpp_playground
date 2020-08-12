struct
{
	int a : 4;
	int b : 13;
	int c : 1;
} test1;

struct
{
	short a : 4;
	short b : 3;
} test2;

struct
{
	char a : 4;
	char b : 3;
} test3;

struct
{
	char a : 4;
	short b : 3;
} test4;


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

#include <iostream>

int main()
{
	printf( "test1: %d\ntest2: %d\ntest3: %d\ntest4: %d\n",
			(int) sizeof( test1 ),
			(int) sizeof( test2 ),
			(int) sizeof( test3 ),
			(int) sizeof( test4 ) );

	std::cout << "1,  1:  " << sizeof( struct bc_1 ) << " bytes" << std::endl;
	std::cout << "31, 1:  " << sizeof( struct bc_2 ) << " bytes" << std::endl;
	std::cout << "32, 1:  " << sizeof( struct bc_3 ) << " bytes" << std::endl;
	std::cout << "31, 2:  " << sizeof( struct bc_4 ) << " bytes" << std::endl;
	std::cout << "32, 32: " << sizeof( struct bc_5 ) << " bytes" << std::endl;

	std::cin.get();

	return 0;
}