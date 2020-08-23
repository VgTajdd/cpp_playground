#include "AutoTimer.h"
#include <iostream>
#include <thread>

int main()
{
	{
		AutoTimer timer( "Tick-Tack" );

		AutoTimer timer2( "Timer2" );

		// It's no possible to generate shallow copies of this object because
		// m_impl is non copyable.
		//timer2 = timer;

		std::this_thread::sleep_for( std::chrono::milliseconds( 1500 ) );
	}
	std::cin.get();
}