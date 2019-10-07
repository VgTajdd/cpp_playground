#include <iostream>
#include <chrono>
#include <thread>

struct Timer
{
	std::chrono::time_point< std::chrono::steady_clock> start, end;
	std::chrono::duration< float > duration;

	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	// ~ : ALT + 126
	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.0f;
		std::cout << "Timer alive: " << ms << " ms" << std::endl;
	}
};

void Function()
{
	Timer timer;

	for ( int i = 0; i < 100; i++ )
	{
		std::cout << "Hello" << std::endl;
	}
}

void Function2()
{
	Timer timer;

	for ( int i = 0; i < 500; i++ )
	{
		std::cout << "abcdef ";
	}

	std::cout << std::endl;
}

int main()
{
	{
		Timer t;
		using namespace std::literals::chrono_literals;
		std::this_thread::sleep_for( 1s );
	}

	Function();

	Function2();

	std::cin.get();
}