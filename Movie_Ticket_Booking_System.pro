QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cancel_seat_1.cpp \
    cancel_seat_2.cpp \
    confirm_booking_1.cpp \
    confirm_booking_2.cpp \
    main.cpp \
    mainwindow.cpp \
    screen_1.cpp \
    screen_2.cpp \
    select_seat_1.cpp \
    select_seat_2.cpp \
    system_database.cpp

HEADERS += \
    cancel_seat_1.h \
    cancel_seat_2.h \
    confirm_booking_1.h \
    confirm_booking_2.h \
    mainwindow.h \
    screen_1.h \
    screen_2.h \
    select_seat_1.h \
    select_seat_2.h \
    system_database.h

FORMS += \
    cancel_seat_1.ui \
    cancel_seat_2.ui \
    confirm_booking_1.ui \
    confirm_booking_2.ui \
    mainwindow.ui \
    screen_1.ui \
    screen_2.ui \
    select_seat_1.ui \
    select_seat_2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
