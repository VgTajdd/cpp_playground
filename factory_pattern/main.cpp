#include "IRenderer.h"
#include "RendererFactory.h"
#include <iostream>

class UserRenderer : public IRenderer
{
public:
	~UserRenderer() {}
	bool LoadScene( const std::string& filename ) { return true; }
	void SetViewportSize( int w, int h ) {}
	void SetCameraPosition( double x, double y, double z ) {}
	void SetLookAt( double x, double y, double z ) {}
	void Render() { std::cout << "User Render" << std::endl; }
	static IRenderer* Create() { return new UserRenderer(); }
};

int main( int, char** )
{
	// Register a new renderer.
	RendererFactory::RegisterRenderer( "user", UserRenderer::Create );
	// Create an instance of our new renderer.
	IRenderer* r = RendererFactory::CreateRenderer( "user" );
	r->Render();
	delete r;
	return 0;
}