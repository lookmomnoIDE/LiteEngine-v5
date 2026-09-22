#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include <string>
#include <unordered_map>

#include "Shader.h"
//I know enums are preferred, however from my understanding
//c++ optimizes short strings differently from long strings. 
//so from a little bit of expirementation it seems like c++ 
//treats strings under 16 characters as ints or any other pbv type. 
//as with everything this is a complex topic and doesn't really
//include the idea of say packing data. Feel free to correct 
//me if I am flat out wrong about something though. 
class ShaderMan
{
	std::unordered_map<std::string, Shader*> m_shaders;
	std::string m_currentShader;
public:
	ShaderMan(){}
	~ShaderMan()
	{
		for(auto& [name, shader] : m_shaders)
		{
			delete shader;
		}
		m_currentShader = nullptr;
	}
	Shader* get(std::string name);
	void 	set(std::string name);
	Shader* add(std::string name, std::string vertexPath, std::string fragmentPath);
	void 	rem(std::string name);
	

};

#endif