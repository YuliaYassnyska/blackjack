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
    src/gameScene/items/cardItem/carditem.h
    src/gameScene/items/cardItem/carditem.cpp
    src/gameScene/items/cardItem/icard.h
    src/enums/cardEnums/cardenums.cpp
    src/enums/cardEnums/cardenums.h
    src/gameScene/items/factory/cardfactory.h
    src/gameScene/items/factory/cardfactory.cpp
    src/gameScene/items/factory/icardfactory.h
    src/model/items/cardItem/carditem.h
    src/model/items/cardItem/carditem.cpp
    src/model/items/cardItem/icard.h
    src/model/controller/modelcontroller.cpp
    src/model/controller/modelcontroller.h
    src/gameScene/controller/scenecontroller.h
    src/gameScene/controller/scenecontroller.cpp
    src/gameScene/items/buttonItem/buttonitem.h
    src/gameScene/items/buttonItem/buttonitem.cpp
    src/gameScene/items/dibItem/dibitem.h
    src/gameScene/items/dibItem/dibitem.cpp
    src/gameScene/items/labels/betLabel/betlabel.h
    src/gameScene/items/labels/betLabel/betlabel.cpp
    src/gameScene/items/labels/ilabel.h
    src/gameScene/items/labels/pointLabel/pointlabel.h
    src/gameScene/items/labels/pointLabel/pointlabel.cpp
    src/gameScene/items/players/iplayer.h
    src/gameScene/items/players/player/player.h
    src/gameScene/items/players/player/player.cpp
    src/gameScene/items/players/dealer/dealer.h
    src/gameScene/items/players/dealer/dealer.cpp
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
