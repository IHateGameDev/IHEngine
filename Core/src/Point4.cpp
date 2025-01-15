#include "../Point4.hpp"

#ifdef CF_INCLUDE_RAYLIB
  #include <raylib.h>
#endif

namespace ih
{
  template<typename Type>
  Point4<Type>::Point4(const Type& x, const Type& y, const Type& z, const Type& w)
  { set(x, y, z, w); }

  template<typename Type>
  void Point4<Type>::set(const Type& x, const Type& y, const Type& z, const Type& w)
  {
    Point3<Type>::set(x, y, z);
    this->w = w;
  }

  #ifdef RAYLIB_H
    template<typename Type>
    Point4<Type>& Point4<Type>::operator=(const Vector2& right)
    {
      Point2<Type>::set(right.x, right.y);
      return *this;
    }

    template<typename Type>
    Point4<Type>& Point4<Type>::operator=(const Vector3& right)
    {
      Point3<Type>::set(right.x, right.y, right.z);
      return *this;
    }

    template<typename Type>
    Point4<Type>& Point4<Type>::operator=(const Vector4& right)
    {
      set(right.x, right.y, right.z, right.w);
      return *this;
    }
  #endif
}
