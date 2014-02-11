#include <Vector.h>
#include <rbody.h>

class Gravity {
public:
  Vector gravity;

  Gravity(const Vector &gravity);

  virtual void updateForce(RigidBody *body, int duration);
};
