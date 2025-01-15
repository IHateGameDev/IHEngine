#ifndef IH_FIGURE_HPP
#define IH_FIGURE_HPP

#include "../DrawnObject.hpp"

namespace ih
{
  class Figure : public DrawnObject
  {
    protected:
      DrawnObject* drawnObject;

    public:
      Figure(DrawnObject* c): drawnObject(c) {}
  };
}

#endif
