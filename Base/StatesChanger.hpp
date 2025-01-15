#ifndef IH_STATES_CHANGER_HPP
#define IH_STATES_CHANGER_HPP

#include "BasicSystem.hpp"

namespace ih
{
  class StatesChanger : public BasicSystem
  {
    public:
      StatesChanger(Engine& engine);

      void update();
  };
}

#endif
