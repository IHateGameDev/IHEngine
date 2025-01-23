#include "../../Core/Entities.hpp"

namespace ih
{
  entt::entity Entities::createEntity()
    { return registry.create(); }

  void Entities::destroyEntity(const entt::entity& entity)
    { registry.destroy(entity); }

  bool Entities::entityIsValid(const entt::entity& entity)
    { return registry.valid(entity); }

  template<typename Type, typename ...Args>
  decltype(auto) Entities::emplaceComponent(const entt::entity& entity, Args&&... args)
    { return registry.emplace<Type, Args...>(entity, args...); }

  template<typename Type, typename ...Other, typename ...Exclude>
  [[nodiscard]] decltype(auto) Entities::createView()
    { return registry.view<Type, Other..., Exclude...>();}

  template<typename Type, typename ...Other>
  size_t Entities::removeComponent(const entt::entity& entity)
    { return registry.emplace<Type, Other...>(entity); }

  template<typename ...Type>
  [[nodiscard]]decltype(auto) Entities::getComponent([[maybe_unused]] const entt::entity& entity)
    { return registry.get<Type...>(entity); }

  template<typename ...Type>
  [[nodiscard]] auto Entities::tryGetComponent([[maybe_unused]] const entt::entity& entity)
    { return registry.try_get<Type...>(entity); }

  template<typename ...Type>
  void Entities::clear()
    { registry.clear<Type...>(); }

  template<typename ...Type>
  [[nodiscard]] bool Entities::isAllOf([[maybe_unused]] const entt::entity& entity)
    { return registry.all_of<Type...>(entity); }
}
