#include <rbody.h>

struct PotentialContact {
  RigidBody* body[2];
};


template<class BoundingVolumeClass>
class BVHNode {
  BVHNode* children[2];
  BoundingVolumeClass volume;
  RigidBody *body;
  bool isLeaf() const;
}; 
