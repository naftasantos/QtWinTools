#ifndef ADVAPI32_H
#define ADVAPI32_H

#include "iapi.h"

#include <windows.h>
#include <QLibrary>

namespace WAL {
  namespace API {
    class Advapi32 : public QObject, public IApi {
      Q_OBJECT
    public:
      LONG RegOpenKeyEx(_In_     HKEY    hKey,
                        _In_opt_ LPCWSTR lpSubKey,
                        _In_     DWORD   ulOptions,
                        _In_     REGSAM  samDesired,
                        _Out_    PHKEY   phkResult);

      LONG RegCloseKey(_In_ HKEY hKey);

      explicit Advapi32(QObject *parent=0);
      virtual ~Advapi32();
    protected:
      void Load();
    private:
      QLibrary lib_;

      typedef LONG (WINAPI *RegOpenKeyExFuncP) (HKEY, LPCWSTR, DWORD, REGSAM,
                                                PHKEY);
      typedef LONG (WINAPI *RegCloseKeyFuncP) (HKEY);

      RegOpenKeyExFuncP RegOpenKeyExFunc;
      RegCloseKeyFuncP RegCloseKeyFunc;
    };
  }
}

#endif // ADVAPI32_H
