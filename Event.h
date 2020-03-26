// Created by Aidin Attar. 2019

// Event.h

#ifndef Event_h
#define Event_h

struct Particle;

struct Event {
    int evNumber; // event number
    float x; float y; float z;  // point coordinates  
    int nParticles;   // number of particles
    Particle** particles = new Particle*[nParticles]; // array of pointers to Particle
};

#endif
