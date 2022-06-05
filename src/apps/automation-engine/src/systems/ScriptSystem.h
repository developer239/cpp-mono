#pragma once

class ScriptSystem : public System {
  public:
    std::shared_ptr<Lua> lua;

    explicit ScriptSystem(std::shared_ptr<Lua>& lua) : lua(lua) {
    }

    void CreateLuaBindings() {
    }

    void Update() {
      sol::function onUpdate = lua->sol["onUpdate"];
      onUpdate();
    }
};

