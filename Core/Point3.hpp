#ifndef IH_POINT3_HPP
#define IH_POINT3_HPP

#include "Point2.hpp"

namespace ih
{
  template<typename Type>
  class Point3 : public Point2<Type>
  {
    public:
      Type z;

      Point3(const Type& x = 0,
             const Type& y = 0,
             const Type& z = 0);

      void set(const Type& x,
               const Type& y,
               const Type& z);
      
      #ifdef RAYLIB_H
        void operator=(const Vector2& right);
        void operator=(const Vector3& right);
        void operator=(const Vector4& right);
      #endif
  };

  using Point3f = Point3<float>;
  using Point3ub = Point3<uint8>;
}

#endif // !IH_POINT3_HPP
