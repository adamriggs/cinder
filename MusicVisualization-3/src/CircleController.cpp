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
#include "cinder/audio/FftProcessor.h"

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
    //loc.x=(app::getWindowWidth()-num*density)/2;
    loc.x=0;
    loc.y=app::getWindowHeight()/2;
    
    for(int i=0;i<mNumCircles;i++){
        circles.push_back(Circle(loc));
        loc.x+=density;
    }
    
    loc.x=0;
    loc.y=app::getWindowHeight()-50;
    for(int j=0;j<mNumCircles;j++){
        freq.push_back(Circle2(loc));
        loc.x+=density;
    }
    
    
    mFftProcessor=mFftProcessor->createRef(1);
}

void CircleController::update(const cinder::audio::PcmBuffer32fRef &buffer)
{
    audio::Buffer32fRef leftBuffer = buffer->getChannelData( audio::CHANNEL_FRONT_LEFT );
	audio::Buffer32fRef rightBuffer = buffer->getChannelData( audio::CHANNEL_FRONT_RIGHT );
    
    mFftProcessor->process(leftBuffer->mData);
    //std::cout<<*mFftProcessor->process(leftBuffer->mData)<<"\n";
    //std::cout<<mFftProcessor->getBandCount()<<"\n";
    
    for(int i=0;i<mNumCircles;i++){
        circles[i].update((leftBuffer->mData[i]),(rightBuffer->mData[i]));
        //std::cout<<leftBuffer->mData[i]<<",";
        //std::cout<<i<<"=";
        //std::cout<<*mFftProcessor->process(&leftBuffer->mData[i])<<"\n";
        //std::cout<<leftBuffer->mData[i]<<"\n";
        freq[i].update(*mFftProcessor->process(&leftBuffer->mData[i]));
    }
    
    //mFftProcessor=audio::FftProcessorRef();
    
    //std::cout<<"*****\n";
    
}

void CircleController::draw()
{
    for(int i=0;i<mNumCircles;i++){
        circles[i].draw();
        freq[i].draw();
    }
    
    
}