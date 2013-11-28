#include <Mat4.h>


Mat4::Mat4()
{
 for (unsigned index; index < MAT4_SIZE; index++) {
  if (index % 4 == 0) m[index] = 1;
  else m[index] = 0;
 }
}


Mat4::Mat4(const GLfloat m[]) {
 for (unsigned index = 0; index < MAT4_SIZE; index++) {
  this->m[index] = m[index];
 }
}

void Mat4::populateMatrix(GLfloat m[]) {
 for (unsigned index = 0; index < MAT4_SIZE; index++) {
  this->m[index] = m[index];
 }
}

Vector Mat4::operator*(const Vector &vector) const {
 return Vector( m[0]*vector.x + m[1]*vector.y + m[2]*vector.z + m[3]*vector.w,
                m[4]*vector.x + m[5]*vector.y + m[6]*vector.z + m[7]*vector.w,
                m[8]*vector.x + m[9]*vector.y + m[10]*vector.z + m[11]*vector.w,
                m[12]*vector.x + m[13]*vector.y + m[14]*vector.z + m[15]*vector.w
              );
}

Mat4 Mat4::operator*(const Mat4 &m2) const {
 Mat4 mat; 
   for (unsigned i = 1; i < 5; i++) {
     for (unsigned j = 0; j < 4; j++) {
       for (unsigned k = 0; k < 4; k++) {
         mat.m[i*j] += m[4*k + j]*m2.m[k + i*4];     
       }
     }
   }
 return mat;
}

Mat4 Mat4::operator*(const GLfloat &k) const {
 Mat4 matrix = Mat4(m); 
 for (unsigned index = 0; index < MAT4_SIZE; index++) {
   matrix.m[index] = m[index]*k; 
 }
 return matrix; 
}
  
Mat4 Mat4::operator=(const Mat4 &matrix) {
 for (unsigned index = 0; index < MAT4_SIZE; index++) {
   m[index] = matrix.m[index]; 
 }
 return *this; 
}

GLfloat Mat4::operator[](const size_t index) const {
 return m[index];
}

GLfloat& Mat4::operator[](const size_t index) {
 return m[index];
}

