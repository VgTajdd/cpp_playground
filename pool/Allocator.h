#pragma once

//AllocatorChunk:
//- Size
//- Begin / End
//- Alignment

template<typename T, size_t Count = 256>
class AllocatorChunk
{
public:
	AllocatorChunk()
	{
		m_begin = (T*) malloc( sizeof( T ) * Count );

		if ( m_begin == nullptr ) return;

		m_head = m_begin + Count - 1;
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>( m_head );
		if ( ptr != nullptr ) *ptr = 0;

		for ( size_t i = 0; i < Count - 1; i++ )
		{
			auto new_ptr = m_head - 1;
			deallocate( new_ptr );
		}
	}

	~AllocatorChunk()
	{
		if ( m_begin != nullptr )
		{
			free( m_begin );
		}
	}

	T* next( T* object )
	{
		uintptr_t* ptr_value = reinterpret_cast<uintptr_t*>( object );
		return (T*) (void*) ( *ptr_value );
	}

	T* allocate()
	{
		if ( m_head == nullptr ) return nullptr;
		T* head = m_head;
		m_head = next( m_head );
		return head;
	}

	void deallocate( T* object )
	{
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>( object );
		*ptr = (uintptr_t) (void*) m_head;
		m_head = object;
	}

	bool contains( T* object )
	{
		return false;
	}

	AllocatorChunk* next() const { return m_next; }
	void setNext( AllocatorChunk* n ) { m_next = n; }

private:
	T* m_head = nullptr;
	T* m_begin = nullptr;
	AllocatorChunk* m_next = nullptr;
};

template<typename T, size_t ChunkSize = 256>
class Allocator
{
public:
	typedef AllocatorChunk<T, ChunkSize> Chunk;
	Allocator()
	{
		head = new Chunk();
		current = head;
	}

	~Allocator()
	{
		Chunk* nextToDelete = nullptr;
		while ( head != nullptr )
		{
			nextToDelete = head->next();
			delete head;
			head = nextToDelete;
		}
	}

	T* allocate()
	{
		T* allocated = nullptr;
		if ( current != nullptr )
		{
			allocated = current->allocate();
		}
		if ( allocated == nullptr )
		{
			auto newAllocator{ new Chunk() };
			current->setNext( newAllocator );
			current = newAllocator;
			allocated = current->allocate();
		}
		return allocated;
	}

	void deallocate( T* object )
	{
		auto chunk = head;
		while ( chunk != nullptr )
		{
			if ( chunk->contains( object ) )
			{
				chunk->deallocate( object );
				return;
			}
			chunk = chunk->next();
		}
	}

private:
	AllocatorChunk<T, ChunkSize>* current = nullptr;
	AllocatorChunk<T, ChunkSize>* head = nullptr;
};
