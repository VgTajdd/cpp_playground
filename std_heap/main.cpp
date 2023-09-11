#include <algorithm>
#include <vector>
#include <iostream>

// Reference: https://www.geeksforgeeks.org/cpp-stl-heap/

void print( std::vector<int>& vc )
{
	for ( auto i : vc )
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void make_heap_example()
{
	// Initializing a vector
	std::vector<int> v1 = { 20, 30, 40, 25, 15 };

	// Converting vector into a heap
	// using make_heap()
	make_heap( v1.begin(), v1.end() );

	// Displaying the maximum element of heap
	// using front()
	std::cout << "The maximum element of heap is : ";
	std::cout << v1.front() << std::endl;
}

void push_heap_example()
{
	std::vector <int> vc{20, 30, 40, 10};

	make_heap( vc.begin(), vc.end() );
	std::cout << "Initial Heap: ";
	print( vc );

	vc.push_back( 50 );
	std::cout << "Heap just after push_back(): ";
	print( vc );
	push_heap( vc.begin(), vc.end() );
	std::cout << "Heap after push_heap(): ";
	print( vc );
}

void pop_heap_example()
{
	std::vector<int> vc{ 40, 10, 20, 50, 30 };

	// making heap
	make_heap( vc.begin(), vc.end() );
	std::cout << "Initial Heap: ";
	print( vc );

	// using pop_heap() function to move the largest element
	// to the end
	pop_heap( vc.begin(), vc.end() );
	std::cout << "Heap after pop_heap(): ";
	print( vc );

	// actually removing the element from the heap using
	// pop_back()
	vc.pop_back();
	std::cout << "Heap after pop_back(): ";
	print( vc );
}

void sort_heap_example()
{
	// Initializing a vector
	std::vector<int> v1 = { 20, 30, 40, 25, 15 };

	// Converting vector into a heap
	// using make_heap()
	make_heap( v1.begin(), v1.end() );

	// Displaying heap elements
	std::cout << "The heap elements are: ";
	for ( int& x : v1 )
		std::cout << x << " ";
	std::cout << std::endl;

	// sorting heap using sort_heap()
	sort_heap( v1.begin(), v1.end() );

	// Displaying heap elements
	std::cout << "The heap elements after sorting are: ";
	for ( int& x : v1 )
		std::cout << x << " ";
}

void is_heap_example()
{
	// Initializing a vector
	std::vector<int> v1 = { 40, 30, 25, 35, 15 };

	// Declaring heap iterator
	std::vector<int>::iterator it1;

	// Checking if container is heap
	// using is_heap()
	is_heap( v1.begin(), v1.end() )
		? std::cout << "The container is heap "
		: std::cout << "The container is not heap"; // ternary operator
	std::cout << std::endl;

	// using is_heap_until() to check position
	// till which container is heap
	auto it = is_heap_until( v1.begin(), v1.end() );

	// Displaying heap range elements
	std::cout << "The heap elements in container are : ";
	for ( it1 = v1.begin(); it1 != it; it1++ )
		std::cout << *it1 << " ";
}

int main()
{
	make_heap_example(); std::cout << std::endl << std::endl;
	push_heap_example(); std::cout << std::endl << std::endl;
	pop_heap_example(); std::cout << std::endl << std::endl;
	sort_heap_example(); std::cout << std::endl << std::endl;
	is_heap_example(); std::cout << std::endl << std::endl;
	return 0;
}
