#ifndef PARTICLEFORCEGENERATOR_H
#define PARTICLEFORCEGENERATOR_H

#include "Particle.h"

class ParticleForceGenerator {
  public:
    virtual void updateForce(Particle* particle, float t) = 0;
};

class ParticleGravity : public ParticleForceGenerator {
  public:
    Vector g;
    ParticleGravity(Vector g);
    void updateForce(Particle* particle, float t);
};

class ParticleDrag : public ParticleForceGenerator {
  public:
    GLfloat k1, k2;
    ParticleDrag(float k1, float k2);
    void updateForce(Particle* particle, float t);
};

#endif
