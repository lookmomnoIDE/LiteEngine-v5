#ifndef VERTEXARRAYOBJECT_H
#define VERTEXARRAYOBJECT_H

#include <glad/glad.h>

class VertexArrayObject
{
	unsigned int m_VAO = 0;
public:
	VertexArrayObject()
	{
		glGenVertexArrays(1, &m_VAO);
		bind();
	}


	void bind()
	{
		glBindVertexArray(m_VAO);
	}
};

#endif