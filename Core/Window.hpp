#ifndef IH_WINDOW_HPP
#define IH_WINDOW_HPP

#include "../Math/Vector2.hpp"
#include <string>

namespace ih
{
  class Window
  {
    public:
      Window(Vector2us size,
             Vector2us position,
             std::string titleName,
             std::string iconPath,
             uint32 states);

      Vector2us getScreenSize();
      Vector2us getRenderSize();
      
      void setSize(const Vector2us& size);
      void setMinSize(const Vector2us& size);
      void setMaxSize(const Vector2us& size);
      void setPosition(const Vector2us& size);
      Vector2us getPosition();
      void setTitle(const std::string& title);

      void setStates(const uint32& states = 0);
      bool isState(const uint32& state);
      void disableState(const uint32& state);
      
      bool isShouldClose();
      bool isReady();
      bool isFullscreen();
      bool isHidden();
      bool isMinimized();
      bool isMaximized();
      bool isFocused();
      bool isResized();

      void setOpacity(const float& opacity = 1.f);
      
      void toggleFullscreen();
      void toggleBorderlessWindowed();
      void maximize();
      void minimize();
      void restore();
  };
}

#endif // !IH_WINDOW_HPP
