#include <iostream>

template<size_t S>
void returnProductArray( int first[], int( &second )[S] ) // O(N^2)
{
	for ( size_t i = 0; i < S; i++ )
	{
		for ( size_t j = 0; j < S; j++ )
		{
			if ( i == 0 )
				second[j] = 1;

			if ( i != j )
			{
				second[j] *= first[i];
			}
		}
	}
}

template<size_t S>
void returnProductArray2( int A[], int( &B )[S] ) // O(N)
{
	// Set prod to the neutral multiplication element
	int prod = 1;

	for ( int i = 0; i < S; ++i )
	{
		// For element "i" set B[i] to A[0] * ... * A[i - 1]
		B[i] = prod;
		// Multiply with A[i] to set prod to A[0] * ... * A[i]
		prod *= A[i];
	}

	// Reset prod and use it for the right elements
	prod = 1;

	for ( int i = S - 1; i >= 0; --i )
	{
		// For element "i" multiply B[i] with A[i + 1] * ... * A[S - 1]
		B[i] *= prod;
		// Multiply with A[i] to set prod to A[i] * ... * A[S - 1]
		prod *= A[i];
	}
}

//--------------------------------------------------------

template<typename D, typename B>
class IsDerivedFromHelper
{
	class No {};
	class Yes { No no[3]; };

	static Yes Test( B* );
	static No Test( ... );
public:
	enum { Is = sizeof( Test( static_cast<D*>( 0 ) ) ) == sizeof( Yes ) };

};

template <class C, class P>
bool IsDerivedFrom()
{
	return IsDerivedFromHelper<C, P>::Is;
}

//--------------------------------------------------------

template <typename T, typename U>
struct is_same
{
	static const bool value = false;
};

template <typename T>
struct is_same<T, T>
{
	static const bool value = true;
};

template <class A, class B>
bool IsSameClass()
{
	return is_same<A, B>::value;
}

//--------------------------------------------------------

int main()
{
	int a[] = { 2, 1, 5, 9 };
	int b[] = { 1,1,1,1 };
	returnProductArray( a, b );
	returnProductArray2( a, b );
	for ( int i = 0; i < 4; i++ ) std::cout << b[i] << " ";
	std::cin.get();
	return 0;
}