#ifndef IH_STATES_HPP
#define IH_STATES_HPP

#include <IHSystem/settings.hpp>

namespace ih
{
  enum BS : uint8
  {
    Enabled = 1 << 0,
    Visible = 1 << 1
  };
}

#endif
