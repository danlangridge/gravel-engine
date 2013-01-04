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
    ParticleGravity(Vector g) 
      :g(g) {}
    void updateForce(Particle* particle, float t) {
      particle->addForce(g);
    }
};

class ParticleDrag : public ParticleForceGenerator {
  public:
    GLfloat k1, k2;
    ParticleDrag(float k1, float k2) 
      :k1(k1), k2(k2) {}
    void updateForce(Particle* particle, float t) {
      GLfloat m = (particle->v).magnitude();
      m = k1*m+k2*m*m;
      (particle->v).normalize();
      force *= -m;
      particle->addForce(force);
    }
};

#endif
