#pragma once
#include <Vector.h>
#include <Mat4.h>

//TODO: Add Matrix multiplication variants
class Quaternion {
public: 
 Vector v;
 GLfloat w;
 
 Quaternion();
 Quaternion(GLfloat i, GLfloat j, GLfloat k, GLfloat w);
 Quaternion(Vector v,GLfloat w);
 GLfloat magnitude() const;
 Quaternion conjugate() const;
 Quaternion inverse() const;
 Quaternion normalized() const; 
 void normalize();
 Mat4 matrix();
 Quaternion operator*(const GLfloat &scalar) const;
 Quaternion operator+(const Quaternion &quaternion) const;
 Quaternion operator*(const Quaternion &quaternion) const;
 GLfloat operator[](const size_t index) const;
 GLfloat& operator[](const size_t index);
};
