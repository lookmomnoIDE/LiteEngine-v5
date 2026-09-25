#include "renderer.h"


VertexArrayObject Renderer::makeVAO()
{
	VertexArrayObject vao;
	vao.bind();
	return vao;
}


VertexBufferObject<float> Renderer::makeVBO(Vertices<float>& verts)
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
	makeVBO(obj.m_mesh);
	makeLayout(obj.m_vData);
	makeEBO(obj.m_indices);
}


void Renderer::makeArray(Object& obj)
{
	obj.m_VAO = makeVAO();
	makeVBO(obj.m_mesh);
	makeLayout(obj.m_vData);
}


void Renderer::drawElements(Object& obj)
{
	obj.m_VAO.bind();
	auto shader = m_ShaderMan.get(obj.m_material.shader);
	m_TextureMan.use(obj.m_material.albedo);
	shader->setInt("u_default", 0);
	shader->setInt("u_albedo", 1);
	glDrawElements(GL_TRIANGLES, obj.m_indices.size(), GL_UNSIGNED_INT, 0);
}


void Renderer::drawTriangles(Object& obj)
{
	obj.m_VAO.bind();
	auto shader = m_ShaderMan.get(obj.m_material.shader);
	m_TextureMan.use(obj.m_material.albedo);
	shader->setInt("u_default", 0);
	shader->setInt("u_albedo", 1);
	glDrawArrays(GL_TRIANGLES, 0, obj.m_vCount);
}


std::string Renderer::createShader(std::string name, std::string& vertexPath, std::string& fragmentPath)
{
	m_ShaderMan.add(name, fragmentPath, vertexPath);
	return name;
}


eTexture Renderer::createTexture(eTexture name, std::string& path, TextureOptions opts)
{
	m_TextureMan.add(name, path, opts);
	return name;
}


void Renderer::useTexture(eTexture name)
{
	m_TextureMan.use(name);
}


void Renderer::setView(Object& obj, Camera& camera) // matrix
{
	auto shader = m_ShaderMan.get(obj.m_material.shader);
    shader->setMat4("view", camera.GetViewMatrix());
}



void Renderer::setProjection(Object& obj) // matrix
{
	glm::ivec2 dims = m_window->FramebufferSize();
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), (float)dims.x / (float)dims.y, 0.1f, 100.0f);

	auto shader = m_ShaderMan.get(obj.m_material.shader);
    shader->setMat4("projection", projection);
}


void Renderer::getModel(Object& obj) // matrix
{
	glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, obj.position);
    float angle = obj.angle;
    model = glm::rotate(model, glm::radians(angle), obj.axis);

    auto shader = m_ShaderMan.get(obj.m_material.shader);
    shader->setMat4("model", model);
}