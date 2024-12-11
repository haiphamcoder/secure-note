set(ENCRYPTION_FILES encryption.cpp)
add_library(encryption ${ENCRYPTION_FILES})

target_include_directories(encryption PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
