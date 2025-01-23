#ifndef IH_SCENE_HPP
#define IH_SCENE_HPP

#include <IHSystem/settings.hpp>

namespace ih
{
  class Scenes;
  class CyclePack;

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

      friend class Scenes;
  };
}

#endif
