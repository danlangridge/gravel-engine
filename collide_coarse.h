#include <rbody.h>

struct PotentialContact {
  RigidBody* body[2];
};


template<class BoundingVolumeClass>
class BVHNode {
  BVHNode* children[2];
  BoundingVolumeClass volume;
  RigidBody *body;
  bool isLeaf() const
  {
    return (body != NULL);
  }

  unsigned getPotentialContacts(PotentialContact* contacts, unsigned limit) const;
};

template<class BoundingVolumeClass>
bool BVHNode<BoundingVolumeClass>::overlaps( const BVHNode<BoundingVolumeClass>* other ) const
{
  return volume->overlaps(other->volume);
}

template<class BoundingVolumeClass>
unsigned BVHNode <BoundingVolumeClass>::getPotentialContactsWith(
                                                                 const BVHNode<BoundingVolumeClass> *other, 
                                                                 PotentialContact* contacts,
                                                                 unsigned limit
                                                                ) const
{
  if (!overlaps(other) || limit == 0) return 0;
  if (isLeaf() && other->isLeaf()) {
    contacts->body[0] = body;
    contacts->body[1] = other->body;
    return 1;
  }

  if (other->isLeaf() || !isLeaf() && volume->getSize() >= other->volume->getSize()) {
    unsigned count = children[0]->getPotentialContactsWith( other, contacts, limit);
  
} 
