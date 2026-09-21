#include "renderer.h"


VertexArrayObject Renderer::makeVAO()
{
	VertexArrayObject vao;
	vao.bind();
	return vao;
}


VertexBufferObject<float> Renderer::makeVBO(Vertices& verts)
{
	VertexBufferObject<float> vbo(verts);
	vbo.bind();
	return vbo;
}


VertexAttribObject Renderer::makeLayout(const std::vector<unsigned int>& argv[])
{
	VertexAttribObject layout = VertexAttribObject();
	for(unsigned int i = 0; i < argv.size(); i++)
	{
		layout.push<float>(argv[i]);
	}
	layout.addPointers();
	layout.use();
	return layout;
}


ElementBufferObject Renderer::makeEBO(Indices& indices)
{
	ElementBufferObject ebo = ElementBufferObject(indices);
	ebo.bind();
	return ebo;
}


void Renderer::makeIndexed(Object& obj)
{
	obj.m_VAO = makeVAO();
	obj.m_VBO = makeVBO(obj.m_mesh);
	makeLayout(obj.m_vData);
	obj.m_EBO = makeEBO(obj.m_indices);
}


void Renderer::makeArray(Object& obj)
{
	obj.m_VAO = makeVAO();
	obj.m_VBO = makeVBO(obj.m_mesh);
	makeLayout(obj.m_vData);
}


void Renderer::drawElements(Object& obj)
{
	obj.m_VAO.bind();
	obj.m_material.shader.use()
	obj.m_material.albedo.bind()
	glDrawElements(GL_TRIANGLES, obj.m_indices.count(), GL_UNSIGNED_INT, 0);
}

void Renderer::drawTriangles(Object& obj)
{
	obj.m_VAO.bind();
	obj.m_material.shader.use()
	obj.m_material.albedo.bind()
	glDrawArrays(GL_TRIANGLES, 0, obj.m_vCount);
}

