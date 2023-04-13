cmake_minimum_required(VERSION 3.5)

set(PROJECT_SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    src/mainView/mainview.h
    src/mainView/mainview.cpp
    src/gameScene/gamescene.h
    src/gameScene/gamescene.cpp
    resources.qrc
    src/gameScene/items/cards/digitCard/digitcard.h
    src/gameScene/items/cards/digitCard/digitcard.cpp
    src/gameScene/items/cards/characterCard/charactercard.h
    src/gameScene/items/cards/characterCard/charactercard.cpp
    src/gameScene/items/cards/icard.h
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include_directories(src)
include_directories(src/gameScene)

install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
