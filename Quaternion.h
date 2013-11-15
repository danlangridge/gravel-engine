#include <Vector.h>

class Quaternion {
public: 
 GLfloat a;
 Vector v;
 
 Quaternion();
 Quaternion(GLfloat a, GLfloat i, GLfloat j, GLfloat k);
 Quaternion(GLfloat a, Vector v);
 Quaternion operator+(const Quaternion &quaternion);
 Quaternion operator*(const Quaternion &quaternion);
 
};
