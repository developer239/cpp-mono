#pragma once

#include <filesystem>
#include "sol/sol.hpp"
#include "src/Logger.h"
#include "../components/BoundingBoxComponent.h"

class Lua {
  public:
    sol::state sol;

    Lua() {
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

    std::tuple<int, int> LoadWindowPosition(std::shared_ptr<AppState>& state) {
      auto level = sol["Level"];

      state->windowX = level["window"]["windowX"];
      state->windowY = level["window"]["windowY"];
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

    void LoadTargets(std::shared_ptr<AppState>& state) {
      auto targets = sol["Level"]["targets"];

      int i = 0;
      while (true) {
        sol::optional<sol::table> hasTarget = targets[i];
        if (hasTarget == sol::nullopt) {
          break;
        }

        sol::table target = targets[i];

        state->targets.push_back(Target{
            target["tag"],
            DetectColorsArguments{
                target["detectColors"]["lowerRed"],
                target["detectColors"]["lowerGreen"],
                target["detectColors"]["lowerBlue"],
                target["detectColors"]["upperRed"],
                target["detectColors"]["upperGreen"],
                target["detectColors"]["upperBlue"],
                target["detectColors"]["minWidth"],
                target["detectColors"]["minHeight"]
            },
            ErodeDilateArguments{
                target["erodeDilate"]["width"],
                target["erodeDilate"]["height"]
            }
        });

        i++;
      }
    }
};
