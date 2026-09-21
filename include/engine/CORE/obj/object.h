#ifndef OBJECT_H
#define OBJECT_H

#include <glm.hpp>
#include "Indices.h"
#include "Vertices.h"
#include "VertexArrayObject.h"
#include "Texture.h"
#include "Shader.h"


struct Material
{
	Shader* shader;
	Texture* albedo;
	//glm::vec3 tint;
};


struct Object
{
	VertexArrayObject m_VAO;
	glm::mat4 m_transform;
	Material m_material;
	Vertices m_mesh;
	Indices m_indices;
	unsigned int m_vData[];
	unsigned int m_vCount;
};
#endif