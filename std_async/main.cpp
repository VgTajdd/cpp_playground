#include <string>
#include <iostream>
#include <future>

void heavyProcess( const std::string& inputLoad )
{
	for ( unsigned int i = 0; i < 2000000; i++ )
	{
		std::string a( "example" );
	}
	std::cout << "Finished heavyProcess: " << inputLoad.c_str() << std::endl;
}

std::string LoadSomething( const std::string& txt )
{
	heavyProcess( txt );
	return std::string( "loaded_data_" ).append( txt );
}

static std::mutex s_mutex;

static void AsyncLoadSomething( std::vector<std::string>& loadedData, std::string inputLoad )
{
	auto data = LoadSomething( inputLoad );
	std::lock_guard<std::mutex> lock( s_mutex );
	loadedData.push_back( data );
}

void testAsyncLoading( const std::vector<std::string>& inputs, std::vector<std::string>& loadedData )
{
	std::vector<std::future<void>> futures;
	for ( const auto& input : inputs )
	{
		futures.push_back( std::async( std::launch::async, AsyncLoadSomething, std::ref( loadedData ), input ) );
	}
}

int main()
{
	LoadSomething( "demo_process" );

	std::vector<std::string> inputs = { "a", "b", "c", "d", "e", "f", "g", "h" };
	std::vector<std::string> loadedData;

#define ASYNC_LOAD 1
#if ASYNC_LOAD
	testAsyncLoading( inputs, loadedData );
#else
	for ( const auto& input : inputs )
	{
		loadedData.push_back( LoadSomething( input ) );
	}
#endif

	std::cin.get();
	return 0;
}