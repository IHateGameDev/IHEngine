#ifndef IH_EVENTS_PACK_HPP
#define IH_EVENTS_PACK_HPP

#include <SFML/Window/Event.hpp>

namespace ih
{
  class EventsPack
  {
    public:
      virtual void keyPressed(const sf::Event& event){};
      virtual void keyReleased(const sf::Event& event){};
      virtual void textEntered(const sf::Event& event){};

      virtual void mouseLeft(const sf::Event& event){};
      virtual void mouseMoved(const sf::Event& event){};
      virtual void mouseEntered(const sf::Event& event){};

      virtual void mouseWheelMoved(const sf::Event& event){};
      virtual void mouseWheelScrolled(const sf::Event& event){};
      
      virtual void mouseButtonPressed(const sf::Event& event){};
      virtual void mouseButtonReleased(const sf::Event& event){};
      
      virtual void touchMoved(const sf::Event& event){};
      virtual void touchEnded(const sf::Event& event){};
      virtual void touchBegan(const sf::Event& event){};
      virtual void sensorChanged(const sf::Event& event){};

      virtual void joystickMoved(const sf::Event& event){};
      virtual void joystickConnected(const sf::Event& event){};
      virtual void joystickDisconnected(const sf::Event& event){};

      virtual void joystickButtonPressed(const sf::Event& event){};
      virtual void joystickButtonReleased(const sf::Event& event){};

      virtual void closed(const sf::Event& event){};
      virtual void resized(const sf::Event& event){};
      virtual void lostFocus(const sf::Event& event){};
      virtual void gainedFocus(const sf::Event& event){};
  };
}

#endif // !IH_EVENTS_PACK_HPP
