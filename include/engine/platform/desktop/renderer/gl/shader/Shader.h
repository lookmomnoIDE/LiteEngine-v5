#ifndef SHADER_H
#define SHADER_H


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>
#include <glm.hpp>
#include "filesystem.h"



class Shader
{
	unsigned int m_shaderProgram;

public:
	Shader(std::string fragShaderPath, std::string vertexShaderPath)
	{
		m_shaderProgram = glCreateProgram();
		load(vertexShaderPath, fragShaderPath);
	}

	void load(std::string& fragShaderPath, std::string& vertexShaderPath)
	{
		auto fs = compileFShader(fragShaderPath);
		auto vs = compileVShader(vertexShaderPath);
		linkProgram(fs, vs);	
	}


	unsigned int compileVShader(std::string& vertexShaderPath)
	{
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		auto vShaderCode = loadSource(vertexShaderPath);
		const char* vShaderCCode = vShaderCode.c_str();
		glShaderSource(vertexShader, 1, &vShaderCCode, NULL);
		glCompileShader(vertexShader);
		int ok; 
		char log[1024];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &ok);
		if (!ok) 
		{
			glGetShaderInfoLog(vertexShader, 1024, nullptr, log);
			std::cout << "Shader compile error:\n" << log << std::endl;
		}
		return vertexShader;
	}

	unsigned int compileFShader(std::string& fragShaderPath)
	{
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		auto fShaderCode = loadSource(fragShaderPath);
		const char* fShaderCCode = fShaderCode.c_str();
		int ok; 
		char log[1024];
		glShaderSource(fragmentShader, 1, &fShaderCCode, NULL);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &ok);
		if (!ok) 
		{
			glGetShaderInfoLog(fragmentShader, 1024, nullptr, log);
			std::cout << "Shader compile error:\n" << log << std::endl;
		}
		return fragmentShader;
	}

	void linkProgram(unsigned int fragmentShader, unsigned int vertexShader)
	{
		glAttachShader(m_shaderProgram, vertexShader);
		glAttachShader(m_shaderProgram, fragmentShader);
		glLinkProgram(m_shaderProgram);
		int ok; 
		char log[1024];
		glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &ok);
		if (!ok) 
		{
			glGetProgramInfoLog(m_shaderProgram, 1024, nullptr, log);
			std::cout << "Program link error:\n" << log << std::endl;
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void use()
	{
		glUseProgram(m_shaderProgram);
	}


	std::string loadSource(const std::string& path) const
	{

		std::ifstream fin(FileSystem::getPath(path));
		if (!fin) { std::cout << "Could not open shader: " << path << std::endl; }
		/*
		if (!fin.is_open())
		{
			log("Failed to load file: " + path);
		}
		*/
		std::stringstream ss;
    	ss << fin.rdbuf();
    	return ss.str();
	}


	void setBool(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(m_shaderProgram ,name.c_str()), (int)value);
	}


	void setInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(m_shaderProgram ,name.c_str()), value);
	}


	void setFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(m_shaderProgram ,name.c_str()), value);
	}

	void setFloat4(const std::string& name, float* value) const
	{
		glUniform4f(glGetUniformLocation(m_shaderProgram ,name.c_str()), value[0], value[1] , value[2], value[3]);
	}
	void setVec2(const std::string &name, const glm::vec2 &value) const
    { 
        glUniform2fv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, &value[0]); 
    }
    void setVec2(const std::string &name, float x, float y) const
    { 
        glUniform2f(glGetUniformLocation(m_shaderProgram, name.c_str()), x, y); 
    }
    // ------------------------------------------------------------------------
    void setVec3(const std::string &name, const glm::vec3 &value) const
    { 
        glUniform3fv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, &value[0]); 
    }
    void setVec3(const std::string &name, float x, float y, float z) const
    { 
        glUniform3f(glGetUniformLocation(m_shaderProgram, name.c_str()), x, y, z); 
    }
    // ------------------------------------------------------------------------
    void setVec4(const std::string &name, const glm::vec4 &value) const
    { 
        glUniform4fv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, &value[0]); 
    }
    void setVec4(const std::string &name, float x, float y, float z, float w) const
    { 
        glUniform4f(glGetUniformLocation(m_shaderProgram, name.c_str()), x, y, z, w); 
    }
    // ------------------------------------------------------------------------
    void setMat2(const std::string &name, const glm::mat2 &mat) const
    {
        glUniformMatrix2fv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat3(const std::string &name, const glm::mat3 &mat) const
    {
        glUniformMatrix3fv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat4(const std::string &name, const glm::mat4 &mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
};

#endif