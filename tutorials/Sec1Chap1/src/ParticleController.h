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
    void update();
    void draw();
    void addParticles(int amt);
    void removeParticles(int amt);
    
    std::list<Particle>mParticles;
};