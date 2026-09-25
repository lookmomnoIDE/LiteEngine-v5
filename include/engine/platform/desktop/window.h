#ifndef WINDOW_H
#define WINDOW_H

#include <glm.hpp>
#include <memory>
#include <string>

struct WindowConfig
{
    unsigned int width;
    unsigned int height;
    std::string title;
};

// engine/platform/window.h
class Window 
{
public:
    virtual ~Window() = default;
    virtual bool PollEvents() = 0;        // false => quit
    virtual void SwapBuffers() = 0;
    virtual glm::ivec2 FramebufferSize() const = 0;
    //virtual void setInputCallback(InputCallback cb) = 0;
};

//std::unique_ptr<Window> CreateWindow(const WindowConfig& cfg);

#endif