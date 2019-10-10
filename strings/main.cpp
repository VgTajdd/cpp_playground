#include <iostream>

int main()
{
	{
		auto default_typed_var_1 = "HolaAgustin"; // By default when it has double quoutes it's treates as const char*

		// Using '' instead of "".
		auto default_typed_var_2 = 'H'; // By default char (size of char is 1 byte).
		auto default_typed_var_3 = 'Ho'; // By default int (size of int is 4 bytes).
		auto default_typed_var_4 = 'Holx'; // By default int (size of int is 4 bytes).
		//auto default_typed_var_5 = 'Holax'; // Wrong because it can't be created int with 5 bytes.

		char c = default_typed_var_4; // c takes byte corresponding to the first byte of default_typed_var_4.
		int ic = 'x';
		wchar_t c2 = default_typed_var_4; // It is printed as int.
		int ic2 = 'lx';
		std::cout << default_typed_var_1 << " - " << sizeof( default_typed_var_1 ) << " - " << strlen( default_typed_var_1 ) << std::endl;
		std::cout << ic << " - " << c << " - " << sizeof( c ) << std::endl;
		std::cout << ic2 << " - " << c2 << " - " << sizeof( c2 ) << std::endl;

		__debugbreak();
	}

	{
		char a[5] = "Hola"; // It's correct because this is the same as creating the variable as normal char array, this way : char a[] = {'H', 'o', 'l', 'a', '\0'} or char a[5] = {'H', 'o', 'l', 'a', '\0'} (with null terminator)
		char b[] = "Hola";
		char c[4] = { 'H', 'o', 'l', 'a' }; // Here there's no null at the end.
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << sizeof( a ) << ", " << strlen( a ) << std::endl;
		std::cout << sizeof( b ) << ", " << strlen( b ) << std::endl;
		std::cout << sizeof( c ) << ", " << strlen( c ) << std::endl;

		__debugbreak();
	}

	{
		const char* example1 = "Hola";
		const char* example2 = R"(Hola
								que
								hace
								)";
		const char* name1 = u8"Hola";
		const wchar_t* name2 = L"Hola";

		const char16_t* name3 = u"Hola";
		const char32_t* name4 = U"Hola";

		/*
		Bad usage example: It will only compile if "Conformance mode" is disabled (set value to No).
		*/
		char* test = "aaaa"; // Don't do this, test points to address const value. It only compiles if "Conformance mode" is disabled.
		test[1] = 'x'; // Crash in Debug.
		std::cout << test; // In release is printed "aaaa" instead of "axaa"

		__debugbreak();
	}

	return 0;
}