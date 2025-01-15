#include "../Engine/Scene.hpp"

namespace ih
{
  Scene::Scene(uint16 count, CyclePack** packs): cyclePackCount(count), cyclePacks(new CyclePack*[count])
  {
    for (uint16 i = 0; i < count; ++i)
      cyclePacks[i] = packs[i];
  }

  Scene::~Scene()
  {
    for (uint16 i = 0; i < cyclePackCount; ++i)
      delete cyclePacks[i];
      
    delete[] cyclePacks;
  }

  void Scene::awake()
  {
    for (uint16 i = 0; i < cyclePackCount; ++i)
      cyclePacks[i]->awake();
  }

  void Scene::start()
  {
    for (uint16 i = 0; i < cyclePackCount; ++i)
      cyclePacks[i]->start();
  }

  void Scene::update()
  {
    for (uint16 i = 0; i < cyclePackCount; ++i)
      cyclePacks[i]->update();
  }

  void Scene::render()
  {
    for (uint16 i = 0; i < cyclePackCount; ++i)
      cyclePacks[i]->render();
  }

  void Scene::exit()
  {
    for (uint16 i = 0; i < cyclePackCount; ++i)
      cyclePacks[i]->exit();
  }
}
