//
//  GridController.cpp
//  TrigGrid
//
//  Created by Adam Riggs on 1/29/13.
//
//

#include "GridController.h"


using namespace ci;

GridController::GridController()
{
    
}

GridController::GridController(int res)
{
    mRes=res;
    mGridWidth=floor(app::getWindowWidth()/mRes);
    mGridHeight=floor(app::getWindowHeight()/mRes);
    
    for(int i=0;i<mGridWidth;i++){
        std::vector<Circle> row;
        for(int j=0;j<mGridHeight;j++){
            Vec2i loc;
            loc.x=i*mRes;
            loc.y=j*mRes;
            
            row.push_back(Circle(loc));
        }
        grid.push_back(row);
        
    }
}

void GridController::update(const Vec2i &mouseLoc, const Channel32f &channel)
{
//    mMouseLoc=mouseLoc;
//    mChannel=channel;
    for(int i=0;i<mGridWidth;i++){
        std::vector<Circle> row;
        for(int j=0;j<mGridHeight;j++){
            grid[i][j].update(mouseLoc, channel);
        }
        
        
    }
}

void GridController::draw()
{
    for(int i=0;i<mGridWidth;i++){
        std::vector<Circle> row;
        for(int j=0;j<mGridHeight;j++){
            grid[i][j].draw();
        }
        
        
    }
}
