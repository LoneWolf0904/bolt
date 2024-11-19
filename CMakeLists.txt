cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(bolt)

add_definitions(-DSDL_MAIN_HANDLED)

include_directories(
	src
	contrib/cl-windows-x86_64/include
)

link_directories(
	contrib/cl-windows-x86_64/lib
)

add_library(rend
  src/rend/Animation.cpp
  src/rend/Buffer.cpp
  src/rend/Debug.cpp
  src/rend/Font.cpp
  src/rend/Mesh.cpp
  src/rend/Model.cpp
  src/rend/ModelShader.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/TextShader.cpp
  src/rend/Texture.cpp
  src/rend/rendmath.cpp
  src/rend/utils.cpp
)

target_link_libraries(rend glew32 SDL2 opengl32)

add_library(bolt
  src/bolt/bolt.h
  src/bolt/Core.cpp src/bolt/Core.h 
  src/bolt/Entity.cpp src/bolt/Entity.h
  src/bolt/Component.h src/bolt/Component.cpp
  src/bolt/TriangleRenderer.h src/bolt/TriangleRenderer.cpp
  src/bolt/Window.cpp src/bolt/Window.h
  src/bolt/Resource.cpp src/bolt/Resource.h
  src/bolt/Resources.cpp src/bolt/Resources.h
  src/bolt/Texture.h
)

target_link_libraries(bolt rend)

add_executable(demo
  src/demo/main.cpp
  src/demo/Employee.cpp src/demo/Employee.h
)

target_link_libraries(demo bolt)