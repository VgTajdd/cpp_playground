#ifndef RENDERER_FACTORY_H_
#define RENDERER_FACTORY_H_

#include <map>
#include <string>
#include <memory>

class IRenderer;

class RendererFactory
{
public:
	typedef std::unique_ptr<IRenderer> ( *CreateCallback )( void );
	static void RegisterRenderer( const std::string& type, CreateCallback cb );
	static void UnregisterRenderer( const std::string& type );
	static std::unique_ptr<IRenderer> CreateRenderer( const std::string& type );
private:
	typedef std::map<std::string, CreateCallback> CallbackMap;
	static CallbackMap m_renderers;
};

#define CREATE_METHOD( Typename )			static std::unique_ptr<IRenderer> Create() { return std::make_unique<Typename>(); }
#define RF_REGISTER_RENDERER( Typename )	RendererFactory::RegisterRenderer( #Typename, Typename::Create );
#define RF_CREATE_RENDERER( Typename )		RendererFactory::CreateRenderer( #Typename );

#endif // !RENDERER_FACTORY_H_