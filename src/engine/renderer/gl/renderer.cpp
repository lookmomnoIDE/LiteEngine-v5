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


VertexAttribObject Renderer::makeLayout(const std::vector<unsigned int>& argv)
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
	auto shader = m_ShaderMan.get(obj.m_material.shader);
	m_TextureMan.set(obj.m_material.albedo, 1);
	shader.setInt("u_default", 0);
	shader.setInt("u_albedo", 1);
	glDrawElements(GL_TRIANGLES, obj.m_indices.count(), GL_UNSIGNED_INT, 0);
}


void Renderer::drawTriangles(Object& obj)
{
	obj.m_VAO.bind();
	auto shader = m_ShaderMan.get(obj.m_material.shader);
	m_TextureMan.set(obj.m_material.albedo, 1);
	shader.setInt("u_default", 0);
	shader.setInt("u_albedo", 1);
	glDrawArrays(GL_TRIANGLES, 0, obj.m_vCount);
}


std::string createShader(std::string name, std::string& vertexPath, std::string& fragmentPath)
{
	m_ShaderMan.add(name, vertexPath, fragmentPath);
	return name;
}


std::string createTexture(std::string name, std::string& path, TextureOptions opts = {})
{
	m_TextureMan.add(name, path, opts);
	return name;
}