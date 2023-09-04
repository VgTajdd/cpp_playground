#pragma once

#include <iostream>

#include "Allocator.h"

enum class EventType
{
	None,
	WindowClose,
	WindowResize,
	WindowFocus,
	WindowLostFocus,
	WindowMoved,

	AppTick,
	AppUpdate,
	AppRender,

	KeyPressed,
	KeyReleased,
	KeyTyped,

	MouseButtonPressed,
	MouseButtonReleased,
	MouseMoved,
	MouseScrolled
};

class Event
{
	//public:
	//	explicit Event( EventType type );
	//	virtual ~Event();
	//
	//	Event( const Event& other );
	//	Event& operator=( const Event& other );
	//
	//	Event( Event&& other );
	//	Event& operator=( Event&& rhs );
	//
	//	void setup();
	//	EventType type() const;
	//	const char* name() const;
	//	bool handled() const;
	//	void setHandled( const bool handled );
	//	bool isMouseEvent() const;
	//	bool isKeyboardEvent() const;
private:
	class EventPimpl* m_pimpl;
};

class EventPimpl
{
public:
	explicit EventPimpl( const Event* reference, EventType type ) :
		m_eventRef( reference ),
		m_type( type )
	{
	}
	//void setup();
	//EventType type() const { return m_type; }
	//const char* name() { return m_name.c_str(); }
	//bool handled() const { return m_handled; }
	//void setHandled( const bool handled ) { m_handled = handled; };
	//bool isMouseEvent() const { return m_isMouseEvent; }
	//bool isKeyboardEvent() const { return m_isKeyboardEvent; }

	void* operator new( size_t size )
	{
		return allocator.allocate();
	}

	void operator delete( void* e )
	{
		allocator.deallocate( (EventPimpl*)e );
	}

private:
	EventType m_type;
	std::string m_name; // use small strings->events( avoid strings allocation )
	bool m_handled = false;
	const Event* m_eventRef;
	bool m_isMouseEvent = false;
	bool m_isKeyboardEvent = false;

	static Allocator<EventPimpl> allocator;
};

Allocator<EventPimpl> EventPimpl::allocator;

#define PRINT_TYPE_DETAILS(type) std::cout << #type << ": size= " << sizeof( type ) << " bytes, alignment= " << alignof( type ) << " bytes." << std::endl;
