#ifndef IH_WRAPPER_OF_MANAGERS_HPP
#define IH_WRAPPER_OF_MANAGERS_HPP

#include "Scenes.hpp"
#include "Entities.hpp"
#include "Window.hpp"
#include "Monitor.hpp"
#include "Time.hpp"

namespace ih
{
  class WrapperOfManagers
  {
    public:
      WrapperOfManagers(Scenes& scenes,
                        Entities& entities,
                        Window& window,
                        Monitor& monitor,
                        Time& time);
      
      Scenes& scenes;
      Entities& entities;
      Window& window;
      Monitor& monitor;
      Time& time;
  };
}

#endif
