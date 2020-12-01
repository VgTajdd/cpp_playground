#include "rendererfactory.h"

#include "IRenderer.h"

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

std::unique_ptr<IRenderer> RendererFactory::CreateRenderer( const std::string& type )
{
	std::unique_ptr<IRenderer> ptr;

	CallbackMap::iterator it = m_renderers.find( type );
	if ( it != m_renderers.end() )
	{
		// Call the creation callback to construct this derived type.
		ptr = it->second();
	}

	return ptr;
}