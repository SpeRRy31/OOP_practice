QT       += core gui widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Customer.cpp \
    Person.cpp \
    Seller.cpp \
    dialogcreatecustomer.cpp \
    dialogcreateseller.cpp \
    dialogshowcustomer.cpp \
    dialogshowseller.cpp \
    logfile.cpp \
    main.cpp \
    mainwindow.cpp \
    sqlitedbmanager.cpp

HEADERS += \
    Customer.h \
    Person.h \
    Seller.h \
    dbmanager.h \
    dialogcreatecustomer.h \
    dialogcreateseller.h \
    dialogshowcustomer.h \
    dialogshowseller.h \
    logfile.h \
    mainwindow.h \
    sqlitedbmanager.h

FORMS += \
    dialogcreatecustomer.ui \
    dialogcreateseller.ui \
    dialogshowcustomer.ui \
    dialogshowseller.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    CMakeLists.txt \
    CMakeLists.txt.user \
    MDI.pro.autosave \
    MDI.pro.user
