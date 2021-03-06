/*******************************************************************
** Taken and adapted from learnopengl.com (part of a Breakout game) 
******************************************************************/
#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <string>

#include <GL/glew.h>
#include <SDL/SDL_mixer.h>

#include "texture.h"
#include "shader.h"
#include "model.h"


// A static singleton ResourceManager class that hosts several
// functions to load Textures and Shaders. Each loaded texture
// and/or shader is also stored for future reference by string
// handles. All functions and resources are static and no 
// public constructor is defined.
class ResourceManager
{
public:
    // Resource storage
    static std::map<std::string, Shader>     Shaders;
    static std::map<std::string, Texture2D>  Textures;
    static std::map<std::string, Texture3D>  Cubemaps;
    static std::map<std::string, Model>      Models;
    static std::map<std::string, Mix_Music*> Musics;
    static std::map<std::string, Mix_Chunk*> Sons;
    // Loads (and generates) a shader program from file loading vertex, fragment (and geometry) shader's source code. If gShaderFile is not nullptr, it also loads a geometry shader
    static Shader   LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name);
    // Retrieves a stored sader
    static Shader   GetShader(std::string name);
    // Loads (and generates) a texture from file
    static Texture2D LoadTexture(const GLchar *file, GLboolean alpha, GLboolean repeat, std::string name);
    // Retrieves a stored texture
    static Texture2D GetTexture(std::string name);
    // Loads (and generates) a cubemaps from file
    static Texture3D LoadCubemap(vector<const GLchar*> faces, std::string name);
    // Retrieves a stored cubemaps
    static Texture3D GetCubemap(std::string name);
    // Loads (and generates) a model from file
    static Model LoadModel(std::string file, std::string name);
    // Retrieves a stored model
    static Model GetModel(std::string name);
    // Load a music from file
    static Mix_Music* LoadMusic(std::string file, std::string name);
    // Retrieves a stored music
    static Mix_Music* GetMusic(std::string name);
    // Load a sound from file
    static Mix_Chunk* LoadSound(std::string file, std::string name);
    // Retrieves a stored sound
    static Mix_Chunk* GetSound(std::string name);
    // Properly de-allocates all loaded resources
    static void Clear();
private:
    // Private constructor, that is we do not want any actual resource manager objects. Its members and functions should be publicly available (static).
    ResourceManager() { }
    // Loads and generates a shader from file
    static Shader    loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile = nullptr);
    // Loads a single texture from file
    static Texture2D loadTextureFromFile(const GLchar *file, GLboolean alpha, GLboolean repeat);
    // Loads a single texture from file
    static Texture3D loadCubemapFromFile(vector<const GLchar*> faces);
    // Loads a single model from file
    static Model loadModelFromFile(std::string file);
};

#endif

