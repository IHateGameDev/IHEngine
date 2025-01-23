#ifndef IH_TIME_HPP
#define IH_TIME_HPP

#include <IHSystem/settings.hpp>

namespace ih
{
  class Time
  {
    public:
      float getDeltaTime();
      uint16 getFPS();
      double getTime();
      
      void wait(const double& seconds);
      void setTargetFPS(const uint16& fps);
  };
}

#endif
