#ifndef IH_RENDERER_HPP
#define IH_RENDERER_HPP

#include "../Base/BasicSystem.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <entt/entity/fwd.hpp>
#include "../Base/States.hpp"
namespace ih
{
  template <typename Type>
  concept suitableForDrawing = std::is_base_of_v<sf::Drawable, Type>;

  class Renderer : public BasicSystem
  {
    private:
      sf::RenderWindow& window;

    public:
      Renderer(Engine& engine): BasicSystem(engine), window(engine.DANGER_getWindow()){}

      bool checkForDraw(const entt::entity& entity)
      {
        States& states = engine.getComponent<States>(entity);
        return states.getState(BaseState::Enable) && states.getState(BaseState::Visible);
      }
      
      //It works on standard types from SFML and based on its principles like sf::RectangleShape and looks like this [window.draw(yourComponent);]
      template <suitableForDrawing Type>
      void draw()
      {
        auto view = engine.createView<Type, States>();

        for (entt::entity entity : view)
          if (checkForDraw(entity))
            window.draw(engine.getComponent<Type>(entity));
      }
  };
}

#endif
