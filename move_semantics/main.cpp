#include <iostream>

class String
{
public:
	String( const char* data = nullptr ) : // CONSTRUCTOR
		m_size( 0 ),
		m_data( nullptr )
	{
		if ( data == nullptr )
		{
			printf( "Created empty String\n" );
			return;
		}

		m_size = strlen( data );
		m_data = new char[m_size + 1];
		memcpy( m_data, data, m_size );
		m_data[m_size] = '\0';

		printf( "Created String: '%s'\n", m_data );
	}

	String( const String& other ) // COPY CONSTRUCTOR
	{
		m_size = other.m_size;
		m_data = new char[m_size + 1];
		memcpy( m_data, other.m_data, m_size );
		m_data[m_size] = '\0';

		printf( "[CONSTRUCTOR] Copied String: '%s'\n", m_data );
	}

	String( String&& other ) // MOVE CONSTRUCTOR
	{
		m_size = other.m_size;
		m_data = other.m_data;

		other.m_data = nullptr;
		other.m_size = 0;

		printf( "[CONSTRUCTOR] Moved String: '%s'\n", m_data );
	}

	~String() // DESTRUCTOR
	{
		clear();

		printf( "Destroyed String\n" );
	}

	void clear()
	{
		if ( m_data != nullptr )
		{
			delete[] m_data;
			m_data = nullptr;
		}
		m_size = 0;
	}

	String& operator=( const String& other ) // COPY ASSIGNMENT OPERATOR
	{
		if ( this != &other )
		{
			clear();

			m_size = other.m_size;
			m_data = new char[m_size + 1];
			memcpy( m_data, other.m_data, m_size );
			m_data[m_size] = '\0';

			printf( "[OPERATOR] Copied String: '%s'\n", m_data );
		}
		return *this;
	}

	String& operator=( String&& other ) noexcept // MOVE ASSIGNMENT OPERATOR
	{
		if ( this != &other )
		{
			clear();

			m_size = other.m_size;
			m_data = other.m_data;

			other.m_data = nullptr;
			other.m_size = 0;

			printf( "[OPERATOR] Moved String: '%s'\n", m_data );
		}
		return *this;
	}

	void print()
	{
		for ( size_t i = 0; i < m_size; i++ ) printf( "%c", m_data[i] );
		printf( "\n" );
	}

private:
	char* m_data;
	size_t m_size;
};

class Entity
{
public:
	Entity( const String& name ):
		m_name( name )
	{ }

	Entity( String&& name ) :
		m_name( std::move( name ) )
	{ } 

	void printName()
	{
		m_name.print();
	}
private:
	String m_name;
};

int main()
{
	{
		Entity vgt( "VGT" );
		vgt.printName();
	}

	// Move constructor.
	{
		String A = "A";
		String B = std::move( A ); // <> String B( std::move( A ) ) <> String B((String&&)A)
	}

	// Move assignment operator.
	{
		String C = "C";
		String D;
		D = std::move( C );
		C.print();
		D.print();
	}

	// Copy assignment operator.
	{
		String E = "E";
		String F;
		F = E;
	}

	String nullstr;

	char msg[] = "Hi, there!";
	String m( msg );

	std::cin.get();
}