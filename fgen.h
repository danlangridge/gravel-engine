#include <Vector.h>
#include <rbody.h>

class Gravity {
public:
  Vector gravity;

  Gravity(const Vector &gravity);

  virtual void updateForce(RigidBody *body, int duration);
};

class Spring {
  Vector connectionPoint;
  Vector otherConnectionPoint;
  RigidBody* other;
  int springConstant;
  int restLength;
public:
  Spring(const Vector &localConnectionPt,
         RigidBody* other,
         const Vector &otherConnectionPt,
         int springConstant,
         int restLength);
  virtual void updateForce(RigidBody *body, int duration);
};

