#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/imageIO.h"
#include "GridController.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TrigGridApp : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
    void mouseMove( MouseEvent event );
	void update();
	void draw();
    
    Channel32f      mChannel;
    gl::Texture     mTexture;
    
    int res;
    Vec2i mouseLoc;
    
    GridController gc;
};

void TrigGridApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize(640,629);
    settings->setFrameRate(60.0f);
}

void TrigGridApp::setup()
{
    mChannel=Channel32f(loadImage(loadResource("einstein-and-his-therapist.jpg")));
    mTexture=mChannel;
    
    res=10;
    gc=GridController(res);
}

void TrigGridApp::mouseDown( MouseEvent event )
{
}

void TrigGridApp::mouseMove( MouseEvent event)
{
    mouseLoc=event.getPos();
}

void TrigGridApp::update()
{
    gc.update(mouseLoc, mChannel);
}

void TrigGridApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
   // gl::draw(mTexture);
    gc.draw();
}

CINDER_APP_BASIC( TrigGridApp, RendererGl )
