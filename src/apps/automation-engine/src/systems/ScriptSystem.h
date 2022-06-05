#pragma once

class ScriptSystem : public System {
  public:
    ScriptSystem() = default;

    void CreateLuaBindings(std::shared_ptr<Lua>& lua) {
    }

    void Update() {

    }
};

