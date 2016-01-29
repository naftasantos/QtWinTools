TEMPLATE = subdirs

SUBDIRS += \
    wal \
    TestView

TestView.depends = wal
