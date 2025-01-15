#include "../Colors.hpp"

#ifdef CF_INCLUDE_RAYLIB
  #include <raylib.h>
#endif

namespace ih
{
  Color3::Color3(const uint8& r,
                 const uint8& g,
                 const uint8& b)
  : r(r), g(g), b(b){}

  Color3& Color3::operator=(const Color& right)
  {
    r = right.r;
    g = right.g;
    b = right.b;
    return *this;
  }

  Color::Color(const uint8& r,
               const uint8& g,
               const uint8& b,
               const uint8& a)
  : Color3(r, g, b), a(a) {};

  Color& Color::operator=(const Color3& right)
  {
    r = right.r;
    g = right.g;
    b = right.b;
    return *this;
  }


  #ifdef RAYLIB_H
    Color3& Color3::operator=(const ::Color& right)
    {
      r = right.r;
      g = right.g;
      b = right.b;
      return *this;
    }
    
    Color3& Color3::operator=(const ::Color& right)
    {
      r = right.r;
      g = right.g;
      b = right.b;
      return *this;
    }
  #endif
}
