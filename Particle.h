#pragma once

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
  void setPos(float x, float y, float z);
  void setVel(float x, float y, float z);
  void setAcc(float x, float y, float z);
  void incPos(float x, float y, float z);
  void incVel(float x, float y, float z);
  void incAcc(float x, float y, float z);
  void updateVel(float t, Vector acc);
  void updatePos(float t);
  void integrate(float t);
  void addForce(const Vector &force);
  void clearForces();
  virtual void render();
  ~Particle();
};
