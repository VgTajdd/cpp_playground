#include <iostream>
#include <queue>

// Reference: https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

// Implementation of priority queue
void showPq( std::priority_queue<int> gq )
{
	std::priority_queue<int> g = gq;
	while ( !g.empty() )
	{
		std::cout << ' ' << g.top();
		g.pop();
	}
	std::cout << '\n';
}

// Driver Code
int main()
{
	std::priority_queue<int> pq;
	// used in inserting the element
	pq.push( 10 );
	pq.push( 30 );
	pq.push( 20 );
	pq.push( 5 );
	pq.push( 1 );

	// used for highlighting the element
	std::cout << "The priority queue pq is : ";
	showPq( pq );

	// used for identifying the size // of the priority queue
	std::cout << "\npq.size() : " << pq.size();
	// used for telling the top element in priority queue
	std::cout << "\npq.top() : " << pq.top();
	// used for identifying the empty status of priority queue
	std::cout << "\npq.empty() : " << pq.empty();

	// used for popping the element from a priority queue
	std::cout << "\npq.pop() : ";
	pq.pop();
	showPq( pq );

	return 0;
}
