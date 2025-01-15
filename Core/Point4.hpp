#ifndef IH_POINT4_HPP
#define IH_POINT4_HPP

#include "Point3.hpp"

namespace ih
{
  template<typename Type>
  class Point4 : public Point3<Type>
  {
    public:
      Type w;

      Point4(const Type& x = 0,
             const Type& y = 0,
             const Type& z = 0,
             const Type& w = 0);

      void set(const Type& x,
               const Type& y,
               const Type& z,
               const Type& w);

      #ifdef RAYLIB_H
        void operator=(const Vector2& right);
        void operator=(const Vector3& right);
        void operator=(const Vector4& right);
      #endif
  };

  using Point4f = Point4<float>;

}

#endif // !IH_POINT4_HPP
