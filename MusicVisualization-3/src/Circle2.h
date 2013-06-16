//
//  Circle.h
//  TrigRepeater
//
//  Created by Adam Riggs on 1/29/13.
//
//

#pragma once
#include "cinder/Vector.h"
#include <vector>

using namespace ci;

class Circle2{
    
    
public:
    Circle2();
    Circle2(Vec2f loc);
    void update(float amp);
    void draw();
    
    float   mRad;
    float   mRadCoeff;
    int     mColor;
    Vec2f   mLocOriginal;
    Vec2f   mLocCurrent;
};