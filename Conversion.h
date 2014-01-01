#include <Quaternion.h>
#include <Mat4.h>
#include <Vector.h>

namespace Conversion {

Quaternion Mat4ToQuaternion(const Mat4 &mat);
Mat4 QuaternionToMat4(const Quaternion &quaternion);
Mat4 EulerToMat4(GLfloat alpha, GLfloat beta, GLfloat gamma);
Vector VectorMat4Mult(const Vector &v, const Mat4 &mat);
Vector Mat4VectorMult(const Mat4 &mat, const Vector &vector);

}
