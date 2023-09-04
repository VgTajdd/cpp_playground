#include "Event.h"
#include "Allocator.h"

int main()
{
	PRINT_TYPE_DETAILS( EventType );
	PRINT_TYPE_DETAILS( std::string );
	PRINT_TYPE_DETAILS( const Event* );
	PRINT_TYPE_DETAILS( bool );
	PRINT_TYPE_DETAILS( short );
	PRINT_TYPE_DETAILS( EventPimpl );

	/*
	EventType: size= 4 bytes, alignment= 4 bytes.
	std::string: size= 40 bytes, alignment= 8 bytes.
	const Event*: size= 8 bytes, alignment= 8 bytes.
	bool: size= 1 bytes, alignment= 1 bytes.
	short: size= 2 bytes, alignment= 2 bytes.
	EventPimpl: size= 72 bytes, alignment= 8 bytes.
	*/

	{
		{
			AllocatorChunk<EventPimpl> allocatorChunk;
			auto a = allocatorChunk.allocate();
			auto b = allocatorChunk.allocate();
			auto c = allocatorChunk.allocate();
			auto d = allocatorChunk.allocate();
			allocatorChunk.deallocate(a);
			allocatorChunk.deallocate(b);
			allocatorChunk.deallocate(c);
			allocatorChunk.deallocate(d);
		}

		{
			Allocator<EventPimpl> allocator;
			auto a = allocator.allocate();
			auto b = allocator.allocate();
			auto c = allocator.allocate();
			auto d = allocator.allocate();
			allocator.deallocate( a );
			allocator.deallocate( b );
			allocator.deallocate( c );
			allocator.deallocate( d );
		}

		{
			auto e = new EventPimpl( nullptr, EventType::AppRender );
			delete e;
		}
	}

	std::cin.get();
	return 0;
}
