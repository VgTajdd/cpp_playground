#pragma once

#include <iostream>

struct Point
{
	Point()
	{
		std::cout << "Point Created" << std::endl;
	}
	~Point()
	{
		std::cout << "Point Destroyed" << std::endl;
	}

	float x = 100.f, y = 100.f;

	void* operator new( size_t size )
	{
		auto memory{ ::operator new( size ) };
		std::cout << "[Point] Allocating " << size << " bytes at " << memory << std::endl;
		return memory;
	}

	void* operator new[]( size_t size )
	{
		auto memory{ ::operator new[]( size ) };
		std::cout << "[Point Array] Allocating " << size << " bytes at " << memory << std::endl;
		return memory;
	}

	void operator delete( void* memory )
	{
		std::cout << "[Point] Deallocating at " << memory << std::endl;
		::operator delete( memory, sizeof( Point ) );
	}

	void operator delete( void* memory, size_t size )
	{
		std::cout << "[Point] Deallocating " << size << " bytes at " << memory << std::endl;
		::operator delete( memory, size );
	}

	void operator delete[]( void* memory )
	{
		std::cout << "[Point Array] Deallocating at " << memory << std::endl;
		::operator delete[]( memory );
	}

	void operator delete[]( void* memory, size_t size )
	{
		std::cout << "[Point Array] Deallocating " << size << " bytes at " << memory << std::endl;
		::operator delete[]( memory, size );
	}
};
