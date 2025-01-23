#ifndef IH_CYCLE_PACK_HPP
#define IH_CYCLE_PACK_HPP

#include "WrapperOfManagers.hpp"

namespace ih
{
  class CyclePack
  {
    protected:
      Scenes& scenes;
      Entities& entities;
      Window& window;
      Monitor& monitor;
      Time& time;

    public:
      CyclePack(WrapperOfManagers& wom);
      virtual void awake(){};
      virtual void start(){};
      virtual void update(){};
      virtual void render(){};
      virtual void exit(){};
      virtual ~CyclePack() = default; 
  };
}

#endif
