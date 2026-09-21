#ifndef VERTEXATTRIBOBJECT_H
#define VERTEXATTRIBOBJECT_H

#include <glad/glad.h>
#include <vector>
#include <type_traits>
#include <cstdint>


class VertexAttribObject
{

public:

	struct VertexBufferElement
	{
		unsigned int type;
		unsigned int count;
		bool normalized;
		unsigned int typeSize;
	};

private:

	std::vector<VertexBufferElement> m_elements;
	unsigned int m_stride = 0;

public:

	VertexAttribObject(){}
	void addPointers()
	{
		const auto& elements = this->getElements();
		unsigned int offset = 0;
		for(unsigned int i = 0; i < elements.size(); i++)
		{
			const auto& element = elements[i];
			glVertexAttribPointer(i, element.count, element.type, element.normalized, this->getStride(), (const void*)(uintptr_t)offset);
			glEnableVertexAttribArray(i);
			offset += element.count * element.typeSize;
		}
	}
	

	void use()
	{
		for(size_t i = 0; i < m_elements.size(); i++)
		{
			glEnableVertexAttribArray(i);
		}
	}


	const std::vector<VertexBufferElement>& getElements() const 
	{
		return m_elements;
	}
	
	 
	unsigned int getStride() const 
	{
		return m_stride;
	}
	
	// Push specializations
	template <typename T>
	VertexAttribObject* push(unsigned int count)
	{
	    GLenum type;
	    if constexpr (std::is_same_v<T, float>)              type = GL_FLOAT;
	    else if constexpr (std::is_same_v<T, unsigned int>)  type = GL_UNSIGNED_INT;
	    else if constexpr (std::is_same_v<T, unsigned char>) type = GL_UNSIGNED_BYTE;
	    else static_assert(sizeof(T) == 0, "Unsupported vertex attribute type");
	
	    m_elements.push_back({type, count, GL_FALSE, sizeof(T)});
	    m_stride += count * sizeof(T);
	    return this;
	}
	
	

};

#endif

/*


#include "VertexBufferLayout.h"

template <typename T> inline GLenum GLType();
template <> inline GLenum GLType<float>()         { return GL_FLOAT; }
template <> inline GLenum GLType<unsigned int>()  { return GL_UNSIGNED_INT; }
template <> inline GLenum GLType<unsigned char>() { return GL_UNSIGNED_BYTE; }

VertexBufferLayout::VertexBufferLayout(){}
VertexBufferLayout::~VertexBufferLayout(){}


const std::vector<VertexBufferLayout::VertexBufferElement>& VertexBufferLayout::GetElements() const 
{
	return m_Elements;
}

 
unsigned int VertexBufferLayout::GetStride() const 
{
	return m_Stride;
}

// Push specializations
template <>
VertexBufferLayout* VertexBufferLayout::Push<float>(unsigned int count)
{
    m_Elements.push_back({GLType<float>(), count, GL_FALSE, sizeof(float)});
    m_Stride += count * sizeof(float);
    return this;
}

template <>
VertexBufferLayout* VertexBufferLayout::Push<unsigned int>(unsigned int count)
{
    m_Elements.push_back({GLType<unsigned int>(), count, GL_FALSE, sizeof(unsigned int)});
    m_Stride += count * sizeof(unsigned int);
    return this;
}

template <>
VertexBufferLayout* VertexBufferLayout::Push<unsigned char>(unsigned int count)
{
    m_Elements.push_back({GLType<unsigned char>(), count, GL_FALSE, sizeof(unsigned char)});
    m_Stride += count * sizeof(unsigned char);
    return this;
}

*/