#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "ParticleController.h"

#define TOTAL_PARTICLES 4800
#define RESOLUTION 1

using namespace ci;
using namespace ci::app;
using namespace std;

class Sec1Chap1App : public AppBasic {
    
    gl::Texture mImage;
    float x;
    float y;
    
public:
	void prepareSettings( Settings *settings );
	void keyDown( KeyEvent event );
	void setup();
	void update();
	void draw();
	
	Channel32f mChannel;
	gl::Texture	mTexture;
	
	ParticleController mParticleController;
	
	bool mDrawParticles;
	bool mDrawImage;
};

void Sec1Chap1App::prepareSettings(Settings *settings)
{
    settings->setWindowSize(800,600);
    settings->setFrameRate(60.0f);
    
    //mParticleController.addParticles(4800);
}

void Sec1Chap1App::setup()
{
    
    
    //mImage=gl::Texture(loadImage(loadUrl("http://i.imgur.com/gYtAJ.jpg")));
    
    mImage=gl::Texture(loadImage(loadResource("image.jpg")));
    
    mChannel = Channel32f(mImage);
	mTexture = mChannel;
    
	mParticleController = ParticleController( RESOLUTION );
	
	mDrawParticles = true;
	mDrawImage = false;
    
}

void Sec1Chap1App::keyDown( KeyEvent event )
{
    if( event.getChar() == '1' ){
		mDrawImage = ! mDrawImage;
	} else if( event.getChar() == '2' ){
		mDrawParticles = ! mDrawParticles;
	}
}

void Sec1Chap1App::update()
{
    if( ! mChannel ) return;
	
	mParticleController.update( mChannel );
}

void Sec1Chap1App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    if(mImage)
   // gl::draw(mImage,getWindowBounds());
    
    //x=(cos(getElapsedSeconds())*100);
    //y=(sin(getElapsedSeconds())*100);
    
    //gl::drawSolidCircle(Vec2f(x,y)+getWindowSize()/2,abs(x));
    
    //mParticleController.draw();
    
    if( mDrawImage ){
		mTexture.enableAndBind();
		gl::draw( mTexture, getWindowBounds() );
	}
	
	if( mDrawParticles ){
		glDisable( GL_TEXTURE_2D );
		mParticleController.draw();
	}
}

CINDER_APP_BASIC( Sec1Chap1App, RendererGl )
