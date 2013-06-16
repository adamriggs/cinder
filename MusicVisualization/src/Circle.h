//
//  Circle.h
//  TrigRepeater
//
//  Created by Adam Riggs on 1/29/13.
//
//

#pragma once
#include "cinder/Vector.h"

using namespace ci;

class Circle {
    
    
public:
    Circle();
    Circle(Vec2f loc);
    void update(float y);
    void draw();
    
    float   mRad;
    float   mRadCoeff;
    Vec2f   mLocOriginal;
    Vec2f   mLocCurrent;
};