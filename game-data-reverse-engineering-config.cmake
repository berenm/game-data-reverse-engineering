# AUTOGENERATED
if (TARGET game-data-reverse-engineering::game-data-reverse-engineering)
  return()
endif()
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}"
  "${CMAKE_BINARY_DIR}/packages/game-data-reverse-engineering" EXCLUDE_FROM_ALL)
message(STATUS "Found game-data-reverse-engineering ${game-data-reverse-engineering_VERSION} (source)")
