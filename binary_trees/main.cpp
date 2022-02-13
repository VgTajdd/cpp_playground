#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node( const int d ) :data( d ),
		left( nullptr ),
		right( nullptr )
	{}

	void insert( const int d )
	{
		if ( d <= data )
		{
			if ( left == nullptr )
			{
				left = new Node( d );
			}
			else
			{
				left->insert( d );
			}
		}
		else
		{
			if ( right == nullptr )
			{
				right = new Node( d );
			}
			else
			{
				right->insert( d );
			}
		}
	}
};

/**
 * @brief Level order traversal of a tree.
 * @param root Root of the tree.
 * @return void
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
void levelOrder( Node* root )
{
	if ( root == nullptr ) return;

	vector<Node*> roots, children;

	roots.push_back( root );
	while ( roots.size() != 0 )
	{
		for ( const auto& r : roots )
		{
			if ( r->left )children.push_back( r->left );
			if ( r->right )children.push_back( r->right );

			cout << r->data << " ";
		}

		roots.clear();
		for ( const auto& c : children )
		{
			roots.push_back( c );
		}
		children.clear();
	}
}

int height( Node* root )
{
	if ( root )
		return 1 + std::max( height( root->left ), height( root->right ) );
	else
		return -1;
}

void print( const std::string& prefix, const Node* node, bool isLeft )
{
	if ( node != nullptr )
	{
		std::cout << prefix;

		std::cout << ( isLeft ? "|--" : "|--" );

		// print the value of the node
		std::cout << node->data << std::endl;

		// enter the next tree level - left and right branch
		print( prefix + ( isLeft ? "|   " : "    " ), node->left, true );
		print( prefix + ( isLeft ? "|   " : "    " ), node->right, false );
	}
}

void print( const Node* node )
{
	print( "", node, false );
}

int main()
{

	Node* root = new Node( 5 );
	root->insert( 2 );
	root->insert( 4 );
	root->insert( 6 );
	root->insert( 7 );

	cout << "Level order traversal of the tree is: " << endl;
	levelOrder( root );

	cout << endl << "Height of the tree is: " << height( root ) << endl;

	cout << endl << "Tree: " << endl;
	print( root );

	std::cin.get();
	return 0;
}
