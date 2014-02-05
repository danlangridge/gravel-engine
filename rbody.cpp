#include <rbody.h>

#include <Mat4.h>
#include <Quaternion.h>


static inline void _calculateTransformMatrix( Mat4 & transformationMatrix, const Vector &position,
                                              const Quaternion &orientation) {

  transformMatrix[0] = 1 - 2*orientation.j*orientation.j-2*orientation.k*orientation.k;
  
  transformMatrix[1] = 1 - 2*orientation.i*orientation.i-2*orientation.k*orientation.k;

  transformMatrix[2] = 1 - 2*orientation.k*orientation.k-2*orientation.k*orientation.k;
  
}


void RigidBody::caluculateDerivedData() {
   _calculateTransformMatrix(transformMatrix, position, orientation);
}

void RigidBody::setInertiaTensor(const Mat4 &inertiaTensor)
{
  inverseInertiaTensor.setInverse(inertiaTensor);
  _checkInverseInertiaTensor(inverseInertiaTensor);
}
