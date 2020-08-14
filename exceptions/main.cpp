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

    std::cout << "----------------" << std::endl;
    std::cout << "Exception safety" << std::endl;
    std::cout << "----------------" << std::endl;

    // https://en.cppreference.com/w/cpp/language/try_catch

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