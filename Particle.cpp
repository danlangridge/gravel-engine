#include "Particle.h"

Particle::Particle() {
  m = 1.f;
  d = 1.f;
}

Particle::Particle(GLfloat x, GLfloat y, GLfloat z) {
  m = 1.f;
  p.x = x;
  p.y = y;
  p.z = z;
  d = 1.f;
}

void Particle::updateVel(float t) {
  v = v*(GLfloat)d^t + fsum*(GLfloat)t;
}
void Particle::updatePos(float t) {
  p = p+v*(GLfloat)t+fsum*((GLfloat)t^2)*0.5;
}

void Particle::integrate(float t) {
  if (duration == 0.0) return;
  updatePos(t);

  acc = a;
  acc += fsum*m; //?
  updateVel(t);

  clearForces();

}

void Particle::addForce(const Vector &force) {
  fsum += force;
}

void Particle::clearForces() {
  fsum.clear();
}

Particle::~Particle() {
}
