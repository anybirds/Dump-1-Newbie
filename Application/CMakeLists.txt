project(application_project)

file(GLOB_RECURSE APP_SOURCE "*.hpp" "*.cpp")

if(MSVC)
  source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${APP_SOURCE})
endif()

add_executable(Application ${APP_SOURCE})

target_include_directories(Application
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Application Engine glfw GLEW::GLEW ${OPENGL_LIBRARY} glm assimp::assimp SOIL)

set_target_properties(
  Application PROPERTIES
  VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)