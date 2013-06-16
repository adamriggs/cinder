#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIO.h"
#include "cinder/gl/Texture.h"
#include "cinder/Perlin.h"
#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/Utilities.h"
#include "ParticleController.h"

#define RESOLUTION 10
#define NUM_PARTICLES_TO_SPAWN 25

using namespace ci;
using namespace ci::app;
using namespace std;

class Sec1Chap4App : public AppBasic {
public:
    void prepareSettings( Settings *settings );
    void keyDown( KeyEvent event );
	void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
    void mouseMove( MouseEvent event );
    void mouseDrag( MouseEvent event );
	void setup();
	void update();
	void draw();
    
    Perlin mPerlin;
    
    Channel32f mChannel;
    gl::Texture mTexture;
    
    Vec2i mMouseLoc;
    Vec2i mMouseVel;
    bool mIsPressed;
    
    ParticleController mParticleController;
    
    bool mDrawParticles;
    bool mDrawImage;
    bool mSaveFrames;
};

void Sec1Chap4App::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60.0f );
}

void Sec1Chap4App::setup()
{
    mPerlin = Perlin();
    
    Url url("http://libcinder.org/media/tutorial/paris.jpg");
    mChannel = Channel32f( loadImage( loadUrl( url ) ) );
    mTexture = mChannel;
    
    mMouseLoc = Vec2i( 0, 0 );
    mMouseVel = Vec2f::zero();
    mDrawParticles = true;
    mDrawImage = false;
    mIsPressed = false;
    mSaveFrames = false;
}

void Sec1Chap4App::mouseDown( MouseEvent event )
{
    mIsPressed = true;
}

void Sec1Chap4App::mouseUp( MouseEvent event )
{
    mIsPressed = false;
}

void Sec1Chap4App::mouseMove( MouseEvent event )
{
    mMouseVel = (event.getPos() - mMouseLoc );
    mMouseLoc = event.getPos();
}

void Sec1Chap4App::mouseDrag( MouseEvent event )
{
    mouseMove( event );
}

void Sec1Chap4App::keyDown( KeyEvent event )
{
    
    if( event. getChar() == '1' ){
        mDrawImage = !mDrawImage;
    } else if ( event.getChar() == '2' ){
        mDrawParticles = !mDrawParticles;
    }
    
    if( event.getChar() == 's' ){
        mSaveFrames = !mSaveFrames;
    }
}

void Sec1Chap4App::update()
{
    if(!mChannel) return;
    
    if( mIsPressed )
        mParticleController.addParticles(NUM_PARTICLES_TO_SPAWN, mMouseLoc, mMouseVel );
    
    mParticleController.update( mPerlin, mChannel, mMouseLoc );
}

void Sec1Chap4App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    if( mDrawImage ){
        mTexture.enableAndBind();
        gl::draw( mTexture, getWindowBounds() );
    }
    
    if( mDrawParticles ){
        glDisable( GL_TEXTURE_2D );
        mParticleController.draw();
    }
    
    if( mSaveFrames ){
        writeImage( getHomeDirectory() / ("image_" + toString(getElapsedFrames() ) + ".png"), copyWindowSurface() );
    }
}

CINDER_APP_BASIC( Sec1Chap4App, RendererGl )
