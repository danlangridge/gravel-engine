#pragma once
#include <Vector.h>
#include <string>

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

  GLfloat det(); 
  
  void translate(const Vector& position);
  
  std::string output();

  Mat4 operator*(const Mat4 &m2) const;
  Vector operator*(const Vector &vector) const;
  Mat4 operator*(const GLfloat &k) const;
  Mat4 operator=(const Mat4 &matrix); 
  GLfloat operator[](const size_t index) const;
  GLfloat& operator[](const size_t index);
};

struct Mat3 {
  
  GLfloat m[16];
  
  Mat3();
  Mat3(const GLfloat m[]);

  void populateMatrix(GLfloat m[]);

  GLfloat det(); 
  
  void translate(const Vector& position);
  
  std::string output();

  Mat3 operator*(const Mat3 &m2) const;
  Vector operator*(const Vector &vector) const;
  Mat3 operator*(const GLfloat &k) const;
  Mat3 operator=(const Mat3 &matrix); 
  GLfloat operator[](const size_t index) const;
  GLfloat& operator[](const size_t index);
};
