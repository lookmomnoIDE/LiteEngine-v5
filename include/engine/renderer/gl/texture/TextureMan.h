#ifndef TEXTUREMAN_H
#define TEXTUREMAN_H

#include <string>
#include <unordered_map>

#include "Texture.h"


class TextureMan
{
	std::unordered_map<std::string, Texture*> m_textures;
	std::vector<std::string> m_activeTextures;
public:
	Texture* 	get(std::string name);
	void 		set(std::string name);
	Texture* 	add(std::string name, std::string path, TextureOptions opts = {});
	void 		rem(std::string name);

};

#endif