//
//  Particle.cpp
//  Sec1Chap1
//
//  Created by Adam Riggs on 1/18/13.
//
//

#include "Particle.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"


using namespace ci;

Particle::Particle()
{
    
}

Particle::Particle(Vec2f loc)
{
    mLoc    = loc;
    mDir    = Rand::randVec2f();
    mVel    = 0.0f;
    mRadius = Rand::randFloat(1.0f,5.0f);
    mScale = 3.0f;
    //mRadius = ( sin( mLoc.y * mLoc.x ) + 1.0f ) * 2.0f;
}

void Particle::update( const Channel32f &channel, const Vec2i &mouseLoc )
{
	//mRadius = channel.getValue( mLoc ) * 7.0f;
    
	//float gray = channel.getValue( mLoc );
	//mColor = Color( gray, gray, gray );
	
	//mLoc += mDir * mVel;
    
    mDirToCursor = mouseLoc-mLoc;
    mDirToCursor.safeNormalize();
    mRadius = channel.getValue( mLoc ) * mScale;
}

void Particle::draw()
{
    //gl::drawSolidCircle(mLoc,mRadius);
    gl::color(Color(1.0f,1.0f,1.0f));
    float arrowLength=15.0f;
    Vec3f p1(mLoc, 0.0f);
    Vec3f p2(mLoc+mDirToCursor * arrowLength, 0.0f);
    float headLength = 6.0f;
    float headRadius=3.0f;
    gl::drawVector(p1,p2,headLength,headRadius);
}