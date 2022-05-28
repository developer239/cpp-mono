#pragma once

#include <map>
#include <typeindex>
#include <list>
#include "Event.h"

namespace Events {
  typedef std::list<std::unique_ptr<IEventCallback>> HandlerList;

  class Bus {
    private:
      std::map<std::type_index, std::unique_ptr<HandlerList>> subscribers;

      HandlerList* GetList(std::type_index type);

      bool ShouldCreateList(std::type_index type);

      void CreateList(std::type_index type);

      void AddItem(std::type_index type, std::unique_ptr<IEventCallback> subscriber);

    public:
      void Reset();

      template<typename TEvent, typename TOwner>
        void SubscribeToEvent(TOwner* ownerInstance, void (TOwner::*callbackFunction)(TEvent&)) {
          if (ShouldCreateList(typeid(TEvent))) {
            CreateList(typeid(TEvent));
          }

          AddItem(
              typeid(TEvent),
              std::make_unique<EventCallback<TOwner, TEvent>>(
                  ownerInstance,
                  callbackFunction
              )
          );
        }

      template<typename TEvent, typename ...TArgs>
        void EmitEvent(TArgs&& ...args) {
          auto handlers = GetList(typeid(TEvent));

          if (handlers) {
            for (auto& it: *handlers) {
              auto handler = it.get();

              TEvent event(std::forward<TArgs>(args)...);
              handler->Execute(event);
            }
          }
        }
  };
}