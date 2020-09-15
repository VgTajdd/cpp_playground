#include "autotimer.h"

#include <iostream>

// Platform detection using preprocessor directives.
#ifdef _WIN32
#define UVR_PLATFORM_WINDOWS
#endif

#ifdef UVR_PLATFORM_WINDOWS
#include <windows.h>
#else
#include <sys/time.h>
#endif

class AutoTimer::Impl
{
public:
	double GetElapsed() const
	{
#ifdef UVR_PLATFORM_WINDOWS
		return ( GetTickCount() - m_startTime ) / 1e3;
#else
		struct timeval end time;
		gettimeofday( &end time, NULL );
		double t1 m_startTime.tv usec / 1e6 þ m_startTime.tv sec;
		double t2 end time.tv usec / 1e6 þ end time.tv sec;
		return t2 t1;
#endif
	}
	std::string m_name;
#ifdef UVR_PLATFORM_WINDOWS
	DWORD m_startTime;
#else
	struct timeval m_startTime;
#endif
};

AutoTimer::AutoTimer( const std::string& name ) :
	m_impl( std::make_unique<AutoTimer::Impl>() )
{
	m_impl->m_name = name;
#ifdef UVR_PLATFORM_WINDOWS
	m_impl->m_startTime = GetTickCount();
#else
	gettimeofday( &m_impl->m_startTime, NULL );
#endif
}

// Your compiler will only check that you don’t change the value of the m_impl
// pointer in a const method, but not whether you change any members pointed to by m_impl.
void AutoTimer::constMethod() const
{
	m_impl->m_name = "string changed by a const method";
}

AutoTimer::~AutoTimer()
{
	std::cout << m_impl->m_name << ": took " << m_impl->GetElapsed() << " secs" << std::endl;
}