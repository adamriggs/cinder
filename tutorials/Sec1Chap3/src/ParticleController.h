//
//  ParticleController.h
//  Sec1Chap1
//
//  Created by Adam Riggs on 1/18/13.
//
//
#pragma once
#include "Particle.h"
#include <list>

class ParticleController{
public:
    ParticleController();
    ParticleController(int res);
    void update( const ci::Channel32f &channel, const cinder::Vec2i &mouseLoc);
    void draw();
    void addParticles(int amt);
    void addParticle(int xi, int yi, int res);
    void removeParticles(int amt);
    
    std::list<Particle>mParticles;
    
    int mXRes, mYRes;
};