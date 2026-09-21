#ifndef RENDERER_H
#define RENDERER_H

#include <map>

#include "Vertices.h"
#include "Indices.h"
#include "VertexBufferObject.h"
#include "Shader.h"
#include "VertexArrayObject.h"
#include "VertexAttribObjects.h"
#include "ElementBufferObject.h"
#include "Texture.h"
#include "Indices.h"
#include "object.h"

class Renderer
{	
	Window* m_window;
	VertexArrayObject makeVAO();
	VertexBufferObject<float> makeVBO(Vertices& verts);
	VertexAttribObject makeLayout(unsigned int const *argv[]);
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

};

std::unique_ptr<Window> createRenderDevice(const GLFWWindowImpl& window) 
{
    return std::make_unique<Renderer>(window);
}

#endif