//
//  Square.cpp
//  MouseSquares
//
//  Created by Adam Riggs on 1/28/13.
//
//

#include "Square.h"
#include "cinder/gl/gl.h"

using namespace ci;


Square::Square()
{
}

Square::Square(Vec2f loc, float width, float height, int id)
{
    mLoc    =   loc;
    mWidth  =   width;
    mHeight =   height;
    mId     =   id;
    mLoc.x+=mWidth/2;
    mLoc.y+=mHeight/2;
    //std::cout << mLoc << "\n";
}

void Square::draw()
{
    gl::drawSolidCircle(mLoc,mWidth);
}