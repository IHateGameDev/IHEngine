#ifndef TEST_PACK_HPP
#define TEST_PACK_HPP

#include <IHEngine/Core/CyclePack.hpp>
#include <raylib.h>

class TestPack: public ih::CyclePack
{
  public:
    TestPack(ih::WrapperOfManagers& wom): ih::CyclePack(wom){}
    
  public:
    void render() override
    {
      ClearBackground(WHITE);
      DrawFPS(50, 50);
    }
};

#endif
