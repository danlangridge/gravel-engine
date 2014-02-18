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
