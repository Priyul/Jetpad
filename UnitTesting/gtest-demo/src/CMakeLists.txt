add_library(unitTest)

target_sources(unitTest
  PRIVATE
    unitTest.cpp
  PUBLIC
    unitTest.h
  )

target_include_directories(unitTest
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
if(CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
  target_compile_options(unitTest
    PUBLIC
      "--coverage"
    )
  target_link_options(unitTest
    INTERFACE
      "--coverage"
    )
endif()
