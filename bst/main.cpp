#include <vector>
#include <iostream>

struct Node
{
	Node( const int _value, Node* _left = nullptr, Node* _right = nullptr ) :
		value( _value ), left( _left ), right( _right ) {};
	int value;
	Node* left;
	Node* right;
};

struct BST
{
	BST() : head( nullptr ), countNodes( 0 ) {}
	int countNodes;
	Node* head;
	bool insert( int value )
	{
		if ( head == nullptr )
		{
			head = new Node( value );
			countNodes++;
			return true;
		}

		Node* current = head;
		while ( current != nullptr )
		{
			if ( current->value == value )
			{
				return false;
			}
			if ( current->value > value )
			{
				if ( current->left == nullptr )
				{
					current->left = new Node( value );
				}
				else
				{
					current = current->left;
				}
			}
			else
			{
				if ( current->right == nullptr )
				{
					current->right = new Node( value );
				}
				else
				{
					current = current->right;
				}
			}
		}
		return true;
	}
	std::vector< int > bft()
	{
		std::vector< int > visitedNodes;

		std::vector< Node* > queue;
		if ( head != nullptr )
		{
			queue.insert( queue.begin(), head );
		}

		while ( !queue.empty() )
		{
			if ( queue.back()->left )
			{
				queue.insert( queue.begin(), queue.back()->left );
			}
			if ( queue.back()->right )
			{
				queue.insert( queue.begin(), queue.back()->right );
			}

			visitedNodes.push_back( queue.back()->value );
			queue.pop_back();
		}
		return visitedNodes;
	}
};

int main()
{
	BST t;
	t.insert( 5 );
	t.insert( 1 );
	t.insert( 4 );
	t.insert( 3 );
	t.insert( 2 );
	t.insert( 7 );

	auto traversal = t.bft();
	for ( auto n : traversal )
	{
		std::cout << n << " ";
	}

	std::cin.get();
}