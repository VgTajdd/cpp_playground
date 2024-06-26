#include <iostream>

// FIRST WAY:

// To handle base case of below recursive Variadic function Template.
void print0()
{
    std::cout << "I am empty function and "
        "I am called at last.\n";
}

// Variadic function Template that takes variable number of arguments and prints all of them.
template <typename T, typename... Types>
void print0( T var1, Types... var2 )
{
    std::cout << var1 << '\n';

    print0( var2... );
}

// SECOND WAY:

template <typename T>
void print1( T var )
{
    std::cout << var << '\n';
}

template <typename T, typename... Types>
void print1( T var1, Types... var2 )
{
    std::cout << var1 << '\n';

    print1( var2... );
}

int main()
{
    std::cout << " ---- TEST 1 ----\n";

    print0( 1, 2, 3.14, "Pass me any "
           "number of arguments",
           "I will print" );

    std::cout << "\n\n ---- TEST 2 ----\n";

    print1( 1, 2, 3.14, "Pass me any "
            "number of arguments",
            "I will print" );

    std::cin.get();
    return 0;
}
