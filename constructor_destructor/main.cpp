
#include <iostream>
#include <string>

class BaseNamedObject
{
protected:
	std::string m_name;
public:
	BaseNamedObject( const std::string& name ) :
		m_name( name )
	{
		std::cout << "Created BaseObject: " << m_name << std::endl;
	}

	void sayHello()
	{
		std::cout << "Hello!" << std::endl;
	}

	~BaseNamedObject()
	{
		std::cout << "Destroyed BaseObject: " << m_name << std::endl;
	}
};

class DerivedNamedObject : public BaseNamedObject
{
public:
	DerivedNamedObject( const std::string& name ) :
		BaseNamedObject( name )
	{
		std::cout << "Created DerivedObject: " << m_name << std::endl;

	}
	~DerivedNamedObject()
	{
		std::cout << "Destroyed DerivedObject: " << m_name << std::endl;
	}
};

class BaseObject
{
public:
	BaseObject()
	{
		std::cout << "Created BaseObject" << std::endl;
	}

	void sayHello()
	{
		std::cout << "Hello!" << std::endl;
	}

	virtual ~BaseObject()
	{
		std::cout << "Destroyed BaseObject" << std::endl;
	}
};

class DerivedObject : public BaseObject
{
public:
	DerivedObject()
	{
		std::cout << "Created DerivedObject" << std::endl;

	}
	~DerivedObject()
	{
		std::cout << "Destroyed DerivedObject" << std::endl;
	}
};

int main()
{
	{
		BaseObject a;
		DerivedObject b;
	}

	std::cout << std::endl << std::endl;

	{
		BaseObject* heap_object = new DerivedObject();
		delete heap_object; // To destroy not only BaseObject but DerivedObject the BaseObject destructor MUST be virtual.
	}

	std::cout << std::endl << std::endl;

	{
		BaseNamedObject a( "A" );
		DerivedNamedObject b( "B" );
	}

	std::cout << std::endl << std::endl;

	{
		std::unique_ptr<DerivedObject> t = std::make_unique<DerivedObject>();
		t->sayHello();
		//t.release(); // If release is used the managed object is not destroyed.
	} // The managed object is destroyed when the current scope ends.

	std::cout << std::endl << std::endl;

	{
		std::unique_ptr<DerivedObject> t = std::make_unique<DerivedObject>();
		t->sayHello();
		t = nullptr; // This forces the managed object to be destroyed.
	}

	std::cout << std::endl << std::endl;

	{
		std::unique_ptr<DerivedObject> t = std::make_unique<DerivedObject>();
		auto raw_ptr = t.get();
		t->sayHello();
		t.release(); // Use this to releasing new object to unique pointer
		t = std::make_unique<DerivedObject>();
		delete raw_ptr;
	}

	__debugbreak();
	return 0;
}