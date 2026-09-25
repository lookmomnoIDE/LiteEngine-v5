#include "TextureMan.h"

Texture* TextureMan::get(eTexture name)
{
	return m_textures[name];
}


void TextureMan::use(eTexture name)
{

	//if(name == m_activeTexture[name]) break;
	m_textures[name]->bind((unsigned int)name);
	//m_activeTextures[name] = name;
	
}


Texture* TextureMan::add(eTexture name, std::string& path, TextureOptions opts)
{
	m_textures[name] = new Texture(path, opts);
	return m_textures[name];
}


void TextureMan::rem(eTexture name)
{
	delete m_textures[name];
}

