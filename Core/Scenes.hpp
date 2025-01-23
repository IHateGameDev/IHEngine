#ifndef IH_SCENES_HPP
#define IH_SCENES_HPP

#include "Scene.hpp"
#include <vector>

namespace ih
{
  class Scenes
  {
    private:
      std::vector<Scene> scenes;
      uint16 currentScene = 0;

    #ifdef LOGGER
      Logger& logger;
    #endif
    
    public:
      void awake();
      void start();
      void update();
      void render();
      void exit();
    #ifdef LOGGER
      Scenes(Logger& logger);
    #endif
      bool isValid(const uint16& index);
      void createScene(uint16 count, CyclePack** packs);
      uint16 setScene(const uint16& index);
      [[nodiscard]] Scene& getScene(const uint16& index);
      [[nodiscard]] Scene* tryGetScene(const uint16& index);

      [[nodiscard]] Scene& getCurrentScene();
      const uint16& getCurrentSceneIndex();
  };
}

#endif
