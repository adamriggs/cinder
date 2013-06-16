//
//  Circle.h
//  TrigGrid
//
//  Created by Adam Riggs on 1/29/13.
//
//

#pragma once

#include "cinder/app/App.h"

using namespace ci;

class Circle{
public:
    Circle();
    Circle(const cinder::Vec2i &loc);
    void update(const Vec2i &mouseLoc, const Channel32f &channel);
    void draw();
    
    Vec2f       mLoc;
    Vec2f       mMouseLoc;
    Vec2f       mDir;
    Vec2f       mDirToCursor;
    
    float       mRadius;
    float       mScale;
    Color       mColor;
    
};