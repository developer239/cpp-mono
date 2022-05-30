#include <SDL_image.h>
#include <filesystem>
#include "src/Logger.h"
#include "AssetStore.h"

AssetStore::AssetStore() {
  Logger::Log("AssetStore constructor called!");
}

AssetStore::~AssetStore() {
  ClearAssets();
  Logger::Log("AssetStore destructor called!");
}

void AssetStore::ClearAssets() {
  for (const auto& texture: textures) {
    SDL_DestroyTexture(texture.second);
  }
  textures.clear();

  for (const auto& font: fonts) {
    TTF_CloseFont(font.second);
  }
  fonts.clear();
}

void AssetStore::AddTexture(SDL_Renderer* renderer, const std::string& assetId, const std::string& filePath) {
  SDL_Surface* surface = IMG_Load(filePath.c_str());
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);

  textures.emplace(assetId, texture);

  Logger::Log("Texture added to the AssetStore with id " + assetId);
}

SDL_Texture* AssetStore::GetTexture(const std::string& assetId) {
  return textures[assetId];
}

void AssetStore::AddFont(const std::string& assetId, const std::string& filePath, int fontSize) {
  // check if file in filePath exists
  auto status = std::filesystem::exists(filePath);
  if (!status) {
    Logger::Err("Couldn't load font " + assetId + " from " + filePath);
    return;
  }

  fonts.emplace(assetId, TTF_OpenFont(filePath.c_str(), fontSize));
}

TTF_Font* AssetStore::GetFont(const std::string& assetId) {
  return fonts[assetId];
}
