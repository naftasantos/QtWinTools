#ifndef ADVAPI32_H
#define ADVAPI32_H

#include "iapi.h"

#include <QLibrary>

#include <windows.h>

namespace WAL {
  namespace API {
    class Advapi32 : public QObject, public IApi {
      Q_OBJECT
    public:
      bool IsValid();
      LONG RegOpenKeyEx(_In_     HKEY    hKey,
                        _In_opt_ LPCWSTR lpSubKey,
                        _In_     DWORD   ulOptions,
                        _In_     REGSAM  samDesired,
                        _Out_    PHKEY   phkResult);

      Advapi32();
      virtual ~Advapi32();

    private:
      QLibrary lib_;
      bool valid_;
      void load();

      typedef LONG (WINAPI *RegOpenKeyExFuncP) (HKEY, LPCWSTR, DWORD, REGSAM,
                                                PHKEY);

      RegOpenKeyExFuncP RegOpenKeyExFunc;
    };
  }
}

#endif // ADVAPI32_H
