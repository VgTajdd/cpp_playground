#include "rendererfactory.h"

// Instantiate the static variable in RendererFactory.
RendererFactory::CallbackMap RendererFactory::m_renderers;

void RendererFactory::RegisterRenderer( const std::string& type, CreateCallback cb )
{
	m_renderers[type] = cb;
}

void RendererFactory::UnregisterRenderer( const std::string& type )
{
	m_renderers.erase( type );
}

IRenderer* RendererFactory::CreateRenderer( const std::string& type )
{
	CallbackMap::iterator it = m_renderers.find( type );
	if ( it != m_renderers.end() )
	{
		// Call the creation callback to construct this derived type.
		return it->second();
	}
	return NULL;
}