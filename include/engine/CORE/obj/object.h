#ifndef OBJECT_H
#define OBJECT_H

#include <glm.hpp>
#include <vector>
#include <string>

#include "Vertices.h"
#include "Indices.h"
//Todo: need to make buffer identifier platform agnostic or modify include logic.
// will remain in place for testing.
#include "VertexArrayObject.h"
#include "Texture.h"


struct Material
{
	std::string shader = "";
	eTexture albedo = eTexture::ALBEDO;
	//glm::vec3 tint;
};



struct Object
{
	glm::vec3 position;
	float angle;
	glm::vec3 axis;

	VertexArrayObject m_VAO;
	Material m_material;
	Vertices<float> m_mesh;
	Indices m_indices;
	std::vector<unsigned int> m_vData;
	unsigned int m_vCount;
};
#endif