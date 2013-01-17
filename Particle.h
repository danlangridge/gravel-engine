#ifndef PARTICLE_H
#define PARTICLE_H

#include "gllibs.h"
#include "Vector.h"


struct Particle {

  // Mass
  GLfloat m;

  // Position Vector
  Vector p;

  // Velocity Vector
  Vector v;
  
  // Acceleration Vector
  Vector a;

  Vector fsum;

  // Damping factor
  GLfloat d;
  Particle();
  Particle(GLfloat x, GLfloat y, GLfloat z);
  void updateVel(float t, Vector acc);
  void updatePos(float t);
  void integrate(float t);
  void addForce(const Vector &force);
  void clearForces();
  virtual void render();
  ~Particle();
};

#endif
