#include "../Engine/Engine.hpp"
#include <raylib.h>

namespace ih
{
  #ifdef LOGGER
    Engine::Engine(Point2us size,
                   std::string title,
                   uint32 windowFlags,
                   std::string logPath,
                   uint8 logLevel)
    :logger(logPath, logLevel)
  #else
    Engine::Engine(Point2us size,
                   std::string title,
                   uint32 windowFlags)
  #endif
  {
    InitWindow(size.x, size.y, title.c_str());
    SetWindowState(windowFlags);
  }

  void Engine::start()
  {
    sceneManager.awake();
    sceneManager.start();
  }

  void Engine::update()
    { sceneManager.update(); }

  void Engine::render()
  {
    BeginDrawing();
    ClearBackground(BLACK);
    sceneManager.render();
    EndDrawing();
  }
}
