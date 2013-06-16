//
//  CircleController.h
//  TrigRepeater
//
//  Created by Adam Riggs on 1/29/13.
//
//

#pragma once
#include "Circle.h"
#include "Circle2.h"
#include "cinder/audio/PcmBuffer.h"
#include "cinder/audio/FftProcessor.h"
#include <vector>

class CircleController {
    
public:
    CircleController();
    CircleController(int num);
    void update(const cinder::audio::PcmBuffer32fRef &buffer);
    void draw();
    
    int     mNumCircles;
    int     mCircleStepper;
    
    audio::FftProcessorRef mFftProcessor;
    
    std::vector<Circle> circles;
    std::vector<Circle2> freq;
};
