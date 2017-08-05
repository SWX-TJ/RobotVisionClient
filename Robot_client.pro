#-------------------------------------------------
#
# Project created by QtCreator 2017-07-22T19:54:37
#
#-------------------------------------------------

QT       += core gui
QT       +=multimedia
QT       +=multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = Robot_client
TEMPLATE = app
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        client_mainwindow.cpp \
    log_window.cpp \
    register_dialog.cpp \
    serport_dialog.cpp \
    tcp_dialog.cpp \
    image_processthread.cpp \
    stratgy_processthread.cpp \
    camerasetting_dialog.cpp \
    calibrationsinglecamera.cpp \
    goaldetection_dialog.cpp \
    pictureset_dialog.cpp

HEADERS += \
        client_mainwindow.h \
    log_window.h \
    register_dialog.h \
    serport_dialog.h \
    tcp_dialog.h \
    image_processthread.h \
    stratgy_processthread.h \
    camerasetting_dialog.h \
    calibrationsinglecamera.h \
    goaldetection_dialog.h \
    pictureset_dialog.h

FORMS += \
        client_mainwindow.ui \
    log_window.ui \
    register_dialog.ui \
    serport_dialog.ui \
    tcp_dialog.ui \
    camerasetting_dialog.ui \
    calibrationsinglecamera.ui \
    goaldetection_dialog.ui \
    pictureset_dialog.ui

RESOURCES += \
    resource.qrc

DISTFILES += \
    Readme

INCLUDEPATH += F:/opencvmingw/include
INCLUDEPATH += F:/opencvmingw/include/opencv
INCLUDEPATH += F:/opencvmingw/include/opencv2
DEPENDPATH += F:/opencvmingw/include

win32: LIBS += -LF:/opencvmingw/lib/ -llibopencv_core320.dll
win32: LIBS += -LF:/opencvmingw/lib/ -llibopencv_highgui320.dll
win32: LIBS += -LF:/opencvmingw/lib/ -llibopencv_imgproc320.dll
win32: LIBS += -LF:/opencvmingw/lib/ -llibopencv_calib3d320.dll
win32: LIBS += -LF:/opencvmingw/lib/ -llibopencv_features2d320.dll
win32: LIBS += -LF:/opencvmingw/lib/ -llibopencv_video320.dll
win32: LIBS += -LF:/opencvmingw/lib/ -llibopencv_videoio320.dll
win32: LIBS += -LF:/opencvmingw/lib/ -llibopencv_videostab320.dll
win32: LIBS += -LF:/opencvmingw/lib/ -llibopencv_flann320.dll
win32: LIBS += -LF:/opencvmingw/lib/ -llibopencv_objdetect320.dll
win32: LIBS += -LF:/opencvmingw/lib/ -llibopencv_photo320.dll
win32: LIBS += -LF:/opencvmingw/lib/ -llibopencv_imgcodecs320.dll
win32: LIBS += -LF:/opencvmingw/lib/ -llibopencv_superres320.dll
win32: LIBS += -LF:/opencvmingw/lib/ -llibopencv_shape320.dll
win32: LIBS += -LF:/opencvmingw/lib/ -llibopencv_stitching320.dll
win32: LIBS += -LF:/opencvmingw/lib/ -llibopencv_ml320.dll
