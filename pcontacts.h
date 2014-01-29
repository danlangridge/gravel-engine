#include <PContact.h>

class ParticleContactGenerator
{
public:

  virtual unsigned addContact(ParticleContact *contact, unsigned lmit) const = 0;

};


