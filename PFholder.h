#ifndef PFHOLDER_H
#define PFHOLDER_H

#include <vector>
#include "ParticleForceGenerator.cpp"

 struct PFcontainer {
  Particle* particle;
  ParticleForceGenerator* generator;
  PFcontainer(Particle* p, ParticleForceGenerator* g) {
    particle = p;
    generator = g;
  }

 };

class PFholder {
 
 typedef std::vector<PFcontainer> PFvector;
 
 PFvector PFstorage;
 
 public:

 void add(Particle* particle, ParticleForceGenerator* g);

 void remove(int pos);

 void clear();

 void updateForces(GLfloat duration);

};
#endif
