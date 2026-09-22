#include "glfw_window.h"
#include "renderer.h"
#include "Engine.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


int main() 
{
    auto window   = createWindow({1280, 720, "engine"});
    auto renderer = createRenderDevice(*window);
    Engine engine(*window, *renderer);
    engine.run();
}