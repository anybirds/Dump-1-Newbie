project(app LANGUAGES CSharp)

include(CSharpUtilities)

file(GLOB_RECURSE APP_SOURCE "*.cs" "*.config" "*.xaml" "*.xaml.cs" "*.resx" "*.settings")

if(MSVC)
  source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${APP_SOURCE})
endif()

add_executable(App ${APP_SOURCE})

set_target_properties(
  App PROPERTIES
  VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.6.1"
  WIN32_EXECUTABLE TRUE
  CMAKE_CSharp_FLAGS "/langversion:latest"
)

target_link_libraries(App Custom Engine)

set_property(TARGET App PROPERTY VS_DOTNET_REFERENCES
  "Microsoft.CSharp"
  "PresentationCore"
  "PresentationFramework"
  "System"
  "System.Core"
  "System.Data"
  "System.Data.DataSetExtensions"
  "System.Net.Http"
  "System.Xaml"
  "System.Xml"
  "System.Xml.Linq"
  "WindowsBase"
)
