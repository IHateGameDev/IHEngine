#ifndef IH_SCENE_HPP
#define IH_SCENE_HPP

#include "CyclePack.hpp"
#include <IHSystem/settings.hpp>

namespace ih
{
  class SceneManager;
  
  class Scene
  {
    private:
      CyclePack** cyclePacks;
      uint16 cyclePackCount;

      void awake();
      void start();
      void update();
      void render();
      void exit();

    public:
      Scene(uint16 count, CyclePack** packs);
      ~Scene();

      friend class SceneManager;
  };
}

#endif
