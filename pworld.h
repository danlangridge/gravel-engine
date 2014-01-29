#include <Particle.h>

class ParticleWorld
{


struct ParticleRegistration
{
  Particle *particle;
  ParticleRegistration *next;
};


ParticleRegistration *firstParticle;
ParticleContactResolver resolver;

public:

ParticleWorld(unsigned maxContacts, unsigned iterations=0);

void startFrame();

unsigned generateContacts();
void integrate(int duration);
void runPhysics(int duration);
};
