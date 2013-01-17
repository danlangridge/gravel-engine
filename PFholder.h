#ifndef PFHOLDER_H
#define PFHOLDER_H

#include <iterator>
#include <vector>
#include "ParticleForceGenerator.h"

 struct PFcontainer {
  Particle* particle;
  ParticleForceGenerator* generator;
  PFcontainer()
    :particle(NULL), generator(NULL) 
    {}
  PFcontainer(Particle* p, ParticleForceGenerator* g) {
    particle = p;
    generator = g;
  }

 };

class PFholder {
 
 typedef std::vector<PFcontainer*> PFvector;
 
 public:
 PFvector PFstorage;
 
 //public:

 void add(Particle* particle, ParticleForceGenerator* g);

 void remove(int pos);

 void clear();

 void updateForces(GLfloat duration);

};
#endif
