#include "AssetStore.h"

AssetStore::AssetStore() = default;

AssetStore::~AssetStore() {
  ClearAssets();
}

void AssetStore::ClearAssets() {
  for (const auto& font: fonts) {
    TTF_CloseFont(font.second);
  }
  fonts.clear();
}

void AssetStore::AddFont(const std::string& assetId, const std::string& filePath, const int fontSize) {
  fonts.emplace(assetId, TTF_OpenFont(filePath.c_str(), fontSize));
}

TTF_Font* AssetStore::GetFont(const std::string& assetId) {
  return fonts[assetId];
}
