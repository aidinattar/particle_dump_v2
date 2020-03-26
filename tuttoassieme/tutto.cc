// Created by Aidin Attar. 2019

// main.cc

/* Rimane da fare la funzione clear, inoltre non capisco se ho capito
   cosa esattamente mi era richiesto nel fare una array di puntatori
   alla struttura Particle. Essendo un array di puntatori deve avere
   qualcosa a cui puntare: io ho definito tale oggetto nella funzione
   read: mi viene il dubbio di aver sbagliato poiché mi viene richiesto
   di distruggerlo nella funzione clear.
   Per il resto il programma legge e stampa i dati in modo esatto. */

/* È inoltre ancora da fare la divisione in traslation unit diverse, ma
   questo mi sono convinto a farlo come ultima cosa poiché mi risutla
   dispersivo altrimenti lavorare su file sorgenti diversi in 
   contemporanea. */


#include<iostream>
#include<fstream>

#ifndef Particle_h
#define Particle_h

struct Particle{
    int q; // charge
    float Px; float Py; float Pz; // momentum components
};

#endif

#ifndef Event_h
#define Event_h

struct Event {
    int evNumber; // event number
    float x; float y; float z;  // point coordinates  
    int nParticles;   // number of particles
    Particle** particles = new Particle*[nParticles]; // array of pointers to Particle
};

#endif


const Event* read( std::ifstream& file );
void dump( const Event& ev);
void clear( const Event* ev);

int main( int argc, char* argv[] ) {

    // open input file
    const char* name = argv[1];
    std::ifstream file(name);

    const Event* ev;

    // loop over events
    while( ( ev = read( file ) ) != 0 ){
        dump( *ev );
        clear( ev );
        }


    return 0;
}

const Event* read(std::ifstream& file){

    // pointers to objects
    Particle* par;
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
    par = new Particle[n];
    ev->particles = new Particle*[n];

    for ( i = 0 ; i < n ; ++i)
        ev->particles[ i ] = &par[ i ];

    for (i = 0; i < n; ++i)
        file >> ev->particles[i]->q
             >> ev->particles[i]->Px
             >> ev->particles[i]->Py
             >> ev->particles[i]->Pz;

    return ev;
}

void dump( const Event& ev ){

    std::cout << ev.evNumber << std::endl
              << ev.x << ' '
              << ev.y << ' '
              << ev.z << std::endl
              << ev.nParticles << std::endl;

    for( int i = 0; i<ev.nParticles; ++i)
        std::cout <<  ev.particles[i]->q << ' '
                  << ev.particles[i]->Px << ' '
                  << ev.particles[i]->Py << ' '
                  << ev.particles[i]->Pz << std::endl; 

    return;
}

/* Il problema sta qui. O meglio: probabilmente la gestione
   che ho avuto dei puntatori non è compatibile con questa funzione.
   Eppure mi sembra strano: gli elementi dell'array sono dei
   puntatori e quindi non c'è motivo per il quale il delete
   dovrebbe dare dei problemi. In più un ciclo viene eseguito:
   il secondo invece si blocca dando l'errore double free or
   corruption (out). */

void clear( const Event* ev){

    // delete all the Particle structure
    for ( int i = 0; i < ev->nParticles; ++i )
        delete ev->particles[ i ];

    // delete the array of pointers
    delete[] ev->particles;

    // delete the event
    delete ev;

    return;

}