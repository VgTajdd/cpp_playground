#include <iostream>

struct my_struct_t
{
	bool dummyBoolean;	// 1 byte
						// 7 bytes padding.
	double dummyDouble;	// 8 bytes
}; // alignof = 8bytes, size = 16bytes.

class A
{
public:
	A() {};
	int fib( int i )
	{
		if ( i == 0 ) return 0;
		if ( i == 1 ) return 1;
		return fib( i - 1 ) + fib( i - 2 );
	}
	~A() noexcept(false) //
	{
		throw 42;
	}
};

int main()
{
//#if 0
	my_struct_t* bar;
	my_struct_t temp = my_struct_t{ false, 0.5 };
	bar = &temp;
	std::cout << "sizeof(bar)=" << sizeof( bar ) << "; sizeof(*bar)=" << sizeof( *bar ) << std::endl;
	//memset( bar, 1, sizeof( bar ) );	// DON'T DO THIS! This will use size of a pointer, which is 4 bytes in 32 bit systems and 8 bytes in 64 bits systems.
										// In this case this will only populate the first 8 bytes (64bit), but size of my_struct_t is 16 bytes.
	memset( bar, 1, sizeof( *bar ) );	// OK!

	std::cin.get();

	// Pointer to array.
	{
		// Pointer to an array of five numbers
		int( *a )[5];
		int b[5] = { 1, 2, 3, 4, 5 };

		// Points to the whole array b
		a = &b;

		printf( "%d\n", (int)sizeof( a ) ); // 4
		printf( "%d\n", (int) sizeof( *a ) ); // 20

		printf( "%p\n", a );
		printf( "%p\n", *a );
		printf( "%d\n", *( *a ) );

		int* ptr = *a;

		for ( int i = 0; i < 5; i++ )
		{
			//printf( "%d, pos in memory: %p\n", *( ptr + i ), ptr + i );		// The 3 ways
			printf( "%d, pos in memory: %p\n", *( ( *a ) + i ), ( *a ) + i );	// are
			// printf( "%d, pos in memory: %p\n", (*a)[i], (*a)+i );			// equivalent.
		}
	}
	std::cin.get();

	// Recursive inline function (member function).
	{
		A objA;
		int fib = objA.fib( 10 );
	}

	std::cin.get();
	{
		int a[] = { 1, 2, 3, 4, 5, 6 };
		std::cout << ( 1 + 3 )[a] - a[0] + ( a + 1 )[2]; // 8
		// ( 1 + 3 )[a] is the same as a[1 + 3] == 5
		// a[0] == 1
		// ( a + 1 )[2] is the same as a[3] == 4

	}
	std::cin.get();
//#endif

	return 0;
}