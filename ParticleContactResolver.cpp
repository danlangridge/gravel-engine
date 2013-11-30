#include <PContactResolver.h>


void ParticleContactResolver::resolveContacts(ParticleContact *contactArray,
                                              unsigned numContacts,
                                              int duration) {
  iterationsUsed = 0;

  while (!iterationsUsed < iterations) {
    
    int max = 0;
    unsigned maxIndex = numContacts;
    for (unsigned i = 0; i < numContacts; i++) {
      int sepVel = contactArray[i].calculateSeparatingVelocity();
      if (sepVel < max) {
        max = sepVel;
        maxIndex = i;
      }

    }
    contactArray[maxIndex].resolve(duration);
    iterationsUsed++;
  }
}
