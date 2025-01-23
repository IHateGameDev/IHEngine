#include "../../Core/WrapperOfManagers.hpp"

ih::WrapperOfManagers::WrapperOfManagers(Scenes& scenes,
                                         Entities& entities,
                                         Window& window,
                                         Monitor& monitor,
                                         Time& time)
: scenes(scenes), entities(entities), window(window), monitor(monitor), time(time){}
