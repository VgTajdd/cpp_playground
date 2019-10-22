#include <iostream>

int main()
{
	{
		bool* boolptr = new bool( false );
		delete boolptr;

		int* intptr = new int( 10 );
		delete intptr;

		void* tempPtr1 = new int( 1 );
		delete tempPtr1;

		void* tempPtr2 = new double( 2.0 );
		delete tempPtr2;

		void* tempPtr3 = new bool( false );
		delete tempPtr3;

		__debugbreak();
	}

	{
		const int a = 5;
		int b = 2;
		int c = 3;

		// Pointer (raw).
		int* ptr = &b;
		//ptr = &a; // <- This will give us and error, because It can be possible to modify constant value.
		ptr = &b; // ok
		( *ptr )++; // ok (modifying the value pointer is pointing to)
		ptr++; // ok (modifying address pointer is pointing to) (ptr will increase sizeof(int), is this case is 4, if type of pointed value is double: ptr++ <> ptr = &ptr + 8)
		ptr--;
		ptr = (int*) ( (char*) ptr + sizeof( int ) );

		// Constant pointer: These type of pointers are the one which cannot change address they are pointing to.
		int* const p1 = &b;
		//p1 = &b; // <- This will give us and error, because It can't be reasingned.
		( *p1 )++; // ok (modifying the value pointer is pointing to)

		// Pointer to constant: These type of pointers are the one which cannot change the value they are pointing to.
		const int* p2 = &a;
		const int* p3 = &c;
		p2 = &b;
		p2++; // ok (modifying address pointer is pointing to)

		__debugbreak();
	}

	{
		//int* a = { 0, 1 };
		int* a = nullptr;
		int b[] = { 0, 1 }; // The size of the array is not specified (is implicit specified) It need to be initialized here.
		//int b[]; // Wrong.
		int c[2]; // It also is initialized here, but it can be created without a lvalue (without assigning).
		int d[3] = { 1, 2, 3 }; // It's OK.
		a = b;
		a = c;
		a = d;

		__debugbreak();
	}

	{
		int* a;
		int b = 20;
		int c = 30;
		a = &b;

		double* d;
		double e = 1.2;
		d = &e;

		std::cout << sizeof( a ) << std::endl; // sizeof(any poiter) = 4 bytes (32bits), because pointer is a integer and its value is the memory adress they are pointing to. (if platform for the project is 64 this changes to 8 (64bits)).
		std::cout << sizeof( b ) << std::endl;
		std::cout << sizeof( c ) << std::endl;
		std::cout << sizeof( d ) << std::endl; // sizeof(any poiter) = 4 bytes (32bits), because pointer is a integer and its value is the memory adress they are pointing to. (if platform for the project is 64 this changes to 8 (64bits)).
		std::cout << sizeof( e ) << std::endl;

		__debugbreak();
	}

	return 0;
}