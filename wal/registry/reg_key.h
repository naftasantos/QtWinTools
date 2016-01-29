#ifndef REGKEY_H
#define REGKEY_H

#include <QObject>
#include <windows.h>

#include "wal/api/advapi32.h"

namespace WAL {
  namespace Registry {
    class RegKey : public QObject {
      Q_OBJECT
    public:
      explicit RegKey(QObject *parent = 0);
      virtual ~RegKey();
    private:
      API::Advapi32 advapi32_;
      HKEY key_;
    };
  }
}

#endif // REGKEY_H
