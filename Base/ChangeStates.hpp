#ifndef IH_CHANGE_STATES_HPP
#define IH_CHANGE_STATES_HPP

#include <IHSystem/rst>

namespace ih
{
  struct ChangeStates
  {
    uint16 enabled;
    uint16 disabled;

    ChangeStates(const uint16& enabled,
                 const uint16& disabled);
  };
}

#endif
