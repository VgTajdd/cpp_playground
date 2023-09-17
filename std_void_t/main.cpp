#include <iostream>
#include <utility>

namespace vgt_std
{
#ifdef _MSC_VER
template< class ... > using void_t = void;

#else

// fix for gcc:
// see http://stackoverflow.com/a/25833474/3087952

template< class ... >
struct make_void
{
	typedef void type;
};

template< class ... T >
using void_t = typename make_void< T... >::type;
#endif
}

template< class T, class = void >
struct has_member : std::false_type // Primary Class Template
{
};

// specialized as has_member< T , void > or discarded (sfinae)
template< class T >
//struct has_member< T, std::void_t< decltype( T::member ) > > : std::true_type // Specialized Class Template
struct has_member< T, vgt_std::void_t< decltype( T::member ) > > : std::true_type // Specialized Class Template
{
};

class A
{
public:
	int member;
};

class B
{
};

int main()
{
	std::cout << "A has 'member' = " << std::boolalpha << has_member< A >::value << std::endl;
	std::cout << "B has 'member' = " << std::boolalpha << has_member< B >::value << std::endl;

	return 0;
}
