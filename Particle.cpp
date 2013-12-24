#include "Particle.h"
#include <cmath>

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

void Particle::setPos(float x, float y, float z) {
  p.x = x;
  p.y = y;
  p.z = z;
}


void Particle::setVel(float x, float y, float z) {
  v.x = x;
  v.y = y;
  v.z = z;
}

void Particle::setAcc(float x, float y, float z) {
  a.x = x;
  a.y = y;
  a.z = z;
}

void Particle::incPos(float x, float y, float z) {
  p.x += x;
  p.y += y;
  p.z += z;
}


void Particle::incVel(float x, float y, float z) {
  v.x += x;
  v.y += y;
  v.z += z;
}

void Particle::incAcc(float x, float y, float z) {
  a.x += x;
  a.y += y;
  a.z += z;
}

void Particle::updateVel(float t, Vector acc) {
  v = v*pow(d,t) + acc*(GLfloat)t;
}
void Particle::updatePos(float t) {
  p = p+v*(GLfloat)t+fsum*((GLfloat)pow(t,2))*0.5;
}

void Particle::integrate(float t) {
  if (t == 0.0) return;
  updatePos(t);

  Vector acc = a;
  acc += fsum*m; //?
  updateVel(t, acc);
  clearForces();
}

void Particle::addForce(const Vector &force) {
  fsum += force;
}

void Particle::clearForces() {
  fsum.clear();
}

void Particle::render() {}

Particle::~Particle() {
}
