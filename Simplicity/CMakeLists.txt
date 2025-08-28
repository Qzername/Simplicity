cmake_minimum_required(VERSION 4.0)
project(Simplicity)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/src/*.c
        ${CMAKE_SOURCE_DIR}/src/*.cpp)

file(GLOB_RECURSE HEADER_FILES
        ${CMAKE_SOURCE_DIR}/src/*.h
        ${CMAKE_SOURCE_DIR}/src/*.hpp)

include_directories(${CMAKE_BINARY_DIR}/src)

add_library(Simplicity SHARED ${HEADER_FILES} ${SOURCE_FILES})

# ======================== LIBRARIES ========================

# ----- OpenGL (system library, provided by drivers) -----
find_package(OpenGL REQUIRED)

# ----- GLM (header-only) -----
find_path(GLM_INCLUDE_DIR glm/glm.hpp
        PATHS ${CMAKE_SOURCE_DIR}/include
)

if(NOT GLM_INCLUDE_DIR)
    message("GLM not found in include/")
    message(FATAL_ERROR "Download glm from: https://github.com/g-truc/glm/tags")
endif()

add_library(glm INTERFACE)
target_include_directories(glm INTERFACE ${GLM_INCLUDE_DIR})

# ----- GLFW (compiled lib + headers) -----
find_path(GLFW_INCLUDE_DIR GLFW/glfw3.h PATHS ${CMAKE_SOURCE_DIR}/include)
find_library(GLFW_LIB glfw3 PATHS ${CMAKE_SOURCE_DIR}/lib)
if(NOT GLFW_INCLUDE_DIR OR NOT GLFW_LIB)
    message("GLFW not found in include/ or libs/")
    message(FATAL_ERROR "Download glfw3 from https://www.glfw.org/download.html")
endif()
add_library(glfw STATIC IMPORTED)
set_target_properties(glfw PROPERTIES
        IMPORTED_LOCATION ${GLFW_LIB}
        INTERFACE_INCLUDE_DIRECTORIES ${GLFW_INCLUDE_DIR}
)

# ----- Assimp (compiled lib + headers) -----
find_path(ASSIMP_INCLUDE_DIR assimp/Importer.hpp PATHS ${CMAKE_SOURCE_DIR}/include)
find_library(ASSIMP_LIB assimp PATHS ${CMAKE_SOURCE_DIR}/lib)

if(NOT ASSIMP_INCLUDE_DIR OR NOT ASSIMP_LIB)
    message("Assimp not found in include/ or libs/")
    message("You need to compile assimp project - GitHub: https://github.com/assimp/assimp")
    message(FATAL_ERROR "Remember to copy include directory from their repo to this repo")
endif()
add_library(assimp STATIC IMPORTED)
set_target_properties(assimp PROPERTIES
        IMPORTED_LOCATION ${ASSIMP_LIB}
        INTERFACE_INCLUDE_DIRECTORIES ${ASSIMP_INCLUDE_DIR}
)

# ----- stb_image (header-only) -----
find_path(STB_INCLUDE_DIR stb_image.h PATHS ${CMAKE_SOURCE_DIR}/include)

if(NOT STB_INCLUDE_DIR)
    message("stb_image.h not found in include/")
    message(FATAL_ERROR "Download stb_image from https://github.com/nothings/stb/blob/master/stb_image.h")
endif()
add_library(stb INTERFACE)
target_include_directories(stb INTERFACE ${STB_INCLUDE_DIR})

# ----- glad  -----
set(GLAD_SRC ${CMAKE_SOURCE_DIR}/include/glad/glad.c)
set(GLAD_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

if(NOT EXISTS "${GLAD_INCLUDE_DIR}/glad/glad.h" OR NOT EXISTS "${GLAD_SRC}")
    message("GLAD headers or source not found")
    message(FATAL_ERROR "Download glad from: https://www.glfw.org/download.html")
endif()

add_library(glad STATIC ${GLAD_SRC})
target_include_directories(glad PUBLIC ${GLAD_INCLUDE_DIR})

# ======================== FINAL LIBRARY LINK ========================

target_link_libraries(Simplicity
        PUBLIC
        OpenGL::GL
        glm
        glfw
        assimp
        stb
        glad
)