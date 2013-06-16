#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "CircleController.h"
#include "cinder/audio/Io.h"
#include "cinder/audio/Output.h"
#include "cinder/audio/FftProcessor.h"
#include "cinder/audio/PcmBuffer.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MusicVisualizationApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    void drawWaveForm();
    
    audio::TrackRef mTrack;
    audio::PcmBuffer32fRef mPcmBuffer;
    
    CircleController cc;
    
};

void MusicVisualizationApp::setup()
{
    mTrack=audio::Output::addTrack(audio::load(loadResource(RES_SONG)));
    
    mTrack->enablePcmBuffering(true);
    
    cc=CircleController(1024);
}

void MusicVisualizationApp::mouseDown( MouseEvent event )
{
}

void MusicVisualizationApp::update()
{
    mPcmBuffer = mTrack->getPcmBuffer();
    if(!mPcmBuffer)return;
    cc.update(mPcmBuffer);
}

void MusicVisualizationApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    glPushMatrix();
    cc.draw();
    
    //drawWaveForm();
}

void MusicVisualizationApp::drawWaveForm()
{
    if(!mPcmBuffer) return;
    
    //uint32_t bufferLength = mPcmBuffer->getSampleCount();
    //std::cout<<bufferLength<<"\n";
    
}

CINDER_APP_BASIC( MusicVisualizationApp, RendererGl )
