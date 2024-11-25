# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Basic_Qt_autogen"
  "CMakeFiles\\Basic_Qt_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Basic_Qt_autogen.dir\\ParseCache.txt"
  )
endif()
