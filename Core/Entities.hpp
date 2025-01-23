#ifndef IH_ENTITIES_HPP
#define IH_ENTITIES_HPP

#include <IHSystem/settings.hpp>
#include <entt/entity/registry.hpp>

namespace ih
{
  class Entities
  {
    private:
      entt::registry registry;

    public:
      entt::entity createEntity();
      void destroyEntity(const entt::entity& entity);
      bool entityIsValid(const entt::entity& entity);

      template<typename Type, typename ...Args>
      decltype(auto) emplaceComponent(const entt::entity& entity, Args&&... args);

      template<typename Type, typename ...Other, typename ...Exclude>
      [[nodiscard]] decltype(auto) createView();

      template<typename Type, typename ...Other>
      size_t removeComponent(const entt::entity& entity);

      template<typename ...Type>
      [[nodiscard]] inline decltype(auto) getComponent([[maybe_unused]] const entt::entity& entity);
      
      template<typename ...Type>
      [[nodiscard]] auto tryGetComponent([[maybe_unused]] const entt::entity& entity);
      
      template<typename ...Type>
      void clear();
      
      template<typename ...Type>
      [[nodiscard]] bool isAllOf([[maybe_unused]]const entt::entity& entity);

      /////////DANGER ZONE!!!//////
      entt::registry& DANGER_getRegistry()
      { return registry; }
  };
}

#endif // !IH_ENTITIES_HPP
