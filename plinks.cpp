#include <plinks.h>
#include <Vector.h>


int ParticleLink::currentLink() const {
  Vector relativePosition = particle[0]->getPosition() - particle[1]->getPosition();

  return relativePosition.magnitude();
}

unsigned ParticleCable::fillContact(ParticleContact *contact, unsigned limit) const {
  
  int length = currentLength();

  if (length < maxLength) return 0;
  
  contact->particle[0] = particle[0];
  contact->particle[1] = particle[1];

  Vector normal = particle[1]->getPosition() - particle[0]->getPosition();
  normal.normalize();

  contact->contactNormal = normal;

  contact->penetration = length - maxLength;
  contact->restitution = restitution;

  return 1;
}
