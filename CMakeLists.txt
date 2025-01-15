cmake_minimum_required(VERSION 3.10)
project(ih-engine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(REMOVE_CACHE "Enable remove cache" OFF)
  if(REMOVE_CACHE)
  if(EXISTS "${CMAKE_BINARY_DIR}/CMakeCache.txt")
      file(REMOVE "${CMAKE_BINARY_DIR}/CMakeCache.txt")
  endif()

  if(EXISTS "${CMAKE_BINARY_DIR}/CMakeFiles")
      file(REMOVE_RECURSE "${CMAKE_BINARY_DIR}/CMakeFiles")
  endif()
endif()


option(LIBRARY_CORE "Enable building library" ON)
if(LIBRARY_CORE)
  include_directories(
    ${CMAKE_SOURCE_DIR}/
  )

  file(GLOB SOURCES
      "Core/src/*.cpp"
  )

  set(HEADERS_DIR "Core")

  add_library(ih-engine-core SHARED ${SOURCES})

  install(TARGETS ih-engine-core
      DESTINATION lib)

  install(DIRECTORY HEADERS_DIR
      DESTINATION include/IHEngine/Core)
endif()


# option(EXAMPLES "Enable building examples" ON)
# if(EXAMPLES)
#   include_directories(../)

#   file(GLOB EXAMPLES
#       "Examples/*.cpp"
#   )

#   foreach(Example IN LISTS EXAMPLES)
#     get_filename_component(ExampleName ${Example} NAME_WE)
#     add_executable(${ExampleName} ${Example})
#     target_link_libraries(${ExampleName} ih-engine-core)
#   endforeach()
# endif()
