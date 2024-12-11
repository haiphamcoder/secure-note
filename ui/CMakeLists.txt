set(UI_FILES ui.cpp)
add_library(ui ${UI_FILES})

target_include_directories(ui PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ui PRIVATE Qt5::Widgets)