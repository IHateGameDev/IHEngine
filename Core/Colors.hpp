#ifndef IH_COLORS_HPP
#define IH_COLORS_HPP

#include <IHSystem/settings.hpp>

namespace ih
{
  class Color;

  class Color3
  {
    public:
      uint8 r, g, b;

      Color3(const uint8& r = 0,
             const uint8& g = 0,
             const uint8& b = 0);

      
      Color3& operator=(const Color& right);

      #ifdef RAYLIB_H
        Color3& operator=(const ::Color& right);
      #endif
  };
  
  class Color : public Color3
  {
    public:
      uint8 a;

      Color(const uint8& r,
            const uint8& g,
            const uint8& b,
            const uint8& a);

      Color& operator=(const Color3& right);

      #ifdef RAYLIB_H
        Color& operator=(const ::Color& right);
      #endif
  };
}

#endif // !IH_COLORS_HPP
