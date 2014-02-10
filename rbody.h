#include <Vector.h>
#include <Mat4.h>
#include <Quaternion.h>


class RigidBody {

public:
  int inverseMass;
  Vector position;
  Quaternion orientation;
  Vector velocity;
  Mat4 transformMatrix;
  Mat4 InverseInertiaTensor; 
  void calculateDerivedData(); 
  void integrate(int duration); 
};
