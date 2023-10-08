#include <iostream>
#include <format>

// This source file shows a tutorial of how to use std_format.
// This source file requires compiler support for C++20.
// This source file is associated with the following blog post: https://geeksforgeeks.org/cpp-20-std-format/

int main()
{
	// Example 1 : Basic usage
	{
		std::cout << std::format("Hello, {}!", "world") << std::endl;
	}

	// Example 2:
	{
		// Declare variables
		int num = 42;
		std::string name = "John";

		// Use std::format to format a string with placeholders
		// for variables
		std::string formatted_str = std::format( "My name is {} and my favorite number is {}", name, num );

		// Print formatted string to console
		std::cout << formatted_str << std::endl;
	}

	// Example 3:
	{
		// Declare variables
		int num = 42;
		std::string name = "John";

		// Use std::format to format a string with placeholders
		// for variables
		std::string formatted_str = std::format( "My name is {1} and my favorite number is {0}", num, name );

		// Print formatted string to console
		std::cout << formatted_str << std::endl;
	}

	// Example 4:
	{
		// Declare and initialize a double variable.
		double num = 3.14159;

		// Declare and initialize a string variable.
		std::string name = "John";

		// Format a string with two placeholders, one for a
		// double and another for a string. The first
		// placeholder formats the double with two decimal
		// places and the second placeholder truncates the
		// string to two characters.
		std::string formatted_str = std::format( "My name is {1:.2s} and pi is {0:.2f}", num, name );

		// Print the formatted string to the console.
		std::cout << formatted_str << std::endl;
	}

	// Example 5: Format a string with a width of 10
	{
		std::cout << std::format("Hello, {:10}!", "world") << std::endl;
	}

	// Example 6: Format a string with a width of 10 and left alignment
	{
		std::cout << std::format("Hello, {:<10}!", "world") << std::endl;
	}

	// Example 7: Format a string with a width of 10 and right alignment
	{
		std::cout << std::format("Hello, {:>10}!", "world") << std::endl;
	}

	// Example 8: Format a string with a width of 10 and center alignment
	{
		std::cout << std::format("Hello, {:^10}!", "world") << std::endl;
	}

	// Example 9: Format a string with a width of 10 and center alignment with a fill character
	{
		std::cout << std::format("Hello, {:_^10}!", "world") << std::endl;
	}

	// Example 10: Format numbers
	{
		std::cout << std::format("The answer is {:d}", 42) << std::endl;
	}

	return 0;
}
