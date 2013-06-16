//
//  Square.h
//  MouseSquares
//
//  Created by Adam Riggs on 1/28/13.
//
//

#pragma once
#include "cinder/app/App.h"
#include "cinder/Vector.h"

class Square{
public:
    Square();
    Square(ci::Vec2f loc, float width, float height, int id);
    void draw();
    
    ci::Vec2f   mLoc;
    float       mWidth;
    float       mHeight;
    int         mId;

};
