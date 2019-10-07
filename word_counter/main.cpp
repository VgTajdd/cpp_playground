#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

static std::string readFile( const std::string& filepath )
{
	std::ifstream stream( filepath );
	std::string line;
	std::stringstream ss;

	while ( getline( stream, line ) )
	{
		ss << line << std::endl;
	}
	return ss.str();
}

static void trimString( std::string& str, const bool left )
{
	if ( str.empty() ) return;

	size_t position = str.size() - 1;
	int increment = -1;
	if ( left )
	{
		position = 0;
		increment = 0;
	}

	while ( str[position] == ' ' || str[position] == '\n' )
	{
		str.erase( str.begin() + position );
		position += increment;
	}
}

static const size_t findFirstChar( const std::string& str, const std::string& chars )
{
	size_t index = std::string::npos;
	for ( const auto& c : chars )
	{
		size_t t_index = str.find( c );
		if ( t_index != std::string::npos )
		{
			if ( index == -1 || t_index < index )
			{
				index = t_index;
			}
		}
	}
	return index;
}

static const int countWords( const std::string& str )
{
	unsigned int count = 0;
	std::string temp_string = str;
	trimString( temp_string, true );
	trimString( temp_string, false );

	while ( !temp_string.empty() )
	{
		size_t index = findFirstChar( temp_string, " .,\n" );

		if ( index == 0 )
		{
			temp_string.erase( temp_string.begin() );
		}
		else if ( index != std::string::npos )
		{
			temp_string.erase( temp_string.begin(), temp_string.begin() + index + 1 );
			count++;
		}
		else
		{
			count++;
			break;
		}
	}
	return count;
}

int main()
{
	std::string text = readFile( "Text.txt" );
	std::cout << text << std::endl;
	std::cout << "The text has: " << countWords( text ) << " words." << std::endl;
	std::cin.get();
	return 0;
}