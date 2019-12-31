project(core)

file(GLOB_RECURSE CORE_SOURCE "*.hpp" "*.cpp")

if(MSVC)
  source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CORE_SOURCE})
endif()

add_library(Core ${CORE_SOURCE})
add_definitions(-DEXPMODULE)

target_include_directories(Core
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Core glfw GLEW::GLEW ${OPENGL_LIBRARY} glm assimp::assimp SOIL)

set_target_properties(
  Core PROPERTIES
  VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)