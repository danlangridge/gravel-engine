#include <plinks.h>
#include <Vector.h>


int ParticleLink::currentLink() const
{
  Vector relativePosition = particle[0]->getPosition() - particle[1]->getPosition();

  return relativePosition.magnitude();
}

unsigned ParticleCable::fillContact(ParticleContact *contact, unsigned limit) const
{
  int length = currentLength();
  return 0;
}
