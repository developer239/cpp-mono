#pragma once

#include <filesystem>
#include "sol/sol.hpp"
#include "src/Logger.h"
#include "../components/BoundingBoxComponent.h"

class LuaState {
  public:
    sol::state sol;

    LuaState() {
      sol.open_libraries(sol::lib::base, sol::lib::package, sol::lib::math, sol::lib::os);
    }

    void LoadSolScript(std::string filePath) {
      auto status = std::filesystem::exists(filePath);

      if (!status) {
        Logger::Err("Couldn't Lua script from " + filePath);
        return;
      }

      sol::load_result script = sol.load_file(filePath);

      if (!script.valid()) {
        sol::error error = script;
        std::string errorMessage = error.what();

        Logger::Err("Lua script ( " + filePath + ") is not valid" + errorMessage);
        return;
      }

      script();
    }

    void LoadEntities(std::shared_ptr<Registry>& registry) {
      auto entities = sol["Level"]["entities"];

      int i = 0;
      while (true) {
        sol::optional<sol::table> hasEntity = entities[i];
        if (hasEntity == sol::nullopt) {
          break;
        }

        sol::table entity = entities[i];
        sol::optional<std::string> tag = entity["tag"];

        // Tag

        Entity newEntity = registry->CreateEntity();
        if (tag != sol::nullopt) {
          newEntity.Tag(entity["tag"]);
        }

        // Group

        sol::optional<std::string> group = entity["group"];
        if (group != sol::nullopt) {
          newEntity.Group(entity["group"]);
        }

        // Components

        sol::optional<sol::table> hasComponents = entity["components"];
        if (hasComponents != sol::nullopt) {

          // Bounding Box

          sol::optional<sol::table> transform = entity["components"]["boundingBox"];
          if (transform != sol::nullopt) {
            newEntity.AddComponent<BoundingBoxComponent>(
                entity["components"]["boundingBox"]["x"],
                entity["components"]["boundingBox"]["y"],
                entity["components"]["boundingBox"]["width"],
                entity["components"]["boundingBox"]["height"]
            );
          }
        }

        i++;
      }
    }
};
