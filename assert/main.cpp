#include <iostream>

#define ASSERTS_ENABLED 1

#if ASSERTS_ENABLED
#define SIMPLE_ASSERT(x)	if (!(x)) __debugbreak()
#define FULL_ASSERT(x)		if (!(x)) \
							{\
								std::cout << #x << " " << __FILE__ << "[" << __FUNCTION__ <<  "] line: " << __LINE__ << std::endl;\
								__debugbreak();\
							}
#else
#define FULL_ASSERT(x)
#define SIMPLE_ASSERT(x)
#endif

int main()
{
	FULL_ASSERT( false );

	return 0;
}