#include <iostream>

class Base
{
public:
	void baseMethod() { std::cout << "Hi!" << std::endl; }
};

class B : public virtual Base // NOTE THE VIRTUAL HERE
{
};

class A : public virtual Base // NOTE THE VIRTUAL HERE
{
};

class C : public  A, public B
{
};

int main()
{
	// The DIAMOND issue in C++ is solved with 'virtual' base class.
	// https://www.geeksforgeeks.org/virtual-base-class-in-c/
	C c;
	c.baseMethod();
	std::cin.get();
	return 0;
}