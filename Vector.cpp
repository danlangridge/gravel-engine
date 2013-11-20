#include "Vector.h"
#include <cmath>

Vector::Vector() 
  :x(0), y(0), z(0), w(1) {}
Vector::Vector(GLfloat x, GLfloat y, GLfloat z) 
  :x(x), y(y), z(z), w(1) {}
Vector::Vector(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
  :x(x), y(y), z(z), w(w) {}
void Vector::scale(GLfloat k) {
  x = k*x;
  y = k*y;
  z = k*z;
}
GLfloat Vector::magnitude() const{
  return sqrt(x*x+y*y+z*z);
}

Vector Vector::normalized() const {
  GLfloat mag = magnitude();
  return Vector(mag*x, mag*y, mag*z);
}

void Vector::normalize() {
  *this = normalized();
}

void Vector::invert() {
  x = -x;
  y = -y;
  z = -z;
}
GLfloat Vector::dotProduct(const Vector &vector) const {
  return x*vector.x + y*vector.y + z*vector.z;
}

Vector Vector::crossProduct(const Vector &vector) const {
  return Vector(y*vector.z-z*vector.y,
                z*vector.x-x*vector.z,
                x*vector.y-y*vector.x);
}

static Vector crossProduct(const Vector &vector1, const Vector &vector2) {
  return Vector(vector1.y*vector2.z - vector1.z*vector2.y,
                vector1.z*vector2.x - vector1.x*vector2.z,
                vector1.x*vector2.y - vector1.y*vector2.x);
}


GLfloat Vector::theta(const Vector &vector) {
  return acos(normalized()*vector.normalized());
}

void Vector::clear() {
  x = 0;
  y = 0;
  z = 0;
}

Vector::~Vector() {}

Vector Vector::operator+(const Vector &vector) const {
  return Vector(x+vector.x, y+vector.y, z+vector.z);
}

void Vector::operator+=(const Vector &vector) {
  *this = Vector(x+vector.x, y+vector.y, z+vector.z);
}

GLfloat Vector::operator*(const Vector &vector) const {
  return dotProduct(vector);
}

Vector Vector::operator*(const GLfloat &k) const {
  return Vector(x*k,y*k,z*k);
}

Vector Vector::operator%(const Vector &vector) {
  return crossProduct(vector);
}

void Vector::operator%=(const Vector &vector) {
  *this = crossProduct(vector);
}
