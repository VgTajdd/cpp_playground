
// free(): is C method		(Is it necessary to use C in your C++ app?)
// delete: is C++ operator

int main()
{
	int* a = new int[5];
	a[4] = 4;
	int* b = a;

	//free( a );	// It works but is necessary to include stdlib.h
	//free( b );
	//delete a[];		// It works.
	delete[] b;		// It works.

	__debugbreak();

	return 0;
}