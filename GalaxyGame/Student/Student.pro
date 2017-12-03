#-------------------------------------------------
#
# Project created by QtCreator 2017-06-14T12:45:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GalaxyGame
TEMPLATE = app
CONFIG += c++14


SOURCES += \
    main.cc\
    galaxy.cc \
    statistics.cc \
    eventhandler.cc \
    mainwindow.cpp \
    player_ship.cpp \
    starsystemobject.cpp \
    mainmenu.cpp\
    graphicsviewcontrols.cpp \
    controls.cpp \
    encounter.cpp \
    mainwindowutility.cpp \
    gameproperties.cpp \
    game_over.cpp \
    highscores.cpp




HEADERS  += \
    galaxy.hh \
    eventhandler.hh \
    statistics.hh \
    mainwindow.hh \
    player_ship.hh \
    starsystemobject.hh \
    mainmenu.hh\
    graphicsviewcontrols.hh \
    controls.hh \
    encounter.hh \
    mainwindowutility.hh \
    gameproperties.hh \
    game_over.hh \
    highscores.hh





INCLUDEPATH += $$PWD/../Course
DEPENDPATH += $$PWD/../Course

CONFIG(release, debug|release) {
   DESTDIR = release
}

CONFIG(debug, debug|release) {
   DESTDIR = debug
}

win32 {
    copyfiles.commands += @echo NOW COPYING ADDITIONAL FILE(S) for Windows &
    copyfiles.commands += @call xcopy ..\\..\\GalaxyGame\\Assets Assets /i /s /e /y
}
unix:!macx {
    copyfiles.commands += @echo \"NOW COPYING ADDITIONAL FILE(S) for Linux\" &&
    copyfiles.commands += cp -r ../../GalaxyGame/Assets $$DESTDIR
}
macx {
    copyfiles.commands += @echo \"NOW COPYING ADDITIONAL FILE(S) for MacOS\" &&
    copyfiles.commands += mkdir -p $$DESTDIR/GalaxyGame.app/Contents/MacOS &&
    copyfiles.commands += cp -r ../../GalaxyGame/Assets $$DESTDIR &&
    copyfiles.commands += cp -r ../../GalaxyGame/Assets $$DESTDIR/GalaxyGame.app/Contents/MacOS/
}

LIBS += -L$$OUT_PWD/../Course/
LIBS += -L$$OUT_PWD/../Course/$${DESTDIR}/ -lCourse


QMAKE_EXTRA_TARGETS += copyfiles
POST_TARGETDEPS += copyfiles

FORMS += \
    mainwindow.ui \
    mainmenu.ui \
    controls.ui \
    encounter.ui \
    game_over.ui \
    highscores.ui

RESOURCES += \
    resources.qrc
