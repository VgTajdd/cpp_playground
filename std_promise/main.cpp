#include <future>
#include <iostream>
using namespace std;

class Foo
{
private:
    std::promise<void> p1;
    std::promise<void> p2;

public:
    void first( function<void()> printFirst )
    {
        printFirst();
        p1.set_value();
    }

    void second( function<void()> printSecond )
    {
        p1.get_future().wait();
        printSecond();
        p2.set_value();
    }

    void third( function<void()> printThird )
    {
        p2.get_future().wait();
        printThird();
    }
};

void printFirst()
{
    cout << "printFirst()" << endl;
}

void printSecond()
{
    cout << "printSecond()" << endl;
}

void printThird()
{
    cout << "printThird()" << endl;
}

int main( int argc, char** argv )
{
    Foo foo;

    thread t1( &Foo::first, &foo, printFirst );
    thread t2( &Foo::second, &foo, printSecond );
    thread t3( &Foo::third, &foo, printThird );

    t3.join();
    t1.join();
    t2.join();

    return 0;
}