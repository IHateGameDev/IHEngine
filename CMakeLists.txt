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

function(add_library_with_install lib_name head_dir)
  file(GLOB SOURCES "src/${head_dir}/*.cpp")
  set(HEADERS_DIR "${head_dir}")

  add_library(${lib_name} SHARED ${SOURCES})

  target_include_directories(${lib_name} PUBLIC
    ${CMAKE_SOURCE_DIR}/
  )

  install(TARGETS ${lib_name}
    DESTINATION lib)

  install(DIRECTORY ${HEADERS_DIR}/
    DESTINATION include/IHEngine/${HEADERS_DIR})
endfunction()


option(LIBS "Enable building libs" ON)
if(LIBS)
  ###### MATH ######
  option(LIBRARY_MATH "Enable building math library" ON)
  if(LIBRARY_MATH)
    add_library_with_install(ih-engine-math "Math")
  endif()
  
  ###### CORE ######
  option(LIBRARY_CORE "Enable building core library" ON)
  if(LIBRARY_CORE)
    add_library_with_install(ih-engine-core "Core")
  endif()
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
