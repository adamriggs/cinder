//
//  CircleController.h
//  TrigRepeater
//
//  Created by Adam Riggs on 1/29/13.
//
//

#pragma once
#include "Circle.h"
#include "cinder/audio/PcmBuffer.h"
#include <vector>

class CircleController {
    
public:
    CircleController();
    CircleController(int num);
    void update(const cinder::audio::PcmBuffer32fRef &buffer);
    void draw();
    
    int     mNumCircles;
    int     mCircleStepper;
    
    std::vector<Circle> circles;
};
