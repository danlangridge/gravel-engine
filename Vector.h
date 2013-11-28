#pragma once

#include <gl_libs.h>

struct Vector {
 GLfloat x;
 GLfloat y;
 GLfloat z;
 GLfloat w;

 Vector();
 Vector(GLfloat x, GLfloat y, GLfloat z);
 Vector(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
 void scale(GLfloat k);
 GLfloat magnitude() const;
 Vector normalized() const;
 void normalize();
 void invert();
 GLfloat dotProduct(const Vector &vector) const;
 Vector crossProduct(const Vector &vector) const;
 static Vector crossProduct(const Vector &vector1, const Vector &vector2);
 GLfloat theta(const Vector &vector);
 void clear();
 ~Vector();
 Vector operator+(const Vector &vector) const;
 void operator+=(const Vector &vector);
 GLfloat operator*(const Vector &vector) const;
 Vector operator*(const GLfloat &k) const;
 Vector operator%(const Vector &vector);
 void operator%=(const Vector &vector);
 GLfloat operator[](const size_t index) const;
 GLfloat& operator[](const size_t index);

};
