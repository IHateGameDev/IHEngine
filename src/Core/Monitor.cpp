#include "../../Core/Monitor.hpp"
#include <raylib.h>

namespace ih
{   
  void Monitor::set(const uint8& monitor)
    { SetWindowMonitor(monitor); }
    
  uint8 Monitor::getCount()
    { return GetMonitorCount(); }
    
  uint8 Monitor::getCurrent()
    { return GetCurrentMonitor(); }
    
  Vector2us Monitor::getPhysicalSize(const uint8& monitor)
    { return Vector2us(GetMonitorPhysicalWidth(monitor), GetMonitorPhysicalHeight(monitor)); }

  Vector2us Monitor::getCurrentPhysicalSize()
    { return getPhysicalSize(GetCurrentMonitor()); }
    
  uint32 Monitor::getRefreshRate(const uint8& monitor)
    { return GetMonitorRefreshRate(monitor); }

  uint32 Monitor::getCurrentRefreshRate()
    { return GetMonitorRefreshRate(GetCurrentMonitor()); }

  Vector2us Monitor::getSize(const uint8& monitor)
    { return Vector2us(GetMonitorWidth(monitor), GetMonitorHeight(monitor)); }

  Vector2us Monitor::getCurrentSize()
    { return getSize(GetCurrentMonitor()); }
    
  std::string Monitor::getName(const uint8& monitor)
    { return GetMonitorName(monitor); }
    
  std::string Monitor::getCurrentName()
    { return GetMonitorName(GetCurrentMonitor()); }   
}
