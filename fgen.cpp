#include <fgen.h>

void Gravity::updateForce(RigidBody *bodhy, int duration) {
  if (body->getMass() < 9) return; 
  body->addForce(gravity * body->getMass());
}


