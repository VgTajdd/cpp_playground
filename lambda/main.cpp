#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

// https://stackoverflow.com/questions/39428437/stdfunction-vs-lambda-for-passing-member-functions

void forEach( const std::vector< int >& values, const std::function< void( int ) >& func )
{
	for ( const int& value : values )
	{
		func( value );
	}
}

int main()
{
	std::vector< int > values = { 1, 5, 4, 2, 3 };
	auto it = std::find_if( values.begin(), values.end(), []( int value ) { return value > 3; } );
	std::cout << *it << std::endl;

	std::cout << std::endl;

	int a = 5;
	[&]() { std::cout << "Value: " << ++a << std::endl; }();

	std::cout << std::endl;

	auto lambda = [=]( int value ) { std::cout << "Value: " << value << std::endl; };
	forEach( values, lambda );

	std::cin.get();
	return 0;
}