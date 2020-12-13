// Created by Aidin Attar. 2019

// read.cc

#include<fstream>

#include "Particle.h"
#include "Event.h"

const Event* read(std::ifstream& file){

    // pointers to objects
    Event* ev;
    int i;

    // try to read input file
    if (file >> i)   ev = new Event; // on success create new event
    else return 0; // on failure return null pointer

    // set event number
    ev->evNumber = i;
    // set decay point coordinates
    file >> ev->x >> ev->y >> ev->z;

    // read and store number of points
    int n;
    file >> n;
    ev->nParticles = n;

    // allocate memory for array of Particles
    ev->particles = new Particle*[n];

    // create the object for the pointer
    for ( i = 0 ; i < n ; ++i ){
        Particle* par = new Particle;
        file >> par->q
             >> par->Px
             >> par->Py
             >> par->Pz; 
        ev->particles[ i ] = par;
    }

    return ev;
}
