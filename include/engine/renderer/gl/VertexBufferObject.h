#ifndef VERTEXBUFFEROBJECT_H
#define VERTEXBUFFEROBJECT_H

#include "Vertices.h"
#include <glad/glad.h>
#include <glfw3.h>

constexpr GLenum DS(bool isDynamic){return isDynamic ?  GL_DYNAMIC_DRAW : GL_STATIC_DRAW;}

template <typename T>
class VertexBufferObject
{
	unsigned int m_ID = 0;
public:
	VertexBufferObject(Vertices<T>& vertices, bool isDynamic = false)
	{
		glGenBuffers(1, &m_ID);
		bind();
		//GL_ARRAY_BUFFER will be used to configure currently bound buffer
		glBufferData(GL_ARRAY_BUFFER, vertices.byteSize(), vertices.data(), DS(isDynamic)); // see constexr fn above 
	}


	void bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	}


	void unBind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}


	void updateBuffer(Vertices<T>& vertices)
	{
		bind();
		glBufferSubData(m_ID, 0, vertices.byteSize(), vertices.data());
		//unBind();
	}

};

#endif