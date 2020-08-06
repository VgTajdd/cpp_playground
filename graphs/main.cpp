#include <iostream>
#include <vector>

struct Node
{
	Node( const int _i ) : id( _i ) {}
	int id;
	std::vector<Node*> neighboors;

	void addNeighboor( Node* n )
	{
		neighboors.push_back( n );
		n->neighboors.push_back( this ); // Comment for not-directed graphs.
	}
};

struct Graph
{
	std::vector<Node*> nodes;
	void addNode( Node* node )
	{
		nodes.push_back( node );
	}
};

int main()
{
	Node* n1 = new Node( 1 );
	Node* n2 = new Node( 2 );
	Node* n3 = new Node( 3 );
	Node* n4 = new Node( 4 );
	Node* n5 = new Node( 5 );

	Graph g;
	g.addNode( n1 );
	g.addNode( n2 );
	g.addNode( n3 );
	g.addNode( n4 );
	g.addNode( n5 );

	n1->addNeighboor( n2 );
	n2->addNeighboor( n3 );
	n3->addNeighboor( n4 );
	n4->addNeighboor( n5 );
	n2->addNeighboor( n4 );

	std::cin.get();

	return 0;
}