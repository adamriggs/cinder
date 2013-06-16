#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "SquareManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MouseSquaresApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );
    void mouseMove(MouseEvent event);
	void update();
	void draw();
    
    SquareManager sm;
    
    int     res;
    Vec2i   mouseLoc;
};

void MouseSquaresApp::setup()
{
    res=10;
    sm=SquareManager(res);
}

void MouseSquaresApp::mouseDown( MouseEvent event )
{
}

void MouseSquaresApp::mouseMove(MouseEvent event)
{
    mouseLoc=event.getPos();
}

void MouseSquaresApp::update()
{
    
    sm.update(mouseLoc);
}

void MouseSquaresApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    sm.draw();
}

CINDER_APP_BASIC( MouseSquaresApp, RendererGl )
