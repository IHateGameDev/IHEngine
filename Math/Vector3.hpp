#ifndef IH_VECTOR3_HPP
#define IH_VECTOR3_HPP

#include "Vector2.hpp"

namespace ih
{
  template<typename Type>
  class Vector3 : public Vector2<Type>
  {
    public:
      Type z;

      Vector3(const Type& x = Type(0),
              const Type& y = Type(0),
              const Type& z = Type(0))
      : Vector2<Type>(x, y), z(z){}
  };

  using Vector3f = Vector3<float>;
  using Vector3ub = Vector3<uint8>;
}

#endif
