#include <pworld.h>


void ParticleWorld::startFrame() {

  ParticleRegistration *reg = firstParticle;
  while(reg) {
    reg->particle->clearAccumulator();
    reg = reg->next;
  }
}

usigned ParticleWorld::generateContacts() {

  unsigned limit = maxContacts;
  ParticleContact *nextContact = contacts;

  ContactGenRegistration *reg = firstContactGen;
  
  while (reg) {

    unsigned used = reg->gen->addContact(nextContact, limit);
    limit -= used;
    nextContact += used;

    if (limit  <= 0) break;

    reg = reg->next;

  }

  return maxContacts - limit;

}
