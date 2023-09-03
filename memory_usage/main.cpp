#include <iostream>
#include <memory>
#include <vector>
#include <array>

#include "GlobalAllocation.h"
#include "Point.h"

int main()
{
	std::cout << "[APP]: Demo 1 started (new Point)..." << std::endl;
	{
		Point* point = new Point;
		float sum = point->x + point->y;
		std::cout << "Sizeof: " << sizeof( point ) << std::endl;
		PrintMemoryUsage();
		delete point;
	}
	PrintMemoryUsage();

	std::cout << std::endl << "[APP]: Demo 2 started (std::make_unique<Point>())..." << std::endl;
	{
		std::unique_ptr<Point> point{ std::make_unique<Point>() };
		float sum = point->x + point->y;
		std::cout << "Sizeof: " << sizeof( point ) << std::endl;
		PrintMemoryUsage();
	}
	PrintMemoryUsage();

	std::cout << std::endl << "[APP]: Demo 3 started (std::make_shared<Point>())..." << std::endl;
	{
		std::shared_ptr<Point> point{ std::make_shared<Point>() };
		float sum = point->x + point->y;
		std::cout << "Sizeof: " << sizeof( point ) << std::endl;
		PrintMemoryUsage();
	}
	PrintMemoryUsage();

	std::cout << std::endl << "[APP]: Demo 4 started (std::vector reserve)..." << std::endl;
	{
		std::vector<Point> points;
		points.reserve( 100 );
		//std::vector<Point> points(100);
		std::cout << "Sizeof: " << sizeof( points ) << std::endl;
		PrintMemoryUsage();
	}
	PrintMemoryUsage();

	std::cout << std::endl << "[APP]: Demo 5 started (new std::array<Point, 10>())..." << std::endl;
	{
		auto points = new std::array<Point, 10>();
		std::cout << "Sizeof: " << sizeof( points ) << std::endl;
		PrintMemoryUsage();
		delete points;
	}
	PrintMemoryUsage();

	std::cout << std::endl << "[APP]: --------------------------" << std::endl;
	std::cout << "[APP]: The remaining demos do not reflect the amount of memory deallocated" << std::endl;
	std::cout << "[APP]: --------------------------" << std::endl;

	std::cout << std::endl << "[APP]: Demo 6 started (std::make_shared<Point[]>(10))..." << std::endl;
	{
		auto points = std::make_shared<Point[]>( 10 );
		PrintMemoryUsage();
	}
	PrintMemoryUsage();

	std::cout << std::endl << "[APP]: Demo 7 started (new Point[10])..." << std::endl;
	{
		Point* points = new Point[10];
		std::cout << "Sizeof: " << sizeof( points ) << std::endl;
		PrintMemoryUsage();
		delete[] points;
	}
	PrintMemoryUsage();

	std::cout << std::endl << "[APP]: Demos finished." << std::endl;
	std::cin.get();
}
