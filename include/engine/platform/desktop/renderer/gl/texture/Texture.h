#ifndef TEXTURE_H
#define TEXTURE_H

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <string>
#include <iostream>
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


struct TextureOptions 
{
    Wraps wrap = Wraps::REPEAT;
    Filters filter = Filters::NEAREST;
    bool flip = true;
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
    Texture(std::string path, TextureOptions opts = {})
    {
        glGenTextures(1, &m_texture);
        glBindTexture(GL_TEXTURE_2D, m_texture); 
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, texWrap(opts.wrap));   // set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, texWrap(opts.wrap));
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, texFilter(opts.filter));
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, texFilter(opts.filter));
        loadImage(path, opts.flip);
    }


    ~Texture() 
    {
        glDeleteTextures(1, &m_texture);
    }


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
