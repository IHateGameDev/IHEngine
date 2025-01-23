#include "../../Core/Time.hpp"
#include <raylib.h>

namespace ih
{
  float Time::getDeltaTime()
    { return GetFrameTime(); }

  uint16 Time::getFPS()
    { return GetFPS(); }
    
  double Time::getTime()
    { return GetTime(); }
    
  void Time::setTargetFPS(const uint16& fps)
    { SetTargetFPS(fps); }

  void Time::wait(const double& seconds)
    { WaitTime(seconds); }
}
