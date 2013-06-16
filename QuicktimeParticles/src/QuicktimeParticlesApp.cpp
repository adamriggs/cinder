#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "ParticleController.h"
#include "cinder/ImageIo.h"
#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/gl/Texture.h"
#include "cinder/Surface.h"
#include "cinder/qtime/QuickTime.h"
#include "cinder/Text.h"
#include "cinder/Utilities.h"

#define RESOLUTION 5

using namespace ci;
using namespace ci::app;
using namespace std;

class QuicktimeParticlesApp : public AppBasic {
public:
    void prepareSettings( Settings *settings );
    void keyDown( KeyEvent event);
    void mouseMove( MouseEvent event );
    void mouseDrag( MouseEvent event );
	void mouseDown( MouseEvent event );
    void fileDrop( FileDropEvent event );
	void setup();
	void update();
	void draw();
    
    void loadMovieFile( const fs::path &path);
    
    Channel32f      mChannel;
	gl::Texture     mTexture, mFrameTexture, mInfoTexture;
    qtime::MovieGl  mMovie;
	
	Vec2i           mMouseLoc;
    
	bool            mDrawParticles;
	bool            mDrawImage;
	
	ParticleController mParticleController;
	
};

void QuicktimeParticlesApp::prepareSettings( Settings *settings )
{
   // settings->setWindowSize( 800, 600 );
	//settings->setFrameRate( 60.0f );
}

void QuicktimeParticlesApp::keyDown( KeyEvent event )
{
    if( event.getChar() == 'f' ) {
		setFullScreen( ! isFullScreen() );
	}
	else if( event.getChar() == 'o' ) {
		fs::path moviePath = getOpenFilePath();
		if( ! moviePath.empty() )
			loadMovieFile( moviePath );
	}
	else if( event.getChar() == '1' )
		mMovie.setRate( 0.5f );
	else if( event.getChar() == '2' )
		mMovie.setRate( 2 );
}

void QuicktimeParticlesApp::mouseMove( MouseEvent event )
{
    mMouseLoc=event.getPos();
}

void QuicktimeParticlesApp::mouseDrag( MouseEvent event )
{
    mouseMove(event);
}

void QuicktimeParticlesApp::setup()
{
    Url url( "http://libcinder.org/media/tutorial/paris.jpg" );
	mChannel = Channel32f( loadImage( loadUrl( url ) ) );
	mTexture = mChannel;
    
	mParticleController = ParticleController( RESOLUTION );
	
	mMouseLoc = Vec2i( 0, 0 );
	
	mDrawParticles = true;
	mDrawImage = false;
    
    fs::path moviePath = getOpenFilePath();
	if( ! moviePath.empty() )
		loadMovieFile( moviePath );
}

void QuicktimeParticlesApp::mouseDown( MouseEvent event )
{
}

void QuicktimeParticlesApp::loadMovieFile(const fs::path &moviePath)
{
    try {
		// load up the movie, set it to loop, and begin playing
		mMovie = qtime::MovieGl( moviePath );
		mMovie.setLoop();
		mMovie.play();
		
		// create a texture for showing some info about the movie
		TextLayout infoText;
		infoText.clear( ColorA( 0.2f, 0.2f, 0.2f, 0.5f ) );
		infoText.setColor( Color::white() );
		infoText.addCenteredLine( moviePath.filename().string() );
		infoText.addLine( toString( mMovie.getWidth() ) + " x " + toString( mMovie.getHeight() ) + " pixels" );
		infoText.addLine( toString( mMovie.getDuration() ) + " seconds" );
		infoText.addLine( toString( mMovie.getNumFrames() ) + " frames" );
		infoText.addLine( toString( mMovie.getFramerate() ) + " fps" );
		infoText.setBorder( 4, 2 );
		mInfoTexture = gl::Texture( infoText.render( true ) );
	}
	catch( ... ) {
		console() << "Unable to load the movie." << std::endl;
		mMovie.reset();
		mInfoTexture.reset();
	}
    
	mFrameTexture.reset();
}

void QuicktimeParticlesApp::fileDrop( FileDropEvent event)
{
    loadMovieFile( event.getFile( 0 ) );
}

void QuicktimeParticlesApp::update()
{
    if( ! mChannel ) return;
    
    if( mMovie )
		mFrameTexture = mMovie.getTexture();
	
    mTexture=mFrameTexture;
    
    //Surface surf(mTexture);
    //mChannel=Channel32f(surf);
    
    
	mParticleController.update( mChannel, mMouseLoc );
}

void QuicktimeParticlesApp::draw()
{
	gl::clear( Color( 0, 0, 0 ), true );
    gl::enableAlphaBlending();
    
	if( mFrameTexture ) {
		Rectf centeredRect = Rectf( mFrameTexture.getBounds() ).getCenteredFit( getWindowBounds(), true );
		gl::draw( mFrameTexture, centeredRect  );
	}
    
	if( mInfoTexture ) {
		glDisable( GL_TEXTURE_RECTANGLE_ARB );
		gl::draw( mInfoTexture, Vec2f( 20, getWindowHeight() - 20 - mInfoTexture.getHeight() ) );
	}
	
	if( mDrawImage ){
		mTexture.enableAndBind();
		gl::draw( mTexture, getWindowBounds() );
	}
	
	if( mDrawParticles ){
		glDisable( GL_TEXTURE_2D );
		mParticleController.draw();
	}
}

CINDER_APP_BASIC( QuicktimeParticlesApp, RendererGl )
