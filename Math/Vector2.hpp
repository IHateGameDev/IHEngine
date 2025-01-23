#ifndef IH_VECTOR2_HPP
#define IH_VECTOR2_HPP

#include <IHSystem/settings.hpp>

namespace ih
{
  template<typename Type>
  class Vector2
  {
  public:
    Type x, y;

    Vector2(const Type& x = Type(0),
            const Type& y = Type(0))
    : x(x), y(y) {}
  };

  using Vector2f = Vector2<float>;
  using Vector2us = Vector2<uint16>;
  using Vector2ui = Vector2<uint32>;
}

#endif
