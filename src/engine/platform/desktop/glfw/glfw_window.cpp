#include "glfw_window.h"


GLFWWindowImpl::GLFWWindowImpl(const WindowConfig& cfg)
{
    if (!glfwInit())
        throw std::runtime_error("glfwInit failed");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE); // must be before glfwCreateWindow

    m_handle = glfwCreateWindow(cfg.width, cfg.height, cfg.title.c_str(), nullptr, nullptr);
    if (!m_handle)
        throw std::runtime_error("glfwCreateWindow failed");

    glfwMakeContextCurrent(m_handle);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("glad failed to load OpenGL");

    // One user pointer, owned by the window. (The old InputHandler::Init
    // overwrote this with the renderer, which is why the two classes fought.)
    glfwSetWindowUserPointer(m_handle, this);

    glfwSetKeyCallback(m_handle, OnKey);
    glfwSetMouseButtonCallback(m_handle, OnMouseButton);
    glfwSetFramebufferSizeCallback(m_handle, OnFramebufferSize);

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);

    // GLFW doesn't fire the framebuffer callback for the initial size
    const glm::ivec2 fb = FramebufferSize();
    glViewport(0, 0, fb.x, fb.y);
}

GLFWWindowImpl::~GLFWWindowImpl()
{
    if (m_handle)
        glfwDestroyWindow(m_handle);
    glfwTerminate();
}

bool GLFWWindowImpl::PollEvents()
{
    glfwPollEvents();
    if (glfwGetKey(m_handle, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_handle, true);
    return !glfwWindowShouldClose(m_handle);
}

void GLFWWindowImpl::SwapBuffers()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers(m_handle);
}

glm::ivec2 GLFWWindowImpl::FramebufferSize() const
{
    int w = 0, h = 0;
    glfwGetFramebufferSize(m_handle, &w, &h);
    return { w, h };
}

glm::dvec2 GLFWWindowImpl::MousePosition() const
{
    double x = 0.0, y = 0.0;
    glfwGetCursorPos(m_handle, &x, &y);
    return { x, y };
}

// ---- callbacks -------------------------------------------------------------

GLFWWindowImpl* GLFWWindowImpl::From(GLFWwindow* w)
{
    return static_cast<GLFWWindowImpl*>(glfwGetWindowUserPointer(w));
}

void GLFWWindowImpl::OnKey(GLFWwindow* w, int key, int button, int action, int)
{
    auto scene = From(w)->m_engine->currentScene();
    auto am = scene->getAM();
    if(am.find(button) == am.end())
    {
        std::cout << "Action Not found!" << std::endl;
        return;
    }
    const Type actionType = (action == GLFW_PRESS) ? Type::START : (action == GLFW_REPEAT) ? Type::NONE : Type::STOP;
    Action a(am.at(button), actionType);
    scene->doAction(a);
}

void GLFWWindowImpl::OnMouseButton(GLFWwindow* w, int button, int action, int)
{
    auto scene = From(w)->m_engine->currentScene();
    auto am = scene->getAM();
    if(am.find(button) == am.end())
    {
        std::cout << "Action Not found!" << std::endl;
        return;
    }
    const Type actionType = (action == GLFW_PRESS) ? Type::START : (action == GLFW_REPEAT) ? Type::NONE : Type::STOP;
    Action a(am.at(button), actionType);
    scene->doAction(a);
}

void GLFWWindowImpl::OnFramebufferSize(GLFWwindow*, int width, int height)
{
    glViewport(0, 0, width, height);
}


void GLFWWindowImpl::setEnginePtr(Engine* engine)
{
    m_engine = engine;
}


Window* CreateWindow(const WindowConfig& cfg)
{
    Window* window = new GLFWWindowImpl(cfg);
    return window;
}