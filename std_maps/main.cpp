#include <iostream>
#include <map>

int main()
{
	const unsigned int totalElements = 10;
	std::map< int, int > dummy;
	for ( int i = 0; i < 10; i++ ) dummy.emplace( i, i );

	for ( auto it = dummy.begin(); it != dummy.end(); )
	{
		if ( it->first == 3 )
		{
			it = dummy.erase( it );
		}
		else
		{
			it++;
		}
	}

	for ( const auto& it : dummy )
	{
		std::cout << it.first << ", " << it.second << std::endl;
	}

	std::cin.get();

	return 0;
}