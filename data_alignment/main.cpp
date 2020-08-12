/*

Each object type imposes its alignment requirement on every object of that type;
stricter alignment (with larger alignment requirement) can be requested using alignas.

In order to satisfy alignment requirements of all non - static members of a class,
padding may be inserted after some of its members.

https://en.cppreference.com/w/cpp/language/object#Alignment

*/

/*
Objects of type Student must be allocated at 4-byte boundaries
because Student.id and Student.age must be allocated at 4-byte boundaries
because int's alignment requirement is (usually) 4.
*/
struct Student
{
	char sex;	// 1 bytes. (3 padding bytes)
	int id;		// 4 bytes.
	char type;	// 1 byte. (3 padding bytes)
	int age;	// 4 byte.
}; // alignment = 4, size = 16.

struct Student2
{
	int id;		// 4 bytes.
	int age;	// 4 bytes.
	char sex;	// 1 byte.
	char type;	// 1 byte.
}; // alignment = 4, size = 12.

struct Student3
{
	int id;		// 4 bytes.
	int age;	// 4 bytes.
	char sex;	// 1 bytes.
	char type;	// 1 bytes.
	double x;	// 8 bytes.
}; // alignment = 8, size = 24.

struct Student4
{
	short id;	// 2 bytes.
	short age;	// 2 bytes.
	char sex;	// 1 bytes.
	char type;	// 1 bytes.
}; // alignment = 2, size = 6.

#include <iostream>

int main()
{
	std::cout << "sizeof( Student ) = " << sizeof( Student ) << " bytes \t| ";
	std::cout << "alignof( Student ) = " << alignof( Student ) << " bytes" << std::endl;

	std::cout << "sizeof( Student2 ) = " << sizeof( Student2 ) << " bytes \t| ";
	std::cout << "alignof( Student2 ) = " << alignof( Student2 ) << " bytes" << std::endl;

	std::cout << "sizeof( Student3 ) = " << sizeof( Student3 ) << " bytes \t| ";
	std::cout << "alignof( Student3 ) = " << alignof( Student3 ) << " bytes" << std::endl;

	std::cout << "sizeof( Student4 ) = " << sizeof( Student4 ) << " bytes \t| ";
	std::cout << "alignof( Student4 ) = " << alignof( Student4 ) << " bytes" << std::endl;

	std::cin.get();

	return 0;
}