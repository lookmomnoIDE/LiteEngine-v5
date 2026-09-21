cmake_minimum_required(VERSION 4.0)
project("LiteEngineV005")

set(CMAKE_CXX_STANDARD 17)
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
	src/main.cpp
    )

target_compile_definitions(${PROJECT_NAME} PRIVATE PROJECT_ROOT="${CMAKE_SOURCE_DIR}")
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE include/utils)
target_include_directories(${PROJECT_NAME} PRIVATE include/GL)
target_include_directories(${PROJECT_NAME} PRIVATE include/math)
target_include_directories(${PROJECT_NAME} PRIVATE ext/STB)
target_include_directories(${PROJECT_NAME} PRIVATE ext/MA)
target_include_directories(${PROJECT_NAME} PRIVATE ext/FT/freetype-2.9.1/include)
target_include_directories(${PROJECT_NAME} PRIVATE ext/GLM/glm)
target_include_directories(${PROJECT_NAME} PRIVATE ext/GLAD/glad/include)
target_include_directories(${PROJECT_NAME} PRIVATE ext/GLAD/glad/include/KHR)
target_include_directories(${PROJECT_NAME} PRIVATE ext/GLFW/glfw-3.5.1/include/GLFW)


# Link static C/C++ runtime and Windows libraries
if(WIN32)

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