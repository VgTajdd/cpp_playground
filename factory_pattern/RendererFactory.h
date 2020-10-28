#ifndef RENDERER_FACTORY_H_
#define RENDERER_FACTORY_H_

#include <map>
#include <string>

class IRenderer;

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

#define CREATE_METHOD( Typename )			static IRenderer* Create() { return new Typename(); }
#define RF_REGISTER_RENDERER( Typename )	RendererFactory::RegisterRenderer( #Typename, Typename::Create );
#define RF_CREATE_RENDERER( Typename )		RendererFactory::CreateRenderer( #Typename );

#endif // !RENDERER_FACTORY_H_