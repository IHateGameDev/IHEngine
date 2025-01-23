#include "Scripts/CyclePacks/TestPack.hpp"
#include <iostream>

int main()
{
  ih::Scenes scenes;
  ih::Entities entities;
  ih::Window window(
    ih::Vector2us(1920, 1080),
    ih::Vector2us(),
    "TestCore",
    "",
    0
  );
  ih::Monitor monitor;
  ih::Time time;
  time.setTargetFPS(60);
  
  ih::WrapperOfManagers wom(scenes, entities, window, monitor, time);

  scenes.createScene(1, new ih::CyclePack*[](new TestPack(wom)));

  scenes.awake();
  scenes.start();

  while (!window.isShouldClose())
  {
    scenes.update();
    scenes.render();
  }
  
  return 0;
}
