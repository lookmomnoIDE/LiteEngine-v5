#include "ShaderManager.h"

Shader* ShaderMan::get(std::string name)
{
	return m_shaders[name];
}


void ShaderMan::set(std::string name)
{
	if(m_currentShader == name) break;
	else
	{
		m_shaders[name]->use();
		m_currentShader = name;
	}
}


Shader* ShaderMan::add(std::string name, std::string vertexPath, std::string fragmentPath)
{
	Shader* shader = new Shader(vertexPath, fragmentPath);
	m_shaders[name] = shader;
	return shader;
}


void ShaderMan::rem(std::string name)
{
	delete m_shaders[name];
}

