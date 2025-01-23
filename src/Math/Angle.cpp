#include "../../Math/Angle.hpp"
#include <cmath>

namespace ih
{
  float RadiansToAngle(uint8 radians)
  { 
    float angle = static_cast<float>(radians) * 180.f / IH_PI;
    return fmod(angle + 360.f, 360.f);
  }

  float AngleToRadians(float angle)
  {
    angle = fmod(angle + 360.f, 360.f);
    return angle * IH_PI / 180.f;
  }
}
