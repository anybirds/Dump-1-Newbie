project(engine_project)

file(GLOB_RECURSE ENGINE_SOURCE "*.hpp" "*.cpp")

if(MSVC)
  source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ENGINE_SOURCE})
endif()

add_library(Engine ${ENGINE_SOURCE})

target_include_directories(Engine
  PUBLIC Header
  PRIVATE Source
)

target_link_libraries(Engine glfw GLEW::GLEW ${OPENGL_LIBRARY} glm)

set_target_properties(
  Engine PROPERTIES
  VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)