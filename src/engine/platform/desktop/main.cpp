#include "glfw_window.h"
#include "renderer.h"
#include "Engine.h"


unsigned int SCR_WIDTH = 1280;
unsigned int SCR_HEIGHT = 720;
int main() 
{
    Window* window   = CreateWindow({SCR_WIDTH, SCR_HEIGHT, "engine"});
    Renderer* renderer = CreateRenderDevice(window);
    Engine engine(window, renderer);
    engine.run();
}