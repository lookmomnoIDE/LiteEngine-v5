#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include "filesystem.h"
#include <glad/glad.h>
#include <glfw3.h>

enum class Wraps
{
    REPEAT,
    MIRRORED,
    CLAMP,
    BORDERCLAMP,
    COUNT
};


enum class Filters
{
    NEAREST,
    LINEAR,
    COUNT
};


constexpr GLenum texWrap(Wraps param)
{
    switch(param)
    {
        case Wraps::REPEAT:
            return GL_REPEAT;
        case Wraps::MIRRORED:
            return GL_MIRRORED_REPEAT;
        case Wraps::CLAMP:
            return GL_CLAMP_TO_EDGE;
        case Wraps::BORDERCLAMP:
            return GL_CLAMP_TO_BORDER;
        case Wraps::COUNT:
            std::cout << "Warning COUNT supplied: returned GL_REPEAT." << std::endl;
            return GL_REPEAT;
    }
}

constexpr GLenum texFilter(Filters param)
{
    switch(param)
    {
        case Filters::NEAREST:
            return GL_NEAREST;
        case Filters::LINEAR:
            return GL_LINEAR;
        case Filters::COUNT:
            std::cout << "Warning COUNT supplied: returned GL_NEAREST." << std::endl;
            return GL_NEAREST;
    }
}


class Texture
{
    unsigned int m_texture;


public:
    Texture(std::string path, Wraps wrap = Wraps::REPEAT, Filters filter = Filters::NEAREST, bool flip = true)
    {
        glGenTextures(1, &m_texture);
        glBindTexture(GL_TEXTURE_2D, m_texture); 
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, texWrap(wrap));   // set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, texWrap(wrap));
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, texFilter(filter));
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, texFilter(filter));
        loadImage(path, flip);

    }

    ~Texture() { glDeleteTextures(1, &m_texture); }


    void bind(unsigned int unit = 0)
    {
        glActiveTexture(GL_TEXTURE0 + unit);
        glBindTexture(GL_TEXTURE_2D, m_texture);
    }


private:    
    void loadImage(const std::string& path, bool flip) const
    {
        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(flip);
        unsigned char *data = stbi_load(FileSystem::getPath(path).c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            GLenum format = nrChannels == 4 ? GL_RGBA : nrChannels == 3 ? GL_RGB : GL_RED;
            glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // needed for RGB/RED with widths not divisible by 4
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
    }
};

#endif
/*

 // load and create a texture 
    // -------------------------
    unsigned int texture1, texture2;
    // texture 1
    // ---------
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1); 
     // set the texture wrapping parameters
    
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char *data = stbi_load(FileSystem::getPath("resources/textures/container.jpg").c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    // texture 2
    // ---------
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    data = stbi_load(FileSystem::getPath("resources/textures/awesomeface.png").c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
    // -------------------------------------------------------------------------------------------
    ourShader.use(); // don't forget to activate/use the shader before setting uniforms!
    // either set it manually like so:
    glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0);
    // or set it via the texture class
    ourShader.setInt("texture2", 1);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);
*/