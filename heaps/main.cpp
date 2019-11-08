// C++ program for building Heap from Array

#include <iostream>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void heapify( int arr[], int n, int i )
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if ( l < n && arr[l] > arr[largest] )
		largest = l;

	// If right child is larger than largest so far
	if ( r < n && arr[r] > arr[largest] )
		largest = r;

	// If largest is not root
	if ( largest != i )
	{
		swap( arr[i], arr[largest] );

		// Recursively heapify the affected sub-tree
		heapify( arr, n, largest );
	}
}

// Function to build a Max-Heap from the given array
void buildHeap( int arr[], int n )
{
	// Index of last non-leaf node
	int startIdx = ( n / 2 ) - 1;

	// Perform reverse level order traversal
	// from last non-leaf node and heapify
	// each node
	for ( int i = startIdx; i >= 0; i-- )
	{
		heapify( arr, n, i );
	}
}

// A utility function to print the array
// representation of Heap
void printHeap( int arr[], int n )
{
	cout << "Array representation of Heap is:\n";

	for ( int i = 0; i < n; ++i )
		cout << arr[i] << " ";
	cout << "\n";
}

void replaceInHeap( int arr[], int n, int newValue )
{
	if ( newValue >= arr[0] )
	{
		return;
	}
	arr[0] = newValue;
	heapify( arr, n, 0 );
}

// Find the lower k values in array using a heap
void getKLowestValues( int arr[], const int n, int values[], const int k )
{
	if ( k == 1 )
	{
		arr[0] = 0; // Linear search, tc O(n).
		return;
	}

	std::copy( arr, arr + k, values );
	buildHeap( values, k ); // Max Heap

	for ( int i = k; i < n; i++ )
	{
		replaceInHeap( values, k, arr[i] );
	}
}

// Driver Code
int main()
{
	// Binary Tree Representation
	// of input array
	//              1
	//           /     \
	//        3         5
	//      /    \     /  \
	//     4      6   13  10
	//    / \    / \
	//   9   8  15 17
	int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

	int n = sizeof( arr ) / sizeof( arr[0] );

	buildHeap( arr, n );

	printHeap( arr, n );
	// Final Heap:
	//              17
	//           /      \
	//         15         13
	//       /    \      /  \
	//      9      6    5   10
	//     / \    /  \
	//    4   8  3    1


	std::cout << std::endl << std::endl;

	int arr2[] = { 2, 10, 1, 0, 3, 4, 9, 1 };
	n = sizeof( arr2 ) / sizeof( arr[0] );
	const int countValues = 3;
	int values[countValues];
	getKLowestValues( arr2, n, values, countValues );

	std::cin.get();

	return 0;
}