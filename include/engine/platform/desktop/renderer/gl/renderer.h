#ifndef RENDERER_H
#define RENDERER_H

#include <map>

#include "Vertices.h"
#include "Indices.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "VertexAttribObjects.h"
#include "ElementBufferObject.h"
#include "ShaderManager.h"
#include "TextureMan.h"
#include "object.h"
#include "camera.h"
#include "glfw_window.h"

class Renderer
{	
	Window* m_window;
	ShaderMan m_ShaderMan = ShaderMan();
	TextureMan m_TextureMan = TextureMan();
	VertexArrayObject makeVAO();
	VertexBufferObject<float> makeVBO(Vertices<float>& verts);
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
	std::string createShader(std::string name, std::string& fragmentPath, std::string& vertexPath);
	eTexture createTexture(eTexture name, std::string& path, TextureOptions opts);
	void useTexture(eTexture name);
	void setView(Object& obj, Camera& camera); // matrix
	void setProjection(Object& obj);
	void getModel(Object& obj); // matrix
};

Renderer* CreateRenderDevice(Window* window) 
{
	Renderer* renderer = new Renderer(window);
    return renderer;
}

#endif