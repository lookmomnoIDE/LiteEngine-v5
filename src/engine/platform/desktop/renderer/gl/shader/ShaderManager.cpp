#include "ShaderManager.h"

Shader* ShaderMan::get(std::string name)
{
	return m_shaders[name];
}


void ShaderMan::set(std::string name)
{
	if(m_currentShader == name) return;
	else
	{
		m_shaders[name]->use();
		m_currentShader = name;
	}
}


Shader* ShaderMan::add(std::string name, std::string fragmentPath, std::string vertexPath)
{
	Shader* shader = new Shader(fragmentPath, vertexPath);
	m_shaders[name] = shader;
	return shader;
}


void ShaderMan::rem(std::string name)
{
	delete m_shaders[name];
}

