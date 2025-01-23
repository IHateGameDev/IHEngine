#include "../../Core/Window.hpp"
#include <raylib.h>

namespace ih
{
  Window::Window(Vector2us size,
                 Vector2us position,
                 std::string titleName,
                 std::string iconPath, 
                 uint32 states)
  {
    InitWindow(size.x, size.y, titleName.c_str());
    SetWindowPosition(position.x, position.y);
    if (iconPath != "")
      SetWindowIcon(LoadImage(iconPath.c_str()));
  }

  Vector2us Window::getScreenSize()
    { return Vector2us(GetScreenWidth(), GetScreenHeight()); }
  
  Vector2us Window::getRenderSize()
    { return Vector2us(GetRenderWidth(), GetRenderHeight()); }
  
  void Window::setSize(const Vector2us& size)
    { SetWindowSize(size.x, size.y); }

  void Window::setMinSize(const Vector2us& size)
    { SetWindowMinSize(size.x, size.y); }

  void Window::setMaxSize(const Vector2us& size)
    { SetWindowMaxSize(size.x, size.y); }
  
  void Window::setPosition(const Vector2us& size)
    { SetWindowPosition(size.x, size.y); }
  
  Vector2us Window::getPosition()
    {
      ::Vector2 pos = GetWindowPosition();
      // return Vector2us(static_cast<uint16>(pos.x), static_cast<uint16>(pos.y));
      return Vector2us(pos.x, pos.y);
    }
    
  void Window::setTitle(const std::string& title)
    { SetWindowTitle(title.c_str()); }

  void Window::setStates(const uint32& states)
    { SetWindowState(states); }
    
  bool Window::isState(const uint32& state)
    { return IsWindowState(state); }
    
  void Window::disableState(const uint32& state)
    { return ClearWindowState(state); }
  
  bool Window::isShouldClose()
    { return WindowShouldClose(); }

  bool Window::isReady()
    { return IsWindowReady(); }
    
  bool Window::isFullscreen()
    { return IsWindowFullscreen(); }
  
  bool Window::isHidden()
    { return IsWindowHidden(); }
  
  bool Window::isMinimized()
    { return IsWindowMinimized(); }
  
  bool Window::isMaximized()
    { return IsWindowMaximized(); }
  
  bool Window::isFocused()
    { return IsWindowFocused(); }
  
  bool Window::isResized()
    { return IsWindowResized(); }

  void Window::setOpacity(const float& opacity)
    { SetWindowOpacity(opacity); }
  
  void Window::toggleFullscreen()
    { ToggleFullscreen(); }
  
  void Window::toggleBorderlessWindowed()
    { ToggleBorderlessWindowed(); }
  
  void Window::maximize()
    { MaximizeWindow(); }
  
  void Window::minimize()
    { MinimizeWindow(); }
  
  void Window::restore()
    { RestoreWindow(); }
}
