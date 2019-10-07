#include <iostream>

struct Entity
{
	int x, y;

	int* GetPositions()
	{
		return &x;
	}
};

int main()
{
	char char1 = 0;
	int a = 50;
	double value = *(double*) &a;

	Entity e = { 5, 8 };

	int* position_ = e.GetPositions();
	position_[0] = 3;

	int* position = (int*) &e;

	std::cout << position[0] << ", " << position[1] << std::endl;

	int y = *(int*)( (char*)&e + 4 );
	std::cout << y << std::endl;

	std::cin.get();
}