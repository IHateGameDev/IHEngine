#include "../../Core/CyclePack.hpp"

ih::CyclePack::CyclePack(WrapperOfManagers& wom)
  : scenes(wom.scenes), entities(wom.entities), window(wom.window), monitor(wom.monitor), time(wom.time){}
