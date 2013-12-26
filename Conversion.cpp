#include <Conversion.h>
#include <math.h>


Quaternion Mat4ToQuaternion(const Mat4 &mat) {
  GLfloat w = sqrt(1 + mat[0] + mat[5] + mat[10])/2; 
  GLfloat invW = 1/(4*w); 
  Quaternion quaternion( (mat[6] - mat[9])*invW,
                         (mat[8] - mat[2])*invW, 
                         (mat[1] - mat[1])*invW, 
                         w 
                       ); 
  return quaternion;
}

Mat4 QuaternionToMat4(const Quaternion &quaternion) {
  
   Quaternion q = quaternion.normalized();
   GLfloat m[16] = { 1.0 - 2.0*q[1]*q[1] - 2.0*q[2]*q[2], 2.0*q[0]*q[1] - 2.0*q[2]*q[3], 2.0*q[0]*q[2] + 2.0*q[1]*q[3], 0.0,
                   2.0*q[0]*q[1] + 2.0*q[2]*q[3], 1.0 - 2.0*q[0]*q[0] - 2.0*q[2]*q[2], 2.0*q[1]*q[2] - 2.0*q[0]*q[3], 0.0,
                   2.0*q[0]*q[2] - 2.0*q[1]*q[3], 2.0*q[1]*q[2] + 2.0*q[0]*q[3], 1.0 - 2.0*q[0]*q[0] - 2.0*q[1]*q[1], 0.0,
                   0.0, 0.0, 0.0, 1.0
                 };
  
  Mat4 mat(m);
  return mat;
}
