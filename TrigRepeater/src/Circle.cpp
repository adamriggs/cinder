//
//  Circle.cpp
//  TrigRepeater
//
//  Created by Adam Riggs on 1/29/13.
//
//

#include "Circle.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"


Circle::Circle()
{
}

Circle::Circle(Vec2f loc)
{
    mLocOriginal= loc;
    mLocCurrent = loc;
    mRad        = 3.0f;
    mRadCoeff   = 3.0f;
}

void Circle::update()
{
    mRad=sin(app::getElapsedSeconds()*mLocOriginal.x) * mRadCoeff;
    mLocCurrent.y=cos(app::getElapsedSeconds()*mLocOriginal.y)*mRadCoeff+app::getWindowHeight()/2;
}

void Circle::draw()
{
    gl::drawSolidCircle(mLocCurrent,mRad);
}