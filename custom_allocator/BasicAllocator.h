#pragma once

// #include <cstdlib>
// #include <new>
// #include <limits>

#ifdef _DEBUG
#define PRINT_ACTIVITY
#endif

#ifdef PRINT_ACTIVITY
#include <iostream>
#endif

template<class T>
struct BasicAllocator
{
	typedef T value_type;

	BasicAllocator() = default;

	template<class U>
	constexpr BasicAllocator( const BasicAllocator <U>& ) noexcept {}

	[[nodiscard]] T* allocate( std::size_t n )
	{
		if ( n > std::numeric_limits<std::size_t>::max() / sizeof( T ) )
			throw std::bad_array_new_length();

		if ( auto p = static_cast<T*>( std::malloc( n * sizeof( T ) ) ) )
		{
			report( p, n );
			return p;
		}

		throw std::bad_alloc();
	}

	void deallocate( T* p, std::size_t n ) noexcept
	{
		report( p, n, 0 );
		std::free( p );
	}
private:
	void report( T* p, std::size_t n, bool alloc = true ) const
	{
#ifdef PRINT_ACTIVITY
		std::cout << ( alloc ? "Alloc: [" : "Dealloc: [" ) << n << " elements " << typeid( T ).name() << "] " << sizeof( T ) * n
			<< " bytes at " << std::hex << std::showbase
			<< reinterpret_cast<void*>( p ) << std::dec << '\n';
#endif
	}
};

template<class T, class U>
bool operator==( const BasicAllocator <T>&, const BasicAllocator <U>& ) { return true; }

template<class T, class U>
bool operator!=( const BasicAllocator <T>&, const BasicAllocator <U>& ) { return false; }
