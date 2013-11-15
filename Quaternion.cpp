#include <Quaternion.h>

Quaternion::Quaternion()
 :a(0), v()
 {}

Quaternion::Quaternion(GLfloat a, GLfloat i, GLfloat j, GLfloat k)
 :a(a), v(i, j, k)
 {}

Quaternion::Quaternion(GLfloat a, Vector v)
 :a(a), v(v)
 {}
 
 Quaternion Quaternion::operator+(const Quaternion &quaternion) {
  return Quaternion( this->a + quaternion.a, this->v+quaternion.v );
 }
 
 Quaternion Quaternion::operator*(const Quaternion &quaternion) {
  return Quaternion( a*quaternion.a - v*quaternion.v,
                     ((Vector)quaternion.v)*a + v*quaternion.a + v.crossProduct(quaternion.v)
                   );
 }
