#ifndef IH_MONITOR_HPP
#define IH_MONITOR_HPP

#include "../Math/Vector2.hpp"
#include <string>

namespace ih
{
  class Monitor
  {
    public:
      void set(const uint8& monitor);
      uint8 getCount();
      uint8 getCurrent();

      Vector2us getPhysicalSize(const uint8& monitor);
      Vector2us getCurrentPhysicalSize();
      
      uint32 getRefreshRate(const uint8& monitor);
      uint32 getCurrentRefreshRate();
      
      Vector2us getSize(const uint8& monitor);
      Vector2us getCurrentSize();
      
      std::string getName(const uint8& monitor);
      std::string getCurrentName();
  };
}

#endif
