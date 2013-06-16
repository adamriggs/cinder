//
//  Ball.h
//  P0ng
//
//  Created by Adam Riggs on 1/25/13.
//
//

#pragma once
#include "cinder/Vector.h"
#include "cinder/Color.h"

#include <vector>

class Ball{
public:
    Ball();
    Ball(ci::Vec2f);
    void update();
    void draw();
    
    ci::Vec2f   mLoc;
    ci::Vec2f   mDir;
    ci::Vec2f   mVel;
    float       mRad;
    
};
