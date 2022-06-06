#pragma once

#include <vector>
#include "src/Keyboard.h"
#include "src/Mouse.h"

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
      bindMouse();
      bindKeyboard();
      bindLogger();
      bindSDL();
      bindEntity();
      bindRegistry();
      bindMisc();
    }

    void Update() const {
      sol::function onUpdate = lua->sol["onUpdate"];
      onUpdate();
    }

  private:
    void bindRegistry() {
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
    }

    void bindEntity() {
      lua->sol.new_usertype<BoundingBoxComponent>(
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

      lua->sol.set_function(
          "entity_has_tag",
          [this](const Entity& entity, const std::string& tag) {
            return entity.HasTag(tag);
          }
      );
    }

    void bindSDL() const {
      lua->sol.set_function("sdl_get_ticks", &SDL_GetTicks);
    }

    void bindLogger() const {
      lua->sol.set_function("log", &Logger::Log);
      lua->sol.set_function("logError", &Logger::Err);
    }

    void bindMouse() const {
      lua->sol.set_function("mouse_move", &Mouse::move);
    }

    void bindKeyboard() const {
      lua->sol.set_function("press_arrow_up", &Keyboard::ArrowUp);
      lua->sol.set_function("press_arrow_right", &Keyboard::ArrowRight);
      lua->sol.set_function("press_arrow_down", &Keyboard::ArrowDown);
      lua->sol.set_function("press_arrow_left", &Keyboard::ArrowLeft);
    }

    void bindMisc() const {
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
};

