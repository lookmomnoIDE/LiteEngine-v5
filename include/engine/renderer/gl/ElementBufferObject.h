#ifndef ELEMENTBUFFEROBJECT_H
#define ELEMENTBUFFEROBJECT_H

#include "Indices.h"
#include <glad/glad.h>
#include <glfw3.h>

//constexpr GLenum DS(bool isDynamic){return isDynamic ?  GL_DYNAMIC_DRAW : GL_STATIC_DRAW;}

class ElementBufferObject
{
	unsigned int m_EBO = 0;
public:
	ElementBufferObject(const Indices& indices, bool isDynamic = false)
	{
		glGenBuffers(1, &m_EBO);
		bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.byteSize(), indices.data(), DS(isDynamic));
	}


	void bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);

	}

	void unBind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void updateBuffer(const Indices& indices)
	{
		bind();
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indices.byteSize(), indices.data());
	}

};

#endif