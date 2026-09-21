#ifndef WINDOW_H
#define WINDOW_H

#include <glm.hpp>

struct WindowConfig
{
    unsigned int width;
    unsigned int height;
    std::string title;
};

// engine/platform/window.h
class Window {
public:
    virtual ~Window() = default;
    virtual bool pollEvents() = 0;        // false => quit
    virtual void swapBuffers() = 0;
    virtual glm::ivec2 framebufferSize() const = 0;
    virtual void setInputCallback(InputCallback cb) = 0;
};

std::unique_ptr<Window> createWindow(const WindowConfig& cfg);

#endif