#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/DisplayList.h"
#include "cinder/gl/Texture.h"
#include "cinder/Capture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CubeCamApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    gl::DisplayList     mCube;
    int                 mCubeWidth;
    int                 mCubeHeight;
    gl::Texture         mTexture;
    Capture             mCam;
    
    Matrix44f           mCubeRotation;
    
    unsigned int        textureObject;
    
};

void CubeCamApp::setup()
{
    //cube
    mCubeWidth=320.0f;
    mCubeHeight=240.0f;
    mCube=gl::DisplayList(GL_COMPILE);
    mCube.newList();
    gl::drawCube(Vec3f(0.0f,0.0f,0.0f), Vec3f(mCubeWidth,mCubeHeight,mCubeWidth));
    mCube.endList();
    mCube.getModelMatrix().translate(Vec3f(app::getWindowWidth()/2,app::getWindowHeight()/2,0));
    //mCubeRotation=Matrix44f;
    mCubeRotation.setToIdentity();
    
    //cam
    mCam=Capture(mCubeWidth,mCubeHeight);
    mCam.start();
}

void CubeCamApp::mouseDown( MouseEvent event )
{
}

void CubeCamApp::update()
{
    mCube.getModelMatrix().rotate(Vec3f(0.0f,0.1f,0.0f),0.005f);
    if(mCam.checkNewFrame()){
        mTexture=gl::Texture(mCam.getSurface());
        
       //mTexture.bind();
    }
    
    
}

void CubeCamApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    if(!mTexture)
        return;
    
    
    //mTexture.bind();
    glGenTextures(1, &textureObject);
    glBindTexture(GL_TEXTURE, textureObject);
    gl::draw(mTexture);
    mCube.draw();
}

CINDER_APP_BASIC( CubeCamApp, RendererGl )
