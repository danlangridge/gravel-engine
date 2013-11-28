#pragma once
#include <Vector.h>

static const int MAT4_SIZE = 16; 

/*
 * A 4x4 Matrix class
 * Initialized column-major order
 *
 */
struct Mat4 {
  
  GLfloat m[16];
  
  Mat4();
  Mat4(const GLfloat m[]);

  void populateMatrix(GLfloat m[]);

  GLfloat Determinant(); 

  Mat4 operator*(const Mat4 &m2) const;
  Vector operator*(const Vector &vector) const;
  Mat4 operator*(const GLfloat &k) const;
  Mat4 operator=(const Mat4 &matrix); 
  GLfloat operator[](const size_t index) const;
  GLfloat& operator[](const size_t index);
};
