TEMPLATE = app
TARGET = b2block
INCLUDEPATH += src src/qt
VERSION = 1.0.0

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
lessThan(QT_MAJOR_VERSION, 5): CONFIG += static

SOURCES +=  src/qt/b2block.cpp

# Dependency library locations can be customized with:
#    BOOST_INCLUDE_PATH, BOOST_LIB_PATH


CONFIG(debug, debug|release) {
    DESTDIR = build/debug
}
CONFIG(release, debug|release) {
    DESTDIR = build/release
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.u


# for lrelease/lupdate
# also add new translations to src/qt/b2block.qrc under translations/
TRANSLATIONS = $$files(src/qt/locale/b2block_*.ts)

isEmpty(QMAKE_LRELEASE) {
    win32:QMAKE_LRELEASE = $$[QT_INSTALL_BINS]\\lrelease.exe
    else:QMAKE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease
}

system($$QMAKE_LRELEASE -silent $$_PRO_FILE_)
