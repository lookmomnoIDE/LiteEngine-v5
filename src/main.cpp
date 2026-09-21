#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>
#include <miniaudio.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <ft2build.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


#include "filesystem.h"

unsigned int SCR_WIDTH = 1280;
unsigned int SCR_HEIGHT = 720;
//declarations
void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);



glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
};



// 2 triangles = 6 indices
//std::vector<unsigned int> ndices = { 0, 1, 3,   1, 2, 3};
Vertices verts = Vertices<float>(vertices, std::size(vertices));
Indices indices = Indices(36);

std::string vertexPath = "src/shaders/textured.vert";
std::string fragmentPath = "src/shaders/textured.frag";

int main(int argc, char const *argv[])
{

	Shader myShader = Shader(vertexPath, fragmentPath);
	myShader.use();
	Texture texture0 = Texture("res/textures/default.png");
	Texture texture1 = Texture("res/textures/fabric.jpg");
	myShader.setInt("texture0", 0);
	myShader.setInt("texture1", 1);

	while(!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glm::mat4 view          = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 projection    = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        view       = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        // pass transformation matrices to the shader
        myShader.setMat4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        myShader.setMat4("view", view);
		//vbo.bind();
		//layout.use();
		//ebo.bind();
		texture0.bind(0);
		texture1.bind(1);
		vao.bind();
		//glDrawArrays(GL_TRIANGLES, 0, 3);

		//ERROR CHECKING
		GLint prog, vaoB, eboB, vboB, eboSize = 0, vboSize = 0;
		glGetIntegerv(GL_CURRENT_PROGRAM, &prog);
		glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &vaoB);
		glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &eboB);
		glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &vboB);
		glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &eboSize);
		glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &vboSize);
		std::cout << "program=" << prog << " vao=" << vaoB
		          << " ebo=" << eboB << " (" << eboSize << " bytes)"
		          << " vbo=" << vboB << " (" << vboSize << " bytes)\n";
		GLenum err = glGetError();
		if (err) std::cout << "GL error before draw: 0x" << std::hex << err << "\n";
		//END ERROR CHECKING BLOCK
		for (unsigned int i = 0; i < 10; i++)
        {
            // calculate the model matrix for each object and pass it to shader before drawing
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            myShader.setMat4("model", model);

            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        }
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}


void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


void processInput(GLFWwindow *window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}