#ifndef TEXTUREMAN_H
#define TEXTUREMAN_H

#include <string>
#include <unordered_map>
#include <vector>

#include "Texture.h"
//Todo: need to handle for different sets of textures?
enum class eTexture
{
	DEFAULT = 0,
	ALBEDO = 1,
	COUNT
};

class TextureMan
{
	std::unordered_map<eTexture, Texture*> m_textures;
	std::vector<eTexture> m_activeTextures;
public:
	Texture* 	get(eTexture name);
	void 		use(eTexture name);
	Texture* 	add(eTexture name, std::string& path, TextureOptions opts);
	void 		rem(eTexture name);

};

#endif