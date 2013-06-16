//
//  Ball.cpp
//  P0ng
//
//  Created by Adam Riggs on 1/25/13.
//
//

#include "Ball.h"
#include "cinder/app/App.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"


using namespace ci;

Ball::Ball()
{
}

Ball::Ball( Vec2f loc)
{
    mLoc    =   loc;
    mDir    =   Rand::randVec2f();
    mVel    =   Vec2f(2.0f,2.0f);
    mRad    =   3.0f;
}

void Ball::update()
{
    //update the location of the ball
    
    //check if the ball is outside the boundaries of the window
    //and adjust the velocity accordingly
    
    if(mLoc.x>app::getWindowWidth() || mLoc.x<0){
        //mLoc.x*=-1;
        mVel.x*=-1;
    }
    
    if(mLoc.y>app::getWindowHeight() || mLoc.y<0){
        // mLoc.y*=-1;
        mVel.y*=-1;
    }
    
    mLoc+=mVel;
    
}

void Ball::draw()
{
    gl::drawSolidCircle(mLoc, mRad);
}