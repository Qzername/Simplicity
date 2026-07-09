cmake_minimum_required(VERSION 4.0)
project(Simplicity)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/*.c
        ${PROJECT_SOURCE_DIR}/src/*.cpp)

file(GLOB_RECURSE HEADER_FILES
        ${PROJECT_SOURCE_DIR}/include/*.h
        ${PROJECT_SOURCE_DIR}/include/*.hpp)

add_library(Simplicity SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(Simplicity PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(Simplicity PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_include_directories(Simplicity PUBLIC ${PROJECT_SOURCE_DIR}/link)

# ======================== LIBRARIES ========================

find_package(OpenGL REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)
find_package(Stb REQUIRED)

target_include_directories(Simplicity PUBLIC ${Stb_INCLUDE_DIR})

target_link_libraries(Simplicity PUBLIC
        OpenGL::GL
        glm::glm
        glad::glad
        assimp::assimp
        glfw
)