#include <iostream>

struct Demo
{
	int data[2]; // alignof = 4 bytes, sizeof = 8 bytes.
	Demo( int x, int y ) : data{ x, y } {}
	virtual void f() {} // creates a pointer.
						// for 32 bits : alignof( pointer ) = 4 bytes, sizeof( pointer ) = 4 bytes.
						// for 64 bits : alignof( pointer ) = 8 bytes, sizeof( pointer ) = 8 bytes.
};

int main()
{
	// See the results compiling in 32bits and 64bits
	std::cout << sizeof( Demo ) << std::endl;
	// for 32 bits : alignof( Demo ) = 4 bytes, sizeof( Demo ) = 12 bytes.
	// for 64 bits : alignof( Demo ) = 8 bytes, sizeof( Demo ) = 16 bytes.

	std::cin.get();
	return 0;
}