#include <pworld.h>


void ParticleWorld::startFrame() {

  ParticleRegistration *reg = firstParticle;
  while(reg) {
    reg->particle->clearAccumulator();
    reg = reg->next;
  }
}
