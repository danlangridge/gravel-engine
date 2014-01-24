#include <Particle.h>
#include <PContact.h>


class ParticleLink
{
public:
  Particle* particle[2];
  
protected:

  int currentLength() const;

public:
  virtual unsigned fillContact(ParticleContact *contact, unsigned limit) const = 0;

};

class ParticleCable : public ParticleLink
{
public:

  int maxLength;

  int restitution;

  virtual unsigned fillContact(ParticleContact *contact, unsigned limit) const = 0;

};

class ParticleRod : public ParticleLink 
{
public:

  int length;

  int currentLength() const;

  virtual unsigned fillContact(ParticleContact *contact, unsigned limit) const;

};
