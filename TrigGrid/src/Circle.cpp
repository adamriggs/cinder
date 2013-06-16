//
//  Circle.cpp
//  TrigGrid
//
//  Created by Adam Riggs on 1/29/13.
//
//

#include "Circle.h"
#include "cinder/gl/gl.h"

using namespace ci;

Circle::Circle()
{
}

Circle::Circle(const Vec2i &loc)
{
    mLoc=loc;
    mRadius=3.0f;
    mScale=3.0f;
    //mRadius=sin(mLoc.x*mLoc.y)+2.0f;
}

void Circle::update(const Vec2i &mouseLoc, const Channel32f &channel)
{
    mMouseLoc           = mouseLoc;
    mDirToCursor        = mMouseLoc-mLoc;
    
    float distToCursor  = mDirToCursor.length();
    float time          = app::getElapsedSeconds();
    float dist          = distToCursor * 0.025f;
    float sinOffset     = sin(dist-time)+1.0f;
    
    mDirToCursor.normalize();
    mDirToCursor        *= sinOffset * 100.0f;
    
    Vec2f newLoc        = mLoc+mDirToCursor;
    newLoc.x            = constrain(newLoc.x, 0.0f, channel.getWidth()-1.0f);
    newLoc.y            = constrain(newLoc.y, 0.0f, channel.getHeight() - 1.0f);
    
    mRadius             = channel.getValue(newLoc)*mScale+2.0f;
    
    float gray=channel.getValue(mLoc);
    mColor=Color(gray,gray,gray);
}

void Circle::draw()
{
    gl::color(mColor);
    gl::drawSolidCircle(mLoc,mRadius);
}