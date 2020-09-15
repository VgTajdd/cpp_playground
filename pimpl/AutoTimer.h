#ifndef AUTO_TIMER_H_
#define AUTO_TIMER_H_

#include <string>
#include <memory>

class AutoTimer
{
public:
	explicit AutoTimer( const std::string& name );
	~AutoTimer();

	void constMethod() const;

private:
	// Make this object be non copyable (only if using raw pointer)
	/*AutoTimer( const AutoTimer& );
	AutoTimer& operator=(const AutoTimer&);*/

	class Impl;
	// Benefits of using unique_ptr over raw pointer:
	// 1) RAII 2) make object non copyable.
	std::unique_ptr<Impl> m_impl;
};

#endif