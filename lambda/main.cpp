#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

void ForEach( const std::vector< int >& values, const std::function< void( int ) >& func )
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
	ForEach( values, lambda );

	std::cin.get();
	return 0;
}