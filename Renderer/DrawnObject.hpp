#ifndef IH_DRAWN_OBJECT_HPP
#define IH_DRAWN_OBJECT_HPP

#include <SFML/Graphics.hpp>

namespace ih
{
  class DrawnObject : public sf::Drawable
  {
    protected:
      virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
      virtual void drawStates(sf::RenderStates& states) const;

    public:
      virtual ~DrawnObject() = default;
  };

#if __cplusplus >= 2020
  template <typename T>
  concept suitableForDrawing = std::is_base_of_v<DrawnObject, T>;
#endif
}

#endif
