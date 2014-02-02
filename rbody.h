#include <Vector.h>
#include <Quaternion.h>


class RigidBody {

public:
  int inverseMass;
  Vector position;
  Quaternion orientation;
  Vector velocity;
  Matrix4 transformMatrix;
  
  void calculateDerivedData();
};
