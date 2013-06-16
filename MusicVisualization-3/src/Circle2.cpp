//
//  Circle.cpp
//  TrigRepeater
//
//  Created by Adam Riggs on 1/29/13.
//
//

#include "Circle2.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include <vector>


Circle2::Circle2()
{
}

Circle2::Circle2(Vec2f loc)
{
    mLocOriginal= loc;
    mLocCurrent = loc;
    mRad        = 1.0f;
    mRadCoeff   = 3.0f;
}

void Circle2::update(float amp)
{
    mLocCurrent.y=mLocOriginal.y+(10*log(10*amp*amp));
}

void Circle2::draw()
{
    gl::drawSolidCircle(mLocCurrent,mRad);
}