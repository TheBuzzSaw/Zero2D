cmake_minimum_required (VERSION 2.6) 
project(Zero2D)
#add_subdirectory(..)

set(CMAKE_CXX_FLAGS "-g -Wall")

file(GLOB SRCS "game/*.cpp")
link_directories(${PROJECT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})

find_package(OpenGL REQUIRED)
link_directories(${OPENGL_LIBRARY_DIRS})
include_directories(${OPENGL_INCLUDE_DIR})

find_package(Lua51 REQUIRED)
include_directories(${LUA_INCLUDE_DIR})
link_directories(${LUA51_LIBRARY_DIRS})

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_net REQUIRED)
find_package(SDL_mixer REQUIRED)
find_package(SDL_ttf REQUIRED)
include_directories(${SDL_INCLUDE_DIR})

find_package(CURL)
include_directories(${CURL_INCLUDE_DIR})

add_library(GLee STATIC GLee/GLee.c)

file(GLOB CGEFILES "CGE/*.cpp")
add_library(CGE STATIC ${CGEFILES})
TARGET_LINK_LIBRARIES(CGE GLee )
include_directories("CGE/")

include_directories("rapidxml/")

set(LIBRARIES
${OPENGL_LIBRARIES} 

${SDL_LIBRARY} 
${SDLIMAGE_LIBRARY} 
${SDLNET_LIBRARY} 
${SDLTTF_LIBRARY} 
${SDLMIXER_LIBRARY} 
SDLmain 

${LUA_LIBRARIES}

curl

CGE
)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

add_executable(zero2d ${SRCS}) 
target_link_libraries(zero2d ${LIBRARIES})


