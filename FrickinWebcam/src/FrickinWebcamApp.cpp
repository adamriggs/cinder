#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/Capture.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class FrickinWebcamApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Capture         mCam;
    gl::Texture     mTexture;
    gl::GlslProg    mShader;
    
};

void FrickinWebcamApp::setup()
{
    mCam=Capture(640,480);
    mCam.start();
    
    mShader=gl::GlslProg(loadAsset("vert.glsl"),loadAsset("frag.glsl"));
    
}

void FrickinWebcamApp::mouseDown( MouseEvent event )
{
    cout<<"You clicked at "<<event.getPos()<<endl;
}

void FrickinWebcamApp::update()
{
    if(mCam.checkNewFrame()){
        mTexture=gl::Texture(mCam.getSurface());
    }
}

void FrickinWebcamApp::draw()
{
	// clear out the window with black
	gl::clear( Color( .5, .6, .6 ) );
    
    //gl::color(1.0f,0.0f,0.0f);
    mShader.bind();
    mShader.uniform("tex0",0);
    if(mTexture)
        gl::draw(mTexture);
}

CINDER_APP_BASIC( FrickinWebcamApp, RendererGl )
