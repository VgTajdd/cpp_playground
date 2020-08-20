
#include <vector>
#include <iostream>

struct Casa
{
	Casa( const int a = 10 ) : amount( a ), things( new int[a] ) { std::cout << "Casa was built." << std::endl; } // Default ctor.
	Casa( const Casa& other ) : amount( other.amount ), things( new int[other.amount] ) { for ( int i = 0; i < this->amount; i++ ) { things.get()[i] = other.things.get()[i]; } std::cout << "Casa was copied (Deep)." << std::endl; } // Copy ctor (Deep copy).
	Casa( Casa&& other ) { things = std::move( other.things );  this->amount = other.amount; std::cout << "Casa was moved." << std::endl; } // Move ctor.
	//Casa& operator=( const Casa& other ) { std::cout << "Casa was copied with operator." << std::endl; return *this; }
	//Casa& operator=( Casa other ) { std::cout << "Casa was copied with operator." << std::endl; return *this; }
	//void operator=( const Casa& other ) { std::cout << "Casa was copied with operator." << std::endl; }
	void operator=( Casa other ) { this->amount = other.amount; this->things.reset( new int[other.amount] ); for ( int i = 0; i < this->amount; i++ ) { things.get()[i] = other.things.get()[i]; } std::cout << "Casa was copied (Deep) with operator." << std::endl; } // Deep copy.
	std::unique_ptr< int[] > things;
	int amount;
};

int main()
{
	{
		Casa c;
		Casa b;
		c.things.get()[0] = 20;
		b = c;
		std::cout << b.things.get()[0];
	}
	std::cout << std::endl << std::endl;
	{
		// This is the best way to add elements to a vector avoiding reallocation and copies.
		std::vector< Casa > v;
		v.reserve( 3 );
		v.emplace_back();
		v.emplace_back();
		v.emplace_back();
		std::cout << "Capacity: " << v.capacity() << "  Size: " << v.size() << std::endl;
	}
	std::cout << std::endl << std::endl;
	{
		std::vector< Casa* > v;
		v.resize( 3, nullptr );
		v.push_back( new Casa() );
		v.erase( v.begin() + 3 );
		Casa* casa = new Casa();
		v.push_back( std::move( casa ) );
		std::cout << "Capacity: " << v.capacity() << "  Size: " << v.size() << std::endl;
	}
	std::cout << std::endl << std::endl;
	{
		Casa b( 4 );
		b.things.get()[3] = 20;
		Casa c( std::move( b ) );
		std::cout << c.things.get()[3];
	}
	std::cin.get();
	return 0;
}