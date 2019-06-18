project(engine_project)

file(GLOB ENGINE_HEADER "Headers/*.hpp")
file(GLOB ENGINE_SOURCE "Sources/*.cpp")

if(MSVC)
  source_group("Headers" FILES ${ENGINE_HEADER})
  source_group("Sources" FILES ${ENGINE_SOURCE})
endif()

add_library(Engine ${ENGINE_SOURCE} ${ENGINE_HEADER})

target_include_directories(Engine
  PUBLIC Headers
  PRIVATE Sources
)

target_link_libraries(Engine glfw GLEW::GLEW ${OPENGL_LIBRARY} glm)

set_target_properties(
  Engine PROPERTIES
  VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)