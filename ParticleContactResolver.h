#include <PContact.h>

class ParticleContactResolver {

protected:

unsigned iterations;

unsigned iterationsUsed;

public:

particleContactResolver(unsigned iterations);

void setIterations(unsigned iterations);

void resolveContacts(ParticleContact *contactArray, unsigned numContacts, int duration);

};
