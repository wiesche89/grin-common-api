INCLUDEPATH += \
    $$PWD \
    $$PWD/src \
    $$PWD/src/attributes \
    $$PWD/src/util

HEADERS += \
    $$PWD/src/attributes/commitment.h \
    $$PWD/src/attributes/error.h \
    $$PWD/src/attributes/output.h \
    $$PWD/src/attributes/result.h \
    $$PWD/src/util/debugutils.h \
    $$PWD/src/util/jsonutil.h

SOURCES += \
    $$PWD/src/attributes/commitment.cpp \
    $$PWD/src/attributes/error.cpp \
    $$PWD/src/attributes/output.cpp \
    $$PWD/src/util/debugutils.cpp \
    $$PWD/src/util/jsonutil.cpp
