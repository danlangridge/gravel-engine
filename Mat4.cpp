#include <Mat4.h>
#include <sstream>

Mat4::Mat4()
{
 for (unsigned index = 0; index < MAT4_SIZE; index++) {
  if (index % 5 == 0)
    m[index] = 1;
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

GLfloat detHelper(int matrixSize, GLfloat* matrix) {
 if (matrixSize == 2) return matrix[0]*matrix[3] - matrix[1]*matrix[2];  
 GLfloat determinant = 0;
 for ( unsigned index = 0; index < matrixSize  ; index = index + matrixSize) {
   GLfloat* minor = new GLfloat[(matrixSize-1) *(matrixSize-1)];
  
   //TODO: calculate minor
   for (unsigned minorIndex = index; minorIndex < 1; minorIndex++) {

   }
   determinant += index*detHelper(matrixSize-1, minor); 
 }
 return determinant;
}

GLfloat Mat4::det() {
 return detHelper(MAT4_SIZE,m);
}

void Mat4::translate(const Vector& position) {
 m[12] = position[0];
 m[13] = position[1];
 m[14] = position[2];
}

std::string Mat4::output() {

 std::stringstream matrix;

 for (unsigned i = 0; i < 4; i++) {
  for (unsigned j = 0; j < 4 ; j++) {
   
   matrix << m[i + j*4] << "  ";
  }
  matrix << "\n";
 }
 
 return matrix.str();
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



Mat3::Mat3()
{
 for (unsigned index = 0; index < MAT3_SIZE; index++) {
  if (index % 4 == 0)
    m[index] = 1;
  else m[index] = 0;
 }
}

Mat3::Mat3(const GLfloat m[]) {
 for (unsigned index = 0; index < MAT3_SIZE; index++) {
  this->m[index] = m[index];
 }
}

void Mat3::populateMatrix(GLfloat m[]) {
 for (unsigned index = 0; index < MAT3_SIZE; index++) {
  this->m[index] = m[index];
 }
}

GLfloat Mat3::det() {

  return m[0]*m[4]*m[8] + m[3]*m[7]*m[2] + m[6]*m[1]*m[5] -
         m[6]*m[4]*m[2] - m[3]*m[1]*m[8] - m[0]*m[7]*m[5];
}

Mat3 Mat3::operator*(const GLfloat &k) const {
 Mat3 matrix = Mat3(m); 
 for (unsigned index = 0; index < MAT3_SIZE; index++) {
   matrix.m[index] = m[index]*k; 
 }
 return matrix; 
}
  
Mat3 Mat3::operator=(const Mat3 &matrix) {
 for (unsigned index = 0; index < MAT3_SIZE; index++) {
   m[index] = matrix.m[index]; 
 }
 return *this; 
}

GLfloat Mat3::operator[](const size_t index) const {
 return m[index];
}

GLfloat& Mat3::operator[](const size_t index) {
 return m[index];
}

Vector Mat3::operator*(const Vector &vector) const {
 return Vector( m[0]*vector.x + m[1]*vector.y + m[2]*vector.z,
                m[4]*vector.x + m[5]*vector.y + m[6]*vector.z,
                m[8]*vector.x + m[9]*vector.y + m[10]*vector.z
              );
}
