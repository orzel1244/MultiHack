QT += quick network
QT += concurrent
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    class/Offsets/offsets.cpp \
    class/Manager/manager.cpp \
    class/TriggerBot/triggerbot.cpp \
    class/Memory/memory.cpp \
    class/KeyTranslator/keytranslator.cpp \
    class/BunnyHop/bunnyhop.cpp \
    class/Misc/misc.cpp \
    class/Glow/glow.cpp \
    class/AntiScriptKiddie/antiscriptkiddie.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    class/Offsets/offsets.h \
    class/Manager/manager.h \
    class/TriggerBot/triggerbot.h \
    class/Memory/memory.h \
    class/KeyTranslator/keytranslator.h \
    class/BunnyHop/bunnyhop.h \
    class/Misc/misc.h \
    class/Glow/glow.h \
    class/AntiScriptKiddie/antiscriptkiddie.h

LIBS += -LC:/OpenSSL-Win32/lib/MinGW -leay32
INCLUDEPATH += C:/OpenSSL-Win32/include/openssl
