#include <iostream>

#include <memory>

class Entity
{
public:
	Entity( const char* name ) : m_name( name )
	{
		std::cout << "Created Entity : " << m_name << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity : " << m_name << std::endl;
	}
	void doSomething()
	{
		std::cout << m_name << " doing something... " << std::endl;
	}
private:
	const char* m_name;
};

int main()
{
	//-------------- Unique pointer --------------//

	// First way to create a unique pointer.
	{
		// This way to create shared pointer is exception safe.
		std::unique_ptr< Entity > entity = std::make_unique< Entity >( "E1" );
	}
	// Alternative ways to create a unique pointer.
	{
		std::unique_ptr< Entity > entity;
		entity.reset( new Entity( "E2" ) ); // Destroy the old object (if exists) and owns the new one.

		std::unique_ptr< Entity > anotherEntity( new Entity( "E3" ) );
	}
	// To point and onw another object unique_ptr first destroy the old object (if exists).
	{
		std::unique_ptr< Entity > entityA = std::make_unique< Entity >( "EA" );
		entityA.reset( new Entity( "EB" ) ); // Destroy the old object (if exists) and owns the new one.
		entityA = std::make_unique< Entity >( "EC" ); // Destroy the old object (if exists) and owns the new one.
	}
	// Unique pointer can be released.
	{
		std::unique_ptr< Entity > entity;
		entity = std::make_unique< Entity >( "E4" );

		entity->doSomething();

		// Unique pointer can be released.
		Entity* releasedPtr = entity.release();
		releasedPtr->doSomething();

		// Must delete the released raw pointer.
		delete releasedPtr;
	}
	// This pointer is only movable.
	{
		std::unique_ptr< Entity > entity = std::make_unique< Entity >( "E5" );
		std::unique_ptr< Entity > anotherEntity = std::move( entity );
	}
	// Inappropriate use - Don't do this!
	{
		Entity* entityPtr = new Entity( "E6" );
		{
			std::unique_ptr< Entity > entity( entityPtr );
		}

		// Undefined behaviour, E6 was already deleted. If the method requires to access data
		// already deleted, a exception of Access violation will be thrown.
		/*entityPtr->doSomething();*/
	}

	std::cout << "-----------------------" << std::endl;

	//-------------- Shared pointer --------------//

	// It has a control block that is heap-allocated with the object.

	// First way to create a shared pointer.
	{
		// This way to create shared pointer is exception safe.
		auto entity = std::make_shared< Entity >( "E1" );
	}
	// Alternative way to create shared pointer.
	{
		std::shared_ptr< Entity > entity( new Entity( "E2" ) ); // No exception safe.
	}
	// This pointer is copyable and movable.
	{
		auto entity = std::make_shared< Entity >( "E3" );
		std::cout << entity.use_count() << std::endl; // 1
		std::shared_ptr< Entity > anotherEntityPtr = entity;
		std::cout << entity.use_count() << std::endl; // 2

		// The scope ends, so the shared pointers in this scope are removed from the stack
		// and that will decrease by 1 (for each shared_ptr)
		// the ref-counter in the control block.
		// If the ref-counter is 0 the object is destroyed.
	}

	{
		std::shared_ptr< Entity > theSameEntity;
		{
			auto entity = std::make_shared< Entity >( "E4" );
			std::cout << entity.use_count() << std::endl; // 1
			theSameEntity = entity;
			std::cout << theSameEntity.use_count() << std::endl; // 2

			// Entity is created in this scope but keeps alive even is the scope ends.
			// It's because new pointer is created and ref-counter in the control block is 2.
		}
		std::cout << theSameEntity.use_count() << std::endl; // 1
		// Here the entity is destroyed.
	}

	std::cout << "-----------------------" << std::endl;

	//-------------- Weak pointer --------------//

	// std::weak_ptr is a smart pointer that holds a non-owning ("weak") reference
	// to an object that is managed by std::shared_ptr.
	// It must be converted to std::shared_ptr in order to access the referenced object.
	// https://en.cppreference.com/w/cpp/memory/weak_ptr

	// std::weak_ptr are created from shared_ptr.
	{
		auto entity = std::make_shared< Entity >( "E1" );
		std::cout << entity.use_count() << std::endl; // 1
		std::weak_ptr< Entity > weak_entity = entity;
		// The ref-counter in the shared_ptr control block is not increased after
		// creating a weak_ptr using copy constructor.
		std::cout << entity.use_count() << std::endl; // 1
		if ( !weak_entity.expired() )
			weak_entity.lock()->doSomething();
	}

	// Example 1:
	{
		std::weak_ptr< Entity > weakEntity;
		std::shared_ptr< Entity > anotherSharedPtr;
		{
			auto entity = std::make_shared< Entity >( "E2" );
			std::cout << entity.use_count() << std::endl; // 1
			weakEntity = entity;
			if ( !weakEntity.expired() )
				anotherSharedPtr = weakEntity.lock();
			std::cout << entity.use_count() << std::endl; // 2
		}
		std::cout << anotherSharedPtr.use_count() << std::endl; // 1
		anotherSharedPtr->doSomething();
	}

	// Example 2:
	{
		std::weak_ptr< Entity > weakEntity;
		{
			auto entity = std::make_shared< Entity >( "E3" );
			weakEntity = entity;
			if ( !weakEntity.expired() )
				weakEntity.lock()->doSomething();
		}
		if ( !weakEntity.expired() )
			weakEntity.lock()->doSomething();
	}

	// Recomendations:
	// - Create allways smart pointers using : std::make_unique and std::make_shared (Exception safe).
	//   Avoid this:
	//   - std::unique_ptr< Entity > entity = std::make_unique< Entity >( new Entity( "E1" ) );
	//   - entity.reset( new Entity( "E2" ) );
	//   - std::shared_ptr< Entity > entity( new Entity( "E2" ) );

	std::cin.get();

	return 0;
}