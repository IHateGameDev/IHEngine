#include "../StatesChanger.hpp"
#include "../States.hpp"
#include "../ChangeStates.hpp"
#include "../ChangeState.hpp"

namespace ih
{
  StatesChanger::StatesChanger(Engine& engine): BasicSystem(engine) {}

  void StatesChanger::update()
  {
    auto view = engine.createView<States, ChangeStates>();

    for (const entt::entity& entity : view)
    {
      States& states = engine.getComponent<States>(entity);
      const ChangeStates& changeStates = engine.getComponent<ChangeStates>(entity);

      states.setState(changeStates.enabled, true);
      states.setState(changeStates.disabled, false);

      engine.removeComponent<States>(entity);
      engine.removeComponent<ChangeStates>(entity);
    }

    view = engine.createView<States, DisableState>();

    for (const entt::entity& entity : view)
    {
      States& states = engine.getComponent<States>(entity);
      const DisableState& disableStates = engine.getComponent<DisableState>(entity);

      states.setState(1 << disableStates.offset, false);

      engine.removeComponent<States>(entity);
      engine.removeComponent<DisableState>(entity);
    }

    view = engine.createView<States, EnableState>();

    for (const entt::entity& entity : view)
    {
      States& states = engine.getComponent<States>(entity);
      const EnableState& enableStates = engine.getComponent<EnableState>(entity);

      states.setState(1 << enableStates.offset, true);

      engine.removeComponent<States>(entity);
      engine.removeComponent<EnableState>(entity);
    }
  }
}
