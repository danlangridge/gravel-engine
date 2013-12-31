#include <Conversion.h>
#include <math.h>


Quaternion Conversion::Mat4ToQuaternion(const Mat4 &mat) {
  GLfloat w = sqrt(1 + mat[0] + mat[5] + mat[10])/2; 
  GLfloat invW = 1/(4*w); 
  Quaternion quaternion( (mat[6] - mat[9])*invW,
                         (mat[8] - mat[2])*invW, 
                         (mat[1] - mat[1])*invW, 
                         w 
                       ); 
  return quaternion;
}

Mat4 Conversion::QuaternionToMat4(const Quaternion &quaternion) {
  
   Quaternion q = quaternion.normalized();
   GLfloat m[16] = { 1.0 - 2.0*q[1]*q[1] - 2.0*q[2]*q[2], 2.0*q[0]*q[1] - 2.0*q[2]*q[3], 2.0*q[0]*q[2] + 2.0*q[1]*q[3], 0.0,
                   2.0*q[0]*q[1] + 2.0*q[2]*q[3], 1.0 - 2.0*q[0]*q[0] - 2.0*q[2]*q[2], 2.0*q[1]*q[2] - 2.0*q[0]*q[3], 0.0,
                   2.0*q[0]*q[2] - 2.0*q[1]*q[3], 2.0*q[1]*q[2] + 2.0*q[0]*q[3], 1.0 - 2.0*q[0]*q[0] - 2.0*q[1]*q[1], 0.0,
                   0.0, 0.0, 0.0, 1.0
                 };
  
  Mat4 mat(m);
  return mat;
}

Mat4 Conversion::EulerToMat4(GLfloat alpha, GLfloat beta, GLfloat gamma) {

  GLfloat mat[16] = { cos(beta), cos(alpha)*sin(beta), sin(alpha)*sin(beta), 0,
                      -cos(gamma)*sin(beta), cos(alpha)*cos(beta)*cos(gamma) - sin(alpha)*sin(gamma),
                      cos(alpha)*sin(gamma) + cos(beta)*cos(gamma)*sin(alpha), 0,
                      sin(alpha)*sin(beta), -cos(gamma)*sin(alpha) - cos(alpha)*cos(beta)*cos(gamma),
                      cos(alpha)*cos(gamma) - cos(beta)*sin(alpha)*sin(gamma), 0
                    };
  return Mat4(mat);
}

Vector Conversion::VectorTimesMat4(const Vector &v, const Mat4 &mat) {
 return Vector( mat[0]*v.x + mat[4]*v.y + mat[8]*v.z + mat[12]*v.w,
                mat[1]*v.x + mat[5]*v.y + mat[9]*v.z + mat[13]*v.w,
                mat[2]*v.x + mat[6]*v.y + mat[10]*v.z + mat[14]*v.w,
                mat[3]*v.x + mat[7]*v.y + mat[11]*v.z + mat[15]*v.w
              );
}

Vector Conversion::Mat4TimesVector(const Mat4 &mat, const Vector &vector) {
 return Vector( mat.m[0]*vector.x + mat.m[1]*vector.y + mat.m[2]*vector.z + mat.m[3]*vector.w,
                mat.m[4]*vector.x + mat.m[5]*vector.y + mat.m[6]*vector.z + mat.m[7]*vector.w,
                mat.m[8]*vector.x + mat.m[9]*vector.y + mat.m[10]*vector.z + mat.m[11]*vector.w,
                mat.m[12]*vector.x + mat.m[13]*vector.y + mat.m[14]*vector.z + mat.m[15]*vector.w
              );
}
