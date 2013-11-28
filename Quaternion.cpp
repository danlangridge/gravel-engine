#include <Quaternion.h>
#include <cmath>

Quaternion::Quaternion()
 :v(),w(0)
{}

Quaternion::Quaternion(GLfloat i, GLfloat j, GLfloat k,GLfloat w)
 :v(i, j, k), w(w)
{}

Quaternion::Quaternion(Vector v, GLfloat w)
 :v(v), w(w)
{}
 
GLfloat Quaternion::magnitude() const {
  return sqrt(w*w + v.x * v.x + v.y * v.y + v.z * v.z);
}
 
Quaternion Quaternion::conjugate() const {
 return Quaternion(v*-1,w);
}

Quaternion Quaternion::inverse() const {
 return conjugate()*(1/magnitude());
}

Quaternion Quaternion::normalized() const { 
 GLfloat magInv = 1.0/magnitude(); 
 
 return Quaternion(v.x*magInv,v.y*magInv,v.z*magInv,w*magInv);
}

void Quaternion::normalize() {
 GLfloat magInv = 1.0/magnitude(); 
 
 v.x *= magInv;
 v.y *= magInv;
 v.z *= magInv;
 w *= magInv;
}

Mat4 Quaternion::matrix() {
 Quaternion q = normalized();
 GLfloat m[16] = { 1.0 - 2.0*q[1]*q[1] - 2.0*q[2]*q[2], 2.0*q[0]*q[1] - 2.0*q[2]*q[3], 2.0*q[0]*q[2] + 2.0*q[1]*q[3], 0.0,
                   2.0*q[0]*q[1] + 2.0*q[2]*q[3], 1.0 - 2.0*q[0]*q[0] - 2.0*q[2]*q[2], 2.0*q[1]*q[2] - 2.0*q[0]*q[3], 0.0,
                   2.0*q[0]*q[2] - 2.0*q[1]*q[3], 2.0*q[1]*q[2] + 2.0*q[0]*q[3], 1.0 - 2.0*q[0]*q[0] - 2.0*q[1]*q[1], 0.0,
                   0.0, 0.0, 0.0, 1.0
                 };
 return Mat4();
}

Quaternion Quaternion::operator+(const Quaternion &quaternion) const {
  return Quaternion(v + quaternion.v, w + quaternion.w );
}
 
Quaternion Quaternion::operator*(const Quaternion &quaternion) const {
  return Quaternion(quaternion.v*w + v*quaternion.w + v.crossProduct(quaternion.v),
                    w*quaternion.w - v*quaternion.v
                   );
}

Quaternion Quaternion::operator*(const GLfloat &scalar) const {
  return Quaternion(v*scalar, w*scalar);
}


GLfloat Quaternion::operator[](const size_t index) const {
 if (index == 3) return w;
 else return v[index];
}


GLfloat& Quaternion::operator[](const size_t index) {
 if (index == 3) return w;
 else return v[index];
}
