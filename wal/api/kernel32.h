#ifndef KERNEL32_H
#define KERNEL32_H

#include "iapi.h"

#include <windows.h>
#include <QObject>
#include <QLibrary>

namespace WAL {
  namespace API {
    class Kernel32 : public QObject, public IApi {
      Q_OBJECT
    public:
      DWORD GetLastError(VOID);

      explicit Kernel32(QObject *parent=0);
      virtual ~Kernel32();
    protected:
      void Load();
    private:
      QLibrary lib_;

      typedef DWORD (WINAPI *GetLastErrorFuncP)(VOID);

      GetLastErrorFuncP GetLastErrorFunc;
    };
  }
}

#endif // KERNEL32_H
