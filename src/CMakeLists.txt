set(SRC_FILES main.cpp note_app.cpp note_app_config.cpp note_app_utils.cpp)
set(HEADERS note_app.h note_app_config.h note_app_utils.h)

qt5_wrap_cpp(MOC_SOURCES ${HEADERS})

add_executable(note_app ${SRC_FILES} ${MOC_SOURCES})

target_include_directories(note_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(note_app PRIVATE Qt5::Widgets)