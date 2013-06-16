//
//  CircleController.cpp
//  TrigRepeater
//
//  Created by Adam Riggs on 1/29/13.
//
//

#include "CircleController.h"
#include "cinder/app/App.h"

CircleController::CircleController()
{
}

CircleController::CircleController(int num)
{
    mNumCircles=num;
    mCircleStepper=0;
    
    int density;
    density=5;
    
    Vec2f loc;
    loc.x=(app::getWindowWidth()-num*density)/2;
    loc.y=app::getWindowHeight()/2;
    
    for(int i=0;i<mNumCircles;i++){
        circles.push_back(Circle(loc));
        loc.x+=density;
    }
}

void CircleController::update()
{
    for(int i=0;i<mNumCircles;i++){
        circles[i].update();
    }
//
//    circles[mCircleStepper].update();
//    mCircleStepper++;
//    if(mCircleStepper>=mNumCircles){
//        mCircleStepper=0;
//    }
}

void CircleController::draw()
{
    for(int i=0;i<mNumCircles;i++){
        circles[i].draw();
    }
    
    
}