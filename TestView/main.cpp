#include <QCoreApplication>

#include "wal/registry/reg_key.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    WAL::Registry::RegKey key;

    return a.exec();
}

