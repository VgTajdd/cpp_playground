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

	int height( Node* root )
	{
		// Write your code here.
		if ( root == nullptr )
		{
			return 0;
		}
		auto h_l = height( root->left );
		auto h_r = height( root->right );
		return 1 + ( ( h_l > h_r ) ? h_l : h_r );
	}

	int height()
	{
		return height( this->head );
	}

	// Breath first traversal.

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

	// Depth first traversals.

	std::vector< int > getTraversal( const int type )
	{
		std::vector< int > sortedArray;
		switch ( type )
		{
			case 0: preorder( this->head, sortedArray ); break;
			case 1: inorder( this->head, sortedArray ); break;
			case 2: postorder( this->head, sortedArray ); break;
		}
		return sortedArray;
	}
private:
	void inorder( Node* node, std::vector< int >& buffer )
	{
		if ( node == nullptr )
		{
			return;
		}
		inorder( node->left, buffer );
		buffer.push_back( node->value );
		inorder( node->right, buffer );
	}

	void preorder( Node* node, std::vector< int >& buffer )
	{
		if ( node == nullptr )
		{
			return;
		}
		buffer.push_back( node->value );
		preorder( node->left, buffer );
		preorder( node->right, buffer );
	}

	void postorder( Node* node, std::vector< int >& buffer )
	{
		if ( node == nullptr )
		{
			return;
		}
		postorder( node->left, buffer );
		postorder( node->right, buffer );
		buffer.push_back( node->value );
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

	std::cout << "Height of tree: " << t.height() << std::endl;

	auto traversal = t.bft();
	for ( auto n : traversal )
	{
		std::cout << n << " ";
	}

	std::cout << std::endl;

	auto sortedArray = t.getTraversal( 1 );
	for ( auto n : sortedArray )
	{
		std::cout << n << " ";
	}

	std::cin.get();
}