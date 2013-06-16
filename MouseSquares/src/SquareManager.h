//
//  SquareManager.h
//  MouseSquares
//
//  Created by Adam Riggs on 1/26/13.
//
//

#pragma once
#include "Square.h"

#include <vector>

using namespace ci;

class SquareManager{
public:
    SquareManager();
    SquareManager(int res);
    void update(const Vec2f &loc);
    void draw();
    
    int     resolution;
    float   gridWidth;
    float   gridHeight;
    
    Vec2f   mouseLoc;
    
    std::vector< std::vector<Square> > grid;
    
};

