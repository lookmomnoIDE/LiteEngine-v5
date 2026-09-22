#ifndef OBJECT_H
#define OBJECT_H

#include <glm.hpp>
#include <vector>
#include <string>

#include "Indices.h"
#include "Vertices.h"
#include "VertexArrayObject.h"
#include "Texture.h"
#include "Shader.h"


struct Material
{
	std::string shader = "";
	Texture* albedo;
	//glm::vec3 tint;
};


struct Object
{
	glm::vec3 position;
	float angle;
	glm::vec3 axis;

	VertexArrayObject m_VAO = 0;
	Material m_material;
	Vertices m_mesh;
	Indices m_indices;
	std::vector<unsigned int> m_vData;
	unsigned int m_vCount;
};
#endif