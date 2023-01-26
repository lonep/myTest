TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += no_keywords

DEFINES += "DTBB_ENABLE_IPO=OFF"
DEFINES += "BUILD_SHARED_LIBS=OFF"


SOURCES += \
        main.cpp \

win32:CONFIG(release, debug|release): LIBS += \
    -L$$PWD/3rd_party/Curves/lib/ -lCurves \
    -L$$PWD/3rd_party/Tbb/lib/ -ltbb \

else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$PWD/3rd_party/Curves/lib/ -lCurves \
    -L$$PWD/3rd_party/Tbb/lib/ -ltbb \

INCLUDEPATH += \
    $$PWD/3rd_party/Curves/include \
    $$PWD/3rd_party/Tbb/include \

DEPENDPATH +=  \
    $$PWD/3rd_party/Curves/include \
    $$PWD/3rd_party/Tbb/include \
