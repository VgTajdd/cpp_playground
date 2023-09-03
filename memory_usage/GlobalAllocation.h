#pragma once

#include <iostream>

struct AllocationMetrics
{
	size_t totalAllocated = 0;
	size_t totalFreed = 0;

	size_t CurrentUsage() const { return totalAllocated - totalFreed; }
};
static AllocationMetrics s_metrics;

void PrintMemoryUsage()
{
	std::cout << "[MEMORY] Total Memory Used: " << s_metrics.CurrentUsage() << " bytes." << std::endl;
}

void* operator new( size_t size )
{
	auto memory{ malloc( size ) };
	s_metrics.totalAllocated += size;
	std::cout << "[Global] Allocating " << size << " bytes at " << memory << std::endl;
	return memory;
}

void* operator new[]( size_t size )
{
	auto memory{ malloc( size ) };
	s_metrics.totalAllocated += size;
	std::cout << "[Global Array] Allocating " << size << " bytes at " << memory << std::endl;
	return memory;
}

void* operator new ( std::size_t size, const std::nothrow_t& nothrow_constant ) noexcept
{
	auto memory{ malloc( size ) };
	s_metrics.totalAllocated += size;
	std::cout << "[Global noexcept] Allocating " << size << " bytes at " << memory << std::endl;
	return memory;
}

void* operator new[]( size_t size, const std::nothrow_t& nothrow_constant ) noexcept
{
	auto memory{ malloc( size ) };
	s_metrics.totalAllocated += size;
	std::cout << "[Global Array noexcept] Allocating " << size << " bytes at " << memory << std::endl;
	return memory;
}

// This is not replaceable: https://stackoverflow.com/questions/12072182
//void* operator new ( std::size_t size, void* ptr ) noexcept
//{
//	auto memory{ malloc( size ) };
//	s_metrics.totalAllocated += size;
//	std::cout << "[Global] Allocating " << size << " bytes at " << memory << std::endl;
//	return memory;
//}

void operator delete( void* memory )
{
	std::cout << "[Global] Deallocating at " << memory << std::endl;
	free( memory );
}

void operator delete[]( void* memory )
{
	std::cout << "[Global Array] Deallocating at " << memory << std::endl;
	free( memory );
}

void operator delete( void* memory, size_t size )
{
	std::cout << "[Global] Deallocating " << size << " bytes at " << memory << std::endl;
	s_metrics.totalFreed += size;
	free( memory );
}

void operator delete[]( void* memory, size_t size )
{
	std::cout << "[Global Array] Deallocating " << size << " bytes at " << memory << std::endl;
	s_metrics.totalFreed += size;
	free( memory );
}
