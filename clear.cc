// Created by Aidin Attar. 2019

// clear.cc

#include "Particle.h"
#include "Event.h"

void clear( const Event* ev){

    // delete all the Particle structures
    for ( int i = 0; i < ev->nParticles; ++i )
        delete ev->particles[ i ];

    // delete the array of pointers
    delete[] ev->particles;

    // delete the event
    delete ev;

    return;

}
