#include <rbody.h>

#include <Mat4.h>
#include <Quaternion.h>


static inline void _calculateTransformMatrix( Mat4 & transformationMatrix, const Vector &position,
                                              const Quaternion &orientation) {

}


void RigidBody::caluculateDerivedData() {
   _calculateTransformMatrix(transformMatrix, position, orientation);
}
