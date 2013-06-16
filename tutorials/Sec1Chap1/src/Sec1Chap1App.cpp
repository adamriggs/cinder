#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "ParticleController.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Sec1Chap1App : public AppBasic {
    
    gl::Texture mImage;
    float x;
    float y;
    
  public:
    void prepareSettings(Settings *settings);
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    ParticleController mParticleController;
};

void Sec1Chap1App::prepareSettings(Settings *settings)
{
    settings->setWindowSize(800,600);
    settings->setFrameRate(60.0f);
    
    mParticleController.addParticles(1000);
}

void Sec1Chap1App::setup()
{
    
    
   //mImage=gl::Texture(loadImage(loadUrl("http://i.imgur.com/gYtAJ.jpg")));
    
    mImage=gl::Texture(loadImage(loadResource("image.jpg")));
    
}

void Sec1Chap1App::mouseDown( MouseEvent event )
{
}

void Sec1Chap1App::update()
{
    mParticleController.update();
}

void Sec1Chap1App::draw()
{
	// clear out the window with black
	//gl::clear( Color( 0, 0, 0 ) );
    if(mImage)
    gl::draw(mImage,getWindowBounds());
    
    x=(cos(getElapsedSeconds())*100);
    y=(sin(getElapsedSeconds())*100);
    
    gl::drawSolidCircle(Vec2f(x,y)+getWindowSize()/2,abs(x));
    
    mParticleController.draw();
}

CINDER_APP_BASIC( Sec1Chap1App, RendererGl )
