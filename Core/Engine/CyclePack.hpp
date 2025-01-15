#ifndef IH_CYCLE_PACK_HPP
#define IH_CYCLE_PACK_HPP

namespace ih
{
  class CyclePack
  {
    public:
      virtual void awake(){};
      virtual void start(){};
      virtual void update(){};
      virtual void render(){};
      virtual void exit(){};
      virtual ~CyclePack() = default; 
  };
}

#endif
