QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

#INCLUDEPATH += ../..

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Factory/ConcreteUnitFactory/unitcpp.cpp \
        Factory/ConcreteUnitFactory/unitcsharp.cpp \
        Factory/ConcreteUnitFactory/unitjava.cpp \
        Factory/unitfactory.cpp \
        Products/ConcreteClassUnit/classunitcpp.cpp \
        Products/ConcreteClassUnit/classunitcsharp.cpp \
        Products/ConcreteClassUnit/classunitjava.cpp \
        Products/ConcreteMethodUnit/methodunitcpp.cpp \
        Products/ConcreteMethodUnit/methodunitcsharp.cpp \
        Products/ConcreteMethodUnit/methodunitjava.cpp \
        Products/ConcretePrintOperatorUnit/printoperatorunitcpp.cpp \
        Products/ConcretePrintOperatorUnit/printoperatorunitcsharp.cpp \
        Products/ConcretePrintOperatorUnit/printoperatorunitjava.cpp \
        Products/classunit.cpp \
        Products/methodunit.cpp \
        Products/printoperatorunit.cpp \
        Products/unit.cpp \
        codegenerator.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Factory/ConcreteUnitFactory/unitcpp.h \
    Factory/ConcreteUnitFactory/unitcsharp.h \
    Factory/ConcreteUnitFactory/unitjava.h \
    Factory/unitfactory.h \
    Products/ConcreteClassUnit/classunitcpp.h \
    Products/ConcreteClassUnit/classunitcsharp.h \
    Products/ConcreteClassUnit/classunitjava.h \
    Products/ConcreteMethodUnit/methodunitcpp.h \
    Products/ConcreteMethodUnit/methodunitcsharp.h \
    Products/ConcreteMethodUnit/methodunitjava.h \
    Products/ConcretePrintOperatorUnit/printoperatorunitcpp.h \
    Products/ConcretePrintOperatorUnit/printoperatorunitcsharp.h \
    Products/ConcretePrintOperatorUnit/printoperatorunitjava.h \
    Products/classunit.h \
    Products/methodunit.h \
    Products/printoperatorunit.h \
    Products/unit.h \
    codegenerator.h
