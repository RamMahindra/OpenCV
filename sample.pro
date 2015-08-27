#-------------------------------------------------
#
# Project created by QtCreator 2015-07-17T12:41:47
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = sample
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += C:\opencv249\opencv\release\install\include

LIBS += C:\opencv249\opencv\release\bin\libopencv_core249.dll
LIBS += C:\opencv249\opencv\release\bin\libopencv_contrib249.dll
LIBS += C:\opencv249\opencv\release\bin\libopencv_highgui249.dll
LIBS += C:\opencv249\opencv\release\bin\libopencv_imgproc249.dll
LIBS += C:\opencv249\opencv\release\bin\libopencv_calib3d249.dll
LIBS += C:\opencv249\opencv\release\bin\libopencv_video249.dll
LIBS += C:\opencv249\opencv\release\bin\libopencv_videostab249.dll


SOURCES += main.cpp \
    smoothing.cpp \
    boundary.cpp \
    countours.cpp \
    edgedetection.cpp \
    thresholding.cpp \
    colortf.cpp \
    addition.cpp \
    drawing.cpp \
    mousep.cpp \
    rotation.cpp \
    dct.cpp \
    randomlines.cpp \
    split.cpp \
    randomtext.cpp \
    cropping.cpp \
    hist.cpp \
    noise.cpp \
    dctcomp.cpp \
    warping.cpp \
    trial.cpp \
    invertion.cpp \
    roi.cpp \
    comp.cpp \
    comp2.cpp
