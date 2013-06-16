#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Ball.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class P0ngApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Ball mBall;
};

void P0ngApp::setup()
{
    Vec2f loc(app::getWindowWidth()/2,app::getWindowHeight()/2);
    mBall=Ball(loc);
    
}

void P0ngApp::mouseDown( MouseEvent event )
{
}

void P0ngApp::update()
{
    mBall.update();
}

void P0ngApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    mBall.draw();
}

CINDER_APP_BASIC( P0ngApp, RendererGl )
