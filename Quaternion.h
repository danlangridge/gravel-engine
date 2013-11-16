#pragma once
#include <Vector.h>

class Quaternion {
public: 
 GLfloat a;
 Vector v;
 
 Quaternion();
 Quaternion(GLfloat a, GLfloat i, GLfloat j, GLfloat k);
 Quaternion(GLfloat a, Vector v);
 GLfloat magnitude() const;
 Quaternion conjugate() const;
 Quaternion inverse() const;
 Quaternion operator*(const GLfloat &scalar) const;
 Quaternion operator+(const Quaternion &quaternion) const;
 Quaternion operator*(const Quaternion &quaternion) const;
};
