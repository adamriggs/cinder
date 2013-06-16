//
//  GridController.h
//  TrigGrid
//
//  Created by Adam Riggs on 1/29/13.
//
//

#pragma once
#include "circle.h"
#include <vector>

using namespace ci;


class GridController
{
public:
    GridController();
    GridController(int res);
    
    void update(const ci::Vec2i &mouseLoc, const Channel32f &channel);
    void draw();
    
    int     mRes;
    int     mGridWidth;
    int     mGridHeight;
    Vec2f   mMouseLoc;
    
    Channel32f      mChannel;
    
    std::vector< std::vector<Circle> > grid;

};
