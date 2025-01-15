#ifndef IH_POINT2_HPP
#define IH_POINT2_HPP

#include <IHSystem/settings.hpp>

namespace ih
{
  template<typename Type>
  class Point2
  {
    public:
      Type x, y;

      Point2(const Type& x = 0, const Type& y = 0);

      void set(const Type& x, const Type& y);

      #ifdef RAYLIB_H
        Point2<Type>& operator=(const Vector2& right);
        Point2<Type>& operator=(const Vector3& right);
        Point2<Type>& operator=(const Vector4& right);
      #endif
  };

  using Point2f = Point2<float>;
  using Point2us = Point2<uint16>;
  using Point2ui = Point2<uint32>;
}

#endif // !IH_POINT2_HPP
