 #include "PFholder.h"

 void PFholder::add(Particle * particle, ParticleForceGenerator* pfg) {
  if (particle == NULL || pfg == NULL) return;
  PFcontainer* pfc = new PFcontainer(particle,pfg);
  PFstorage.push_back(pfc);
 }

 void PFholder::remove(int pos) {
  std::vector<PFcontainer*>::iterator i = PFstorage.begin();
  advance(i,pos);
  PFstorage.erase(i);
 }

 void PFholder::clear() {
  PFstorage.clear();
 }

 void PFholder::updateForces(GLfloat duration) {
  for (unsigned i = 0; i < PFstorage.size(); i++) {
    PFstorage[i]->generator->updateForce(PFstorage[i]->particle, duration);
  }
 }
