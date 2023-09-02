#include "BasicAllocator.h"

#include <vector>
#include <iostream>

int main()
{
	{
		std::vector<int, BasicAllocator<int>> v( 8 );
		v.push_back( 42 );
	}
	std::cout << "----------" << std::endl;
	{
		auto report = []( std::vector<int, BasicAllocator<int>>& vec ) {
			std::cout << "[Report] vector has size=" << vec.size() << " and capacity=" << vec.capacity() << "\n";
		};
		std::cout << "create vector of 8 ints:\n";
		std::vector<int, BasicAllocator<int>> v( 8 );
		report( v );

		std::cout << "Add 1 element:\n";
		v.push_back( 42 );
		report( v );
	}
	std::cin.get();
}
