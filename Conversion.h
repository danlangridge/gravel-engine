#include <Quaternion.h>
#include <Mat4.h>
#include <Vector.h>

namespace Conversion {

Quaternion Mat4ToQuaternion(const Mat4 &mat);
Mat4 QuaternionToMat4(const Quaternion &quaternion);

}
