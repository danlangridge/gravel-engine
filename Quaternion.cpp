#include <Quaternion.h>
#include <cmath>

Quaternion::Quaternion()
 :a(0), v()
{}

Quaternion::Quaternion(GLfloat a, GLfloat i, GLfloat j, GLfloat k)
 :a(a), v(i, j, k)
{}

Quaternion::Quaternion(GLfloat a, Vector v)
 :a(a), v(v)
{}
 
GLfloat Quaternion::magnitude() const {
  return sqrt(a*a + v.x * v.x + v.y * v.y + v.z * v.z);
}
 
Quaternion Quaternion::conjugate() const {
 return Quaternion(a, v*-1);
}

Quaternion Quaternion::inverse() const {
 return conjugate()*(1/magnitude());
}
  
Quaternion Quaternion::operator+(const Quaternion &quaternion) const {
  return Quaternion( a + quaternion.a, v + quaternion.v );
}
 
Quaternion Quaternion::operator*(const Quaternion &quaternion) const {
  return Quaternion( a*quaternion.a - v*quaternion.v,
                     quaternion.v*a + v*quaternion.a + v.crossProduct(quaternion.v)
                   );
}

Quaternion Quaternion::operator*(const GLfloat &scalar) const {
  return Quaternion(a*scalar,v*scalar);
}
