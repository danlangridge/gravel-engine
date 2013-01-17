 #include "PFholder.h"
 #include <iterator>

 void PFholder::add(Particle * particle, ParticleForceGenerator* g) {
  if (particle == NULL || g == NULL) return;
  PFcontainer pfc = PFcontainer(particle,g);
  PFstorage.push_back(pfc);
 }

 void PFholder::remove(int pos) {
  std::vector<PFcontainer>::iterator i = PFstorage.begin();
  advance(i,pos);
  PFstorage.erase(i);
 }

 void PFholder::clear() {
  PFstorage.clear();
 }

 void PFholder::updateForces(GLfloat duration) {
  for (unsigned i = 0; i < PFstorage.size(); i++) {
    (PFstorage[i].generator)->updateForce(PFstorage[i].particle, duration);
  }
 }
