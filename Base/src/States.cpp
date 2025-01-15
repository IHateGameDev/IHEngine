#include "../States.hpp"

namespace ih
{
  States::States(const uint16& states) : states(states) {}
 
  void States::setState(const uint16& state, const bool& conditionState)
  {
    if (conditionState)
      states |= state;
    else
      states &= ~state;
  }

  void States::setState(BaseState state, const bool& conditionState)
  { setState(static_cast<uint16>(state), conditionState); }

  bool States::getState(const uint16& state) const
  { return (states & state) != 0; }

  bool States::getState(BaseState state) const
  { return getState(static_cast<uint16>(state)); }
}
