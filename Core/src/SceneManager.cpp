#include "../Engine/SceneManager.hpp"
#include <stdexcept>

namespace ih
{
  #ifdef LOGGER
    SceneManager(Logger& logger): logger(logger){};
  #endif

  void SceneManager::awake()
  {
    if (scenes.empty())
      throw std::runtime_error("Core::Engine -> No scenes available to start");
  
    #ifdef LOGGER
      logger.info("Core::SceneManager::awake -> Method has started", 6);
    #endif
    
    for (uint16 i=0; i < scenes.size(); i++)
    {
      scenes[i].awake();
      
      #ifdef LOGGER
        logger.info("Core::SceneManager::awake::"+std::to_string(i)+" -> Completed successfully", 9);
      #endif
    }
    #ifdef LOGGER
      logger.info("Core::SceneManager::awake -> Method has ended", 6);
    #endif
  }

  void SceneManager::start()
  {
    #ifdef LOGGER
      logger.info("Core::SceneManager::start -> Method has started", 6);
    #endif

    getCurrentScene().start();
    
    #ifdef LOGGER
      logger.info("Core::SceneManager::start -> Method has ended", 6);
    #endif
  }

  void SceneManager::update()
  {
    #ifdef LOGGER
      logger.info("Core::SceneManager::update -> Method has started", 6);
    #endif

    getCurrentScene().update();
    
    #ifdef LOGGER
      logger.info("Core::SceneManager::update -> Method has ended", 6);
    #endif
  }

  void SceneManager::render()
  {
    #ifdef LOGGER
      logger.info("Core::SceneManager::render -> Method has started", 6);
    #endif

    getCurrentScene().render();
    
    #ifdef LOGGER
      logger.info("Core::SceneManager::render -> Method has ended", 6);
    #endif
  }

  void SceneManager::exit()
  {
    #ifdef LOGGER
      logger.info("Core::SceneManager::exit -> Method has started", 6);
    #endif

    getCurrentScene().exit();
    
    #ifdef LOGGER
      logger.info("Core::SceneManager::exit -> Method has ended", 6);
    #endif
  }

  bool SceneManager::isValid(const uint16& index)
  {
    bool res = index < scenes.size();
    
    #ifdef LOGGER
      if (!res)
        logger.error("Core::SceneManager -> Invalid scene index: "+std::to_string(index));
      
      logger.info("Core::SceneManager -> Max scene index: "+std::to_string(scenes.size()), 10);
    #endif
    
    return res;
  }

  [[nodiscard]] Scene& SceneManager::createScene(uint16 count, CyclePack** packs)
    { return scenes.emplace_back(count, packs); }

  uint16 SceneManager::setScene(const uint16& index)
  {
    if (isValid(index))
    {
      getCurrentScene().exit();
      currentScene = index;
      getCurrentScene().start();
    }
    #ifdef LOGGER
      else
        logger.info("Core::SceneManager::setScene -> The scene remains the same", 10);
    #endif
    
    return currentScene;
  }

  [[nodiscard]] Scene& SceneManager::getScene(const uint16& index)
  {
    if (isValid(index))
      return scenes.at(index);
      
    throw std::out_of_range("^^^ Core::SceneManager::getScene -> For return need ref");
  }

  [[nodiscard]] Scene* SceneManager::tryGetScene(const uint16& index)
  {
    if (isValid(index))
      return &scenes.at(index);

    #ifdef LOGGER
      logger.warning("^^^ Core::SceneManager::tryGetScene -> Failed to get scene", 5);
    #endif

    return nullptr;
}

  [[nodiscard]] Scene& SceneManager::getCurrentScene()
    { return scenes.at(currentScene); }
    
  const uint16& SceneManager::getCurrentSceneIndex()
    { return currentScene; }
}
