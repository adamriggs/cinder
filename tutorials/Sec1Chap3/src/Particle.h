//
//  Particle.h
//  Sec1Chap1
//
//  Created by Adam Riggs on 1/18/13.
//
//

#pragma once
#include "cinder/Channel.h"
#include "cinder/Vector.h"

#include <vector>

class Particle {
public:
    Particle();
    Particle(ci::Vec2f);
    void update( const ci::Channel32f &channel, const ci::Vec2i &mouseLoc );
    void draw();
    
    ci::Vec2f   mLoc;
    ci::Vec2f   mDir;
    float       mVel;
    float       mRadius;
    float       mScale;
    
    cinder::Vec2i   mDirToCursor;
};
