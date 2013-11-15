#pragma once

#include <gl_libs.h>

struct Vector {
 GLfloat x;
 GLfloat y;
 GLfloat z;

 Vector();
 Vector(GLfloat x, GLfloat y, GLfloat z);
 void scale(GLfloat k);
 GLfloat magnitude() const;
 Vector normalized() const;
 void normalize();
 void invert();
 GLfloat dotProduct(const Vector &vector);
 Vector crossProduct(const Vector &vector);
 static Vector crossProduct(const Vector &vector1, const Vector &vector2);
 GLfloat theta(const Vector &vector);
 void clear();
 ~Vector();
 Vector operator+(const Vector &vector);
 void operator+=(const Vector &vector);
 GLfloat operator*(const Vector &vector);
 Vector operator*(const GLfloat &k);
 Vector operator%(const Vector &vector);
 void operator%=(const Vector &vector);

};
