#include "texture_manager.h"

std::unordered_map<std::string, Texture2D> TextureManager::textures;

Texture2D TextureManager::LoadTexture(const std::string& path) {
    if (textures.find(path) != textures.end()) {
        return textures[path];
    }
    Texture2D texture = ::LoadTexture(path.c_str());
    textures[path] = texture;
    return texture;
}

void TextureManager::UnloadTexture(Texture2D texture) {
    for (auto it = textures.begin(); it != textures.end(); ++it) {
        if (it->second.id == texture.id) {
            ::UnloadTexture(it->second);
            textures.erase(it);
            break;
        }
    }
}

Texture2D TextureManager::GetTexture(const std::string& path) {
    return textures[path];
}