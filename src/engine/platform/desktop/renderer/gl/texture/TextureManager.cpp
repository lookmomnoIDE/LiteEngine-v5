#include "TextureMan.h"

Texture* TextureMan::get(std::string name)
{
	return m_textures[name];
}


void TextureMan::set(std::string name, unsigned int unit = 0)
{

	if(name == m_activeTexture[unit]) break;
	else
	{
		m_textures[name].bind(unit);
		m_activeTextures[unit] = name;
	}
	
}


Texture* TextureMan::add(std::string name, std::string path, TextureOptions opts = {})
{
	m_textures[name] = new Texture(path, opts);
	return m_textures[name]
}


void TextureMan::rem(std::string name)
{
	delete m_textures[name];
}

