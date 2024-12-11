set(UTILS_FILES logger.cpp string_utils.cpp)
add_library(utils ${UTILS_FILES})

target_include_directories(utils PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
