struct
{
	int a : 4;
	int b : 13;
	int c : 1;
} test1;

struct
{
	short a : 4;
	short b : 3;
} test2;

struct
{
	char a : 4;
	char b : 3;
} test3;

struct
{
	char a : 4;
	short b : 3;
} test4;

#include <stdio.h>

int main()
{
	printf( "test1: %d\ntest2: %d\ntest3: %d\ntest4: %d\n",
		( int )sizeof( test1 ),
		( int )sizeof( test2 ),
		( int )sizeof( test3 ),
		( int )sizeof( test4 ) );

	return 0;
}