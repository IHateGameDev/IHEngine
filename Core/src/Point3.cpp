#include "../Point3.hpp"

#ifdef CF_INCLUDE_RAYLIB
  #include <raylib.h>
#endif

namespace ih
{
  template<typename Type>
  Point3<Type>::Point3(const Type& x, const Type& y, const Type& z)
  { set(x, y, z); }

  template<typename Type>
  void Point3<Type>::set(const Type& x, const Type& y, const Type& z)
  {
    Point2<Type>::set(x, y);
    this->z = z;
  }

  #ifdef RAYLIB_H
    template<typename Type>
    Point3<Type>& Point3<Type>::operator=(const Vector2& right)
    {
      Point2<Type>::set(right.x, right.y);
      return *this;
    }

    template<typename Type>
    Point3<Type>& Point3<Type>::operator=(const Vector3& right)
    {
      set(right.x, right.y, right.z);
      return *this;
    }

    template<typename Type>
    Point3<Type>& Point3<Type>::operator=(const Vector4& right)
    {
      set(right.x, right.y, right.z);
      return *this;
    }
  #endif
}
