project(application_project)

file(GLOB APP_HEADER "Headers/*.hpp")
file(GLOB APP_SOURCE "Sources/*.cpp")

if(MSVC)
  source_group("Headers" FILES ${APP_HEADER})
  source_group("Sources" FILES ${APP_SOURCE})
endif()

add_executable(Application ${APP_SOURCE} ${APP_HEADER})

target_include_directories(Application
  PUBLIC Headers
  PRIVATE Sources
)

target_link_libraries(Application Engine glfw GLEW::GLEW ${OPENGL_LIBRARY} glm)

set_target_properties(
  Application PROPERTIES
  VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)