#include <Particle.h>

class ParticleWorld
{


struct ParticleRegistration
{
  Particle *particle;
  ParticleRegistration *next;
};


ParticleRegistration *firstParticle;

public:

ParticleWorld(unsigned maxContacts, unsigned iterations=0);

};
