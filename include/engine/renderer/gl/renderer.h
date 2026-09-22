#ifndef RENDERER_H
#define RENDERER_H

#include <map>

#include "Vertices.h"
#include "Indices.h"
#include "VertexBufferObject.h"
#include "ShaderManager.h"
#include "VertexArrayObject.h"
#include "VertexAttribObjects.h"
#include "ElementBufferObject.h"
#include "TextureMan.h"
#include "Indices.h"
#include "object.h"

class Renderer
{	
	Window* m_window;
	m_ShaderMan = ShaderMan();
	m_TextureMan = TextureMan();
	VertexArrayObject makeVAO();
	VertexBufferObject<float> makeVBO(Vertices& verts);
	VertexAttribObject makeLayout(const std::vector<unsigned int>& argv);
	ElementBufferObject makeEBO(Indices& indices);

public:
	Renderer(Window* window)
	:m_window(window)
	{

	}
	void makeIndexed(Object& obj); //buffer
	void makeArray(Object& obj); //buffer

	void drawElements(Object& obj);
	void drawTriangles(Object& obj);
	std::string createShader(std::string name, std::string& vertexPath, std::string& fragmentPath);
	std::string createTexture(std::string name, std::string& path);

};

std::unique_ptr<Window> createRenderDevice(const GLFWWindowImpl& window) 
{
    return std::make_unique<Renderer>(window);
}

#endif