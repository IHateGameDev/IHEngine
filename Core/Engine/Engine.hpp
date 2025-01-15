#ifndef IH_ENGINE_HPP
#define IH_ENGINE_HPP

#include "../Point2.hpp"
#include "SceneManager.hpp"
#include "EntitiesManager.hpp"

#ifdef LOGGER
  #include <IHSystem/Logger.hpp>
  #include <IHSystem/FileSystem.hpp>
#endif

namespace ih
{
  class Engine
  {
    public:
      #ifdef LOGGER
        Logger logger;
      #endif

      SceneManager sceneManager;
      EntitiesManager entitiesManager;

      #ifdef LOGGER
        Engine(Point2us size,
               std::string title,
               uint32 windowFlags,
               std::string logPath);
      #else
        Engine(Point2us size,
               std::string title,
               uint32 windowFlags);
      #endif
      ~Engine();

      void start();
      inline void update();
      inline void render();
      void exit();
    };
}
#endif
