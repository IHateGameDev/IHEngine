#ifndef IH_VECTOR4_HPP
#define IH_VECTOR4_HPP

#include "Vector3.hpp"

namespace ih
{
  template<typename Type>
  class Vector4 : public Vector3<Type>
  {
    public:
      Type w;

      Vector4(const Type& x = Type(0),
              const Type& y = Type(0),
              const Type& z = Type(0),
              const Type& w = Type(0))
      : Vector3<Type>(x, y, z), w(w){}
  };

  using Vector4f = Vector4<float>;

}

#endif
