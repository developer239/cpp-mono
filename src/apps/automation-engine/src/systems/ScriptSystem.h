#pragma once

#include <vector>

class ScriptSystem : public System {
  public:
    std::shared_ptr<Lua> lua;
    std::shared_ptr<Registry> registry;

    explicit ScriptSystem(
        std::shared_ptr<Lua>& lua,
        std::shared_ptr<Registry>& registry
    ) : lua(lua),
        registry(registry) {
    }

    void CreateLuaBindings() {
      //
      // SDL

      lua->sol.set_function("sdl_get_ticks", SDL_GetTicks);

      //
      // Registry

      // sol new user type vector with size

      sol::usertype<Entity> entityType = lua->sol.new_usertype<Entity>("entity", sol::constructors<Entity(int id)>());
      entityType["get_id"] = [](Entity& entity) { return entity.GetId(); };

      lua->sol.set_function(
          "get_entities_by_group",
          [this](const std::string& group) {
            return registry->GetEntitiesByGroup(group);
          }
      );
    }

    void Update() {
      sol::function onUpdate = lua->sol["onUpdate"];
      onUpdate();
    }
};

