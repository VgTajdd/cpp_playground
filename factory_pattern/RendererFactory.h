#pragma once

#include "IRenderer.h"
#include <map>

class RendererFactory
{
public:
	typedef IRenderer* ( *CreateCallback )( void );
	static void RegisterRenderer( const std::string& type, CreateCallback cb );
	static void UnregisterRenderer( const std::string& type );
	static IRenderer* CreateRenderer( const std::string& type );
private:
	typedef std::map<std::string, CreateCallback> CallbackMap;
	static CallbackMap m_renderers;
};
