//
//  CircleController.cpp
//  TrigRepeater
//
//  Created by Adam Riggs on 1/29/13.
//
//

#include "CircleController.h"
#include "cinder/app/App.h"
#include "cinder/audio/PcmBuffer.h"

CircleController::CircleController()
{
}

CircleController::CircleController(int num)
{
    mNumCircles=num;
    mCircleStepper=0;
    
    int density;
    density=1;
    
    Vec2f loc;
    loc.x=(app::getWindowWidth()-num*density)/2;
    loc.y=app::getWindowHeight()/2;
    
    for(int i=0;i<mNumCircles;i++){
        circles.push_back(Circle(loc));
        loc.x+=density;
    }
}

void CircleController::update(const cinder::audio::PcmBuffer32fRef &buffer)
{
    audio::Buffer32fRef leftBuffer = buffer->getChannelData( audio::CHANNEL_FRONT_LEFT );
	audio::Buffer32fRef rightBuffer = buffer->getChannelData( audio::CHANNEL_FRONT_RIGHT );
    
    for(int i=0;i<mNumCircles;i++){
        circles[i].update((leftBuffer->mData[i]*100)+app::getWindowHeight()/2);
        
        //std::cout<<leftBuffer->mData[i]<<"\n";
    }
//
//    circles[mCircleStepper].update();
//    mCircleStepper++;
//    if(mCircleStepper>=mNumCircles){
//        mCircleStepper=0;
//    }
}

void CircleController::draw()
{
    for(int i=0;i<mNumCircles;i++){
        circles[i].draw();
    }
    
    
}