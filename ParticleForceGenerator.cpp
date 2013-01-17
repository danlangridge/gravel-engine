#include "ParticleForceGenerator.h"

ParticleGravity::ParticleGravity(Vector g) 
  :g(g) {}

void ParticleGravity::updateForce(Particle* particle, float t) {
  particle->addForce(g);
}

ParticleDrag::ParticleDrag(float k1, float k2) 
      :k1(k1), k2(k2) {}
void ParticleDrag::updateForce(Particle* particle, float t) {
  GLfloat m = (particle->v).magnitude();
  m = k1*m+k2*m*m;
  Vector force = particle->v; 
  force.normalize();
  force = force*-m;
  particle->addForce(force);
}
