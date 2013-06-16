//
//  SquareManager.cpp
//  MouseSquares
//
//  Created by Adam Riggs on 1/26/13.
//
//

#include "SquareManager.h"
#include "cinder/app/App.h"

using namespace ci;
using std::list;

SquareManager::SquareManager()
{
}

SquareManager::SquareManager(int res)
{
    resolution=res;
    gridWidth=floor(app::getWindowWidth()/resolution);
    gridHeight=floor(app::getWindowHeight()/resolution);
    
    std::cout << gridWidth << "\n";
    std::cout << gridHeight << "\n";
    
    for(int i=0; i<gridWidth; i++){
        std::cout << i<< "\n";
        std::vector<Square> row;
        for(int j=0;j<gridHeight;j++){
            std::cout << j<< "\n";
            Vec2f loc;
            loc.x=i*resolution;
            loc.y=j*resolution;
            
            row.push_back(Square(loc,resolution,resolution,(i+j)));
        }
        
        grid.push_back(row);
    }
    std::cout << "constructor over" << "\n";
    
    
    
}

void SquareManager::update(const Vec2f &loc)
{
    mouseLoc=loc;
    
}

void SquareManager::draw()
{
    //std::cout << mouseLoc << "\n";
    
    int x = floor(mouseLoc.x/resolution);
    int y = floor(mouseLoc.y/resolution);
    
    //std::cout << "x= " << x << " : " << "y= " << y << "\n";
    
    int idx = x*y;
    //std::cout << "idx= " << idx << " : ";

    try{
        if(idx>0){
            grid[x][y].draw();
            //std::cout << "mId= " << grid[x][y].mId << "\n";
        }
    } catch(Exception& e) {
        std::cout<<"exception";
    }
    
   // std::cout << "*****" << "\n";
    
}