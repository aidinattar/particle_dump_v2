// Created by Aidin Attar. 2019

// dump.cc

#include <iostream>

#include "Particle.h"
#include "Event.h"

void dump( const Event& ev ){

    // write event number, 3 decay point coordinates and number
    // of particles 
    std::cout << ev.evNumber << std::endl
              << ev.x << ' '
              << ev.y << ' '
              << ev.z << std::endl
              << ev.nParticles << std::endl;

    // write charge and 3 momentum components for every particle
    for( int i = 0; i<ev.nParticles; ++i)
        std::cout <<  ev.particles[i]->q << ' '
                  << ev.particles[i]->Px << ' '
                  << ev.particles[i]->Py << ' '
                  << ev.particles[i]->Pz << std::endl; 

    return;
}
