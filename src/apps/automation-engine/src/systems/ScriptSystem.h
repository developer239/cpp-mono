#pragma once

#include <vector>
#include "src/Keyboard.h"

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
      // Keyboard
      lua->sol.set_function("press_arrow_up", &Keyboard::ArrowUp);
      lua->sol.set_function("press_arrow_right", &Keyboard::ArrowRight);
      lua->sol.set_function("press_arrow_down", &Keyboard::ArrowDown);
      lua->sol.set_function("press_arrow_left", &Keyboard::ArrowLeft);

      //
      // Logger

      lua->sol.set_function("log", &Logger::Log);
      lua->sol.set_function("logError", &Logger::Err);

      //
      // SDL

      lua->sol.set_function("sdl_get_ticks", &SDL_GetTicks);

      //
      // Entity
      sol::usertype<BoundingBoxComponent> boundingBoxType = lua->sol.new_usertype<BoundingBoxComponent>(
          "BoundingBoxComponent",
          "width", &BoundingBoxComponent::width,
          "height", &BoundingBoxComponent::height,
          "positionX", &BoundingBoxComponent::positionX,
          "positionY", &BoundingBoxComponent::positionY
      );

      lua->sol.set_function(
          "get_entity_bounding_box",
          [this](const Entity& entity) {
            return entity.GetComponent<BoundingBoxComponent>();
          }
      );

      //
      // Registry

      lua->sol.set_function(
          "get_entity_by_tag",
          [this](const std::string& tag) {
            return registry->GetEntityByTag(tag);
          }
      );

      lua->sol.set_function(
          "get_entities_by_group",
          [this](const std::string& group) {
            return registry->GetEntitiesByGroup(group);
          }
      );

      //
      // Misc

      lua->sol.set_function(
          "check_aabb_collision",
          [](
              double aX,
              double aY,
              double aW,
              double aH,
              double bX,
              double bY,
              double bW,
              double bH
          ) {
            return (
                aX < bX + bW &&
                aX + aW > bX &&
                aY < bY + bH &&
                aY + aH > bY
            );
          });
    }

    void Update() {
      sol::function onUpdate = lua->sol["onUpdate"];
      onUpdate();
    }
};

