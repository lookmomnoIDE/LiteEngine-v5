cmake_minimum_required(VERSION 4.0)
project("LiteEngineV005")

set(CMAKE_CXX_STANDARD 20)



# Link static C/C++ runtime and Windows libraries
if(WIN32)
    add_library(glfw STATIC IMPORTED)
    add_library(MA STATIC IMPORTED)
    add_library(freetype STATIC IMPORTED)
    
    set_target_properties(glfw PROPERTIES
        IMPORTED_LOCATION "C:/projects/LiteEngineV005/lib/GLFW/src/libglfw3.a"
        INTERFACE_INCLUDE_DIRECTORIES "C:/projects/LiteEngineV005/ext/GLFW/glfw-3.5.1/include/GLFW"
    )
    
    
    set_target_properties(MA PROPERTIES
        IMPORTED_LOCATION "C:/projects/LiteEngineV005/lib/MA/libminiaudio.a"
        INTERFACE_INCLUDE_DIRECTORIES "C:/projects/LiteEngineV005/ext/MA"
    )
    
    
    #C:\projects\LiteEngineV003\ext\ft27\ft.compiled\lib
    set_target_properties(freetype PROPERTIES
        IMPORTED_LOCATION "C:/projects/LiteEngineV005/lib/FT/libfreetype.a"
        INTERFACE_INCLUDE_DIRECTORIES "C:/projects/LiteEngineV005/ext/FT/freetype-2.9.1/include"
    )
    
    add_executable(${PROJECT_NAME}
        ext/GLAD/glad/src/glad.c
        src/engine/platform/desktop/main.cpp
        src/engine/platform/desktop/renderer/gl/renderer.cpp
        src/engine/platform/desktop/renderer/gl/shader/ShaderManager.cpp
        src/engine/platform/desktop/renderer/gl/texture/TextureManager.cpp
        src/engine/platform/desktop/glfw/glfw_window.cpp
        src/engine/CORE/Engine.cpp
        src/engine/CORE/scene/Scene.cpp
        src/engine/CORE/scene/Scene_test.cpp
        )
    
    target_compile_definitions(${PROJECT_NAME} PRIVATE PROJECT_ROOT="${CMAKE_SOURCE_DIR}")
    target_include_directories(${PROJECT_NAME} PRIVATE include/engine/platform/desktop)
    target_include_directories(${PROJECT_NAME} PRIVATE include/engine/platform/desktop/renderer)
    target_include_directories(${PROJECT_NAME} PRIVATE include/engine/platform/desktop/renderer/gl)
    target_include_directories(${PROJECT_NAME} PRIVATE include/engine/platform/desktop/renderer/gl/buffer)
    target_include_directories(${PROJECT_NAME} PRIVATE include/engine/platform/desktop/renderer/gl/shader)
    target_include_directories(${PROJECT_NAME} PRIVATE include/engine/platform/desktop/renderer/gl/texture)
    target_include_directories(${PROJECT_NAME} PRIVATE include/engine/platform/desktop/glfw)
    target_include_directories(${PROJECT_NAME} PRIVATE include/engine/CORE)
    target_include_directories(${PROJECT_NAME} PRIVATE include/engine/CORE/obj)
    target_include_directories(${PROJECT_NAME} PRIVATE include/engine/CORE/scene)
    target_include_directories(${PROJECT_NAME} PRIVATE include/engine/CORE/utils)
    #target_include_directories(${PROJECT_NAME} PRIVATE include/utils)
    #target_include_directories(${PROJECT_NAME} PRIVATE include/GL)
    #target_include_directories(${PROJECT_NAME} PRIVATE include/math)
    target_include_directories(${PROJECT_NAME} PRIVATE ext/STB)
    target_include_directories(${PROJECT_NAME} PRIVATE ext/MA)
    target_include_directories(${PROJECT_NAME} PRIVATE ext/FT/freetype-2.9.1/include)
    target_include_directories(${PROJECT_NAME} PRIVATE ext/GLM/glm)
    target_include_directories(${PROJECT_NAME} PRIVATE ext/GLAD/glad/include)
    target_include_directories(${PROJECT_NAME} PRIVATE ext/GLAD/glad/include/KHR)
    target_include_directories(${PROJECT_NAME} PRIVATE ext/GLFW/glfw-3.5.1/include/GLFW)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")

    target_link_libraries(${PROJECT_NAME} 
    	gdi32
    	dwmapi
        imm32
        glfw
        MA
        freetype
    )
endif()