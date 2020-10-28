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
	CREATE_METHOD( UserRenderer )
};

int main( int, char** )
{
	RF_REGISTER_RENDERER( UserRenderer ) // Register a new renderer.
	IRenderer* r =  RF_CREATE_RENDERER( UserRenderer ) // Create an instance of our new renderer.
	r->Render();
	delete r;
	return 0;
}