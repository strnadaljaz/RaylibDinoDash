#pragma once

#include <raylib.h>
#include <unordered_map>
#include <string>

class TextureManager {
public:
    static Texture2D LoadTexture(const std::string& path);
    static void UnloadTexture(Texture2D texture);
    static Texture2D GetTexture(const std::string& path);

private:
    static std::unordered_map<std::string, Texture2D> textures;
};