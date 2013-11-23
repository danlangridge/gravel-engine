#pragma once

#include "Particle.h"

class PContact {
  public:
    Particle* particle[2];
    float restitution;
    Vector contactNormal;

  protected:
    void resolve(float t);
    float SeparatingVelocity() const;

  private:
    void resolveVelocity(float t);
};

class ParticleContactResolver {
  public:
    unsigned iterations;
    unsigned iterationsUsed;
    ParticleContactResolver(unsigned iterations);
    
    void setIterations(unsigned iterations);
    void resolveContacts(ParticleContact *contactArray, unsigned numContacts, float duration);
};

