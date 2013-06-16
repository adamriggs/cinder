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

class Circle {
    
    
public:
    Circle();
    Circle(Vec2f loc);
    void update(float left, float right);
    void draw();
    //float FFT(std::vector<float> x);
    
    float   mRad;
    float   mRadCoeff;
    int     mColor;
    Vec2f   mLocOriginal;
    Vec2f   mLocCurrent;
};