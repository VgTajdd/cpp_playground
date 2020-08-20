#include <iostream>

/*
An exception is an error condition.
*/

double division( int a, int b )
{
    if ( b == 0 )
    {
        throw std::exception( "Division by zero condition!" );
    }
    return ( a / b );
}

class Entity
{
public:
    Entity()
    {
        std::cout << "Entity created!" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Entity destroyed!" << std::endl;
    }
};

class A
{
public:
    A() {};
    ~A() noexcept( false ) // Destructors are by defualt noexecpt, so this ('noexcept(false)') will turn-off the compiler warning.
    {
        throw std::exception{}; // AVOID THROW EXCEPTIONS OUT OF DESTRUCTORS because destructors are called
                                // during stack unwinding when an exception is thrown,
                                // and we are not allowed to throw another exception while the previous one is
                                // not caught – in such a case std::terminate will be called.
                                // http://www.vishalchovatiya.com/7-best-practices-for-exception-handling-in-cpp-with-example/
    }
};

struct base
{
    ~base() noexcept( false ) { throw 1; }
};
struct derive : base
{
    ~derive() noexcept( false ) { throw 2; }
};

// Custom exception.
struct MyException : public std::exception
{
    const char* what() const throw ( )
    {
        return "Custom exception";
    }
};

int main()
{
    // Simple example.
    {
        try
        {
            throw 20;
        }
        catch ( int e )
        {
            std::cout << "An exception occurred! Exception: " << e << std::endl;
        }
    }

    // https://en.cppreference.com/w/cpp/language/try_catch
    {
        try
        {
            division( 10, 0 );
        }
        catch ( const std::overflow_error& /*e*/ )
        {
            // this executes if division() throws std::overflow_error (same type rule)
        }
        catch ( const std::runtime_error& /*e*/ )
        {
            // this executes if division() throws std::underflow_error (base class rule)
        }
        catch ( const std::exception& e )
        {
            std::cout << e.what() << std::endl;     // this executes if division() throws std::exception (same type rule)
                                                    // this executes if division() throws std::logic_error (base class rule)
        }
        catch ( ... )
        {
            std::cout << "An exception occurred!" << std::endl; // this executes if division() throws std::string or int or any other unrelated type
        }
    }

    // Exceptions in destructors.
    {
        try
        {
            A a;
        }
        catch ( ... ) {}
    }

#if 0
    // An exception will be thrown when the object d will be destroyed as a result of RAII.
    // But at the same time destructor of base will also be called as it is sub - object of derive
    // which will again throw an exception.Now we have two exceptions at the same time which
    // is invalid scenario & std::terminate will be called.
    {
        try
        {
            derive a;
        }
        catch ( ... ) {}
    }
#endif

    std::cout << "----------------" << std::endl;
    std::cout << "Exception safety" << std::endl;
    std::cout << "----------------" << std::endl;

    // This code is exception safe.
    {
        try
        {
            std::unique_ptr< Entity > entity = std::make_unique< Entity >();
            throw std::exception( "Custom exception!" );
            // The destructor of Entity is called when scope ends.
        }
        catch ( ... )
        {
            // Code to handle the exception.
        }
    }

    std::cout << "----------------" << std::endl;

    // This code is no exception safe.
    {
        try
        {
            Entity* entity = new Entity;
            throw std::exception( "Custom exception!" );
            delete entity; // This won't be called!
        }
        catch ( ... )
        {
            // Code to handle the exception.
        }
    }

    std::cin.get();

    return 0;
}