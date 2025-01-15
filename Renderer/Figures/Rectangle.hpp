#ifndef IH_RECTANGLE_HPP
#define IH_RECTANGLE_HPP

#include "Figure.hpp"
#include <IHMTypes/Point2.hpp>

namespace ih
{
  class Rectangle : public Figure
  {
    sf::VertexArray vertices;

    public:
      Rectangle(DrawnObject* c, const ih::Point2f& size) : Figure(c)
      {
        vertices.setPrimitiveType(sf::TriangleStrip);
        vertices.resize(4);

        vertices[0].position = sf::Vector2f(0, 0);
        vertices[1].position = sf::Vector2f(0, size.y);
        vertices[2].position = sf::Vector2f(size.x, 0);
        vertices[3].position = sf::Vector2f(size.x, size.y);
      }

    protected:
      void draw(sf::RenderTarget& target, sf::RenderStates states) const override
      { target.draw(vertices, states); }
  };
}

#endif
