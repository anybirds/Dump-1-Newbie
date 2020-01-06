project(engine)

file(GLOB_RECURSE ENGINE_SOURCE "*.hpp" "*.cpp")

if(MSVC)
  source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ENGINE_SOURCE})
endif()

add_library(Engine SHARED ${ENGINE_SOURCE})
add_definitions(-DEXPMODULE)

target_include_directories(Engine
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Engine Core)

set_target_properties(
  Engine PROPERTIES
  VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.6.1"
  COMMON_LANGUAGE_RUNTIME ""
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)