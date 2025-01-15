#include "../Point2.hpp"

#ifdef CF_INCLUDE_RAYLIB
  #include <raylib.h>
#endif

namespace ih
{
  template<typename Type>
  Point2<Type>::Point2(const Type& x, const Type& y)
  { set(x, y); }

  template<typename Type>
  void Point2<Type>::set(const Type& x, const Type& y)
  {
    this->x = x;
    this->y = y;
  }

  #ifdef RAYLIB_H
    template<typename Type>
    Point2<Type>& Point2<Type>::operator=(const Vector2& right)
    {
      set(right.x, right.y);
      return *this;
    }

    template<typename Type>
    Point2<Type>& Point2<Type>::operator=(const Vector3& right)
    {
      set(right.x, right.y);
      return *this;
    }

    template<typename Type>
    Point2<Type>& Point2<Type>::operator=(const Vector4& right)
    {
      set(right.x, right.y);
      return *this;
    }
  #endif
}
