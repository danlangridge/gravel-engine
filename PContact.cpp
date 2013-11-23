#include "ParticleContact.h"

void ParticleContact::resolve(float t) {
  resolveVelocity(t);
}

float ParticleContact::SeparatingVelocity() const {
  Vector relativeVelocity = particle[0]->getVelocity();
  if (particle[1]) relativeVelocity -= particle[1]->getVelocity();
  return relativeVelocity*contactNormal;
}


void ParticleContact::resolveVelocity(float t) {
  float separatingVelocity = calculateSeparatingVelocity();

  if (separatingVelocity > 0) return;
  
  float newSepVelocity = -separatingVelocity*restitution;
  float deltaVelocity = newSepVelocity - separatingVelocity; 
  float totalInverseMass = particle[0]->getInverseMass();

  if (particle[1]) totalInverseMass += particle[1]->getInverseMass();
  if (totalInverseMass <= 0) return;

  float impulse = deltaVelocity / totalInverseMass;

  Vector impulsePerIMass = contactNormal * impulse;

  particle[0]->setVelocity(particle[0]->getVelocity() + 
  impulsePerIMass*particle[0]->getInverseMass());

  if (particle[1]) {
    particle[1]->setVelocity(particle[1]->getVelocity() + 
    impulsePerIMass* -particle[1]->getInverseMass());
  }
}



//-----------------
// Contact Resolver
//-----------------

void ParticleContactResolver::resolveContacts( Contact *contactArray, unsigned numContacts, float duration) {
  iterationsUsed = 0;
  while(iterationsUsed < iterations) {
    float max = 0;
    unsigned maxIndex = numContacts;
    for (unsigned i = 0; i < numContacts; i++) {
      float sepVel = contactArray[i].calculatingSeperatingVelocity();
      if (sepVel < max) {
        max = sepVel;
        maxIndex = i;
      }
    }

    contactArray[maxIndex].resolve(duration);
    iterationsUsed++;
  }
}
