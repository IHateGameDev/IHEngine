#ifndef IH_BASIC_SYSTEM_HPP
#define IH_BASIC_SYSTEM_HPP

#include <IHEngineLib/Core/Engine/Engine.hpp>

namespace ih
{
  class BasicSystem
  {
    protected:
      Engine& engine;

    public:
      BasicSystem(Engine& engine): engine(engine){}

      virtual ~BasicSystem() = 0;
  };
}

#endif
