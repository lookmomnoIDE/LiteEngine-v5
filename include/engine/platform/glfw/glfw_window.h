#ifndef GLFW_WINDOW_H
#define GLFW_WINDOW_H

#include "window.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <functional>
#include <memory>

// Add these two to the Window base class in window.h so callers never see GLFW:
//
//   using InputCallback = std::function<void(int code, bool pressed)>;
//   virtual void SetInputCallback(InputCallback cb) = 0;
//   virtual glm::dvec2 MousePosition() const = 0;

class GLFWWindowImpl : public Window
{
    GLFWwindow*   m_handle = nullptr;
    InputCallback m_onInput;

public:
    explicit GLFWWindowImpl(const WindowConfig& cfg);
    ~GLFWWindowImpl() override;

    GLFWWindowImpl(const GLFWWindowImpl&) = delete;
    GLFWWindowImpl& operator=(const GLFWWindowImpl&) = delete;

    bool PollEvents() override;                 // false once the window should close
    void SwapBuffers() override;
    glm::ivec2 FramebufferSize() const override;

    void SetInputCallback(InputCallback cb) override { m_onInput = std::move(cb); }
    glm::dvec2 MousePosition() const override;

private:
    static GLFWWindowImpl* From(GLFWwindow* w);

    // GLFW trampolines -> recover `this` from the user pointer
    static void OnKey(GLFWwindow* w, int key, int scancode, int action, int mods);
    static void OnMouseButton(GLFWwindow* w, int button, int action, int mods);
    static void OnFramebufferSize(GLFWwindow* w, int width, int height);
};

std::unique_ptr<Window> CreateWindow(const WindowConfig& cfg);

#endif