#include "../Engine/EntitiesManager.hpp"

namespace ih
{
  entt::entity EntitiesManager::createEntity()
    { return registry.create(); }

  void EntitiesManager::destroyEntity(const entt::entity& entity)
    { registry.destroy(entity); }

  bool EntitiesManager::entityIsValid(const entt::entity& entity)
    { return registry.valid(entity); }

  template<typename Type, typename ...Args>
  decltype(auto) EntitiesManager::emplaceComponent(const entt::entity& entity, Args&&... args)
    { return registry.emplace<Type, Args...>(entity, args...); }

  template<typename Type, typename ...Other, typename ...Exclude>
  [[nodiscard]] decltype(auto) EntitiesManager::createView()
    { return registry.view<Type, Other..., Exclude...>();}

  template<typename Type, typename ...Other>
  size_t EntitiesManager::removeComponent(const entt::entity& entity)
    { return registry.emplace<Type, Other...>(entity); }

  template<typename ...Type>
  [[nodiscard]]decltype(auto) EntitiesManager::getComponent([[maybe_unused]] const entt::entity& entity)
    { return registry.get<Type...>(entity); }

  template<typename ...Type>
  [[nodiscard]] auto EntitiesManager::tryGetComponent([[maybe_unused]] const entt::entity& entity)
    { return registry.try_get<Type...>(entity); }

  template<typename ...Type>
  void EntitiesManager::clear()
    { registry.clear<Type...>(); }

  template<typename ...Type>
  [[nodiscard]] bool EntitiesManager::isAllOf([[maybe_unused]] const entt::entity& entity)
    { return registry.all_of<Type...>(entity); }
}
