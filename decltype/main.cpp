
#include <iostream>

template<typename T>
bool isInt( T ) { return std::is_same_v<T, int>; }
#define TEST_INT( x ) std::cout << "isInt(" << x << ") = " << std::boolalpha << isInt( x ) << std::endl;

int main()
{
	TEST_INT( 1 );
	TEST_INT( .0f );
	TEST_INT( .5 );
	TEST_INT( &main );

	std::cout << std::is_integral_v< decltype( .4 )> << std::endl;
	std::cout << std::is_integral_v< decltype( std::declval<float>() ) > << std::endl;

	return 0;
}
