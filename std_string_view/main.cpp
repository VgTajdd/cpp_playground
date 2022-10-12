#include <iostream>
#include <string_view>

/**
* Reference:
* https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view/
*/

void* operator new( size_t sizeInBytes )
{
	std::cout << "Dynamic allocated: " << sizeInBytes << " bytes." << std::endl;
	return malloc( sizeInBytes );
}

template<typename T>
void printString( T stringToPrint )
{
	std::cout << stringToPrint << std::endl;
}

int main()
{
	{
		// 2 unnecessary copies will be generated (4 allocations because is a long string).
		printString( "Using std::string:" );
		std::string long_string{"HolaaAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA!"};
		printString( long_string );
	}

	{
		printString( "\nUsing std::string_view:" );
		std::string_view long_string{ "HolaaAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA!" };
		printString( long_string );

		// It supports constexpr.
		constexpr std::string_view s{ "\nSupports constexpr!" };
		printString( s );
	}

	std::cin.get();
	return EXIT_SUCCESS;
}
