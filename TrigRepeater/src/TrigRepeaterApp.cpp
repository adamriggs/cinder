#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "CircleController.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TrigRepeaterApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    CircleController cc;
};

void TrigRepeaterApp::setup()
{
    cc=CircleController(100);
}

void TrigRepeaterApp::mouseDown( MouseEvent event )
{
}

void TrigRepeaterApp::update()
{
    
    cc.update();
}

void TrigRepeaterApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    cc.draw();
}

CINDER_APP_BASIC( TrigRepeaterApp, RendererGl )
