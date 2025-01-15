#ifndef IH_SCENE_MANAGER_HPP
#define IH_SCENE_MANAGER_HPP

#include "Scene.hpp"
#include <vector>

namespace ih
{
  class Engine;

  class SceneManager
  {
    private:
      std::vector<Scene> scenes;
      uint16 currentScene = 0;

      void awake();
      void start();
      void update();
      void render();
      void exit();

    #ifdef LOGGER
      Logger& logger;
    #endif
    
    public:
    #ifdef LOGGER
      SceneManager(Logger& logger);
    #endif
      bool isValid(const uint16& index);
      [[nodiscard]] Scene& createScene(uint16 count, CyclePack** packs);
      uint16 setScene(const uint16& index);
      [[nodiscard]] Scene& getScene(const uint16& index);
      [[nodiscard]] Scene* tryGetScene(const uint16& index);

      [[nodiscard]] Scene& getCurrentScene();
      const uint16& getCurrentSceneIndex();

      friend class Engine;
  };
}

#endif
