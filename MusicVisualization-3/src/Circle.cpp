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
#include <vector>


Circle::Circle()
{
}

Circle::Circle(Vec2f loc)
{
    mLocOriginal= loc;
    mLocCurrent = loc;
    mRad        = 1.0f;
    mRadCoeff   = 3.0f;
    mColor      = 0;
}

void Circle::update(float left, float right)
{
    //mRad=sin(app::getElapsedSeconds()*mLocOriginal.x) * mRadCoeff;
    //mLocCurrent.y=cos(app::getElapsedSeconds()*mLocOriginal.y)*mRadCoeff+app::getWindowHeight()/2;
    mLocCurrent.y=((left+right)*100)+(app::getWindowHeight()/2);
    
    //mRad=sin((mLocCurrent.x+mLocCurrent.y)) * mRadCoeff;
    
    mColor=right*16777215;
    //float red = float((int(mColor)<<16)&0xFF);
}

void Circle::draw()
{
    //gl::color( mColor );
    //std::cout<<mColor<<"\n";
    //gl::color((int(mColor)<<16)&0xFF,(int(mColor)<<8)&0xFF,int(mColor)&0xFF);
    gl::drawSolidCircle(mLocCurrent,mRad);
}