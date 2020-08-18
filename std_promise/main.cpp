#if 0

// https://riptutorial.com/cplusplus/example/13552/using-condition-variables

#include <condition_variable>
#include <cstddef>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <thread>

int main()
{
    std::condition_variable cond;
    std::mutex mtx;
    std::queue<int> intq;
    bool stopped = false;

    std::thread producer{ [&]()
    {
        // Prepare a random number generator.
        // Our producer will simply push random numbers to intq.
        //
        std::default_random_engine gen{};
        std::uniform_int_distribution<int> dist{};

        std::size_t count = 4006;
        while ( count-- )
        {
            // Always lock before changing
            // state guarded by a mutex and
            // condition_variable (a.k.a. "condvar").
            std::lock_guard<std::mutex> L{mtx};

            // Push a random int into the queue
            intq.push( dist( gen ) );

            // Tell the consumer it has an int
            cond.notify_one();
        }

        // All done.
        // Acquire the lock, set the stopped flag,
        // then inform the consumer.
        std::lock_guard<std::mutex> L{mtx};

        std::cout << "Producer is done!" << std::endl;

        stopped = true;
        cond.notify_one();
    } };

    std::thread consumer{ [&]()
    {
        do
        {
            std::unique_lock<std::mutex> L{mtx};
            cond.wait( L,[&]()
            {
                // Acquire the lock only if
                // we've stopped or the queue
                // isn't empty
                return stopped || !intq.empty();
            } );

            // We own the mutex here; pop the queue
            // until it empties out.

            while ( !intq.empty() )
            {
                const auto val = intq.front();
                intq.pop();

                std::cout << "Consumer popped: " << val << std::endl;
            }

            if ( stopped )
            {
                // producer has signaled a stop
                std::cout << "Consumer is done!" << std::endl;
                break;
            }

        }
        while ( true );
    } };

    consumer.join();
    producer.join();

    std::cout << "Example Completed!" << std::endl;

    return 0;
}

#endif

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