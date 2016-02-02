#include "advapi32.h"

#include <QDebug>

WAL::API::Advapi32::Advapi32(QObject* parent)
  : QObject(parent),
    lib_("Advapi32.dll"),
    RegOpenKeyExFunc(NULL),
    RegCloseKeyFunc(NULL) {

  lib_.setParent(this);

  Load();
}

WAL::API::Advapi32::~Advapi32() {
  if(lib_.isLoaded()) {
    lib_.unload();
  }
}

void WAL::API::Advapi32::Load() {
  valid_ = false;

  if(lib_.load()) {
    valid_ = true;

    RegOpenKeyExFunc = (RegOpenKeyExFuncP)lib_.resolve("RegOpenKeyExW");
    valid_ = valid_ && (bool)RegOpenKeyExFunc;

    if(!valid_) {
      error_string_ = lib_.errorString();
      return;
    }

    RegCloseKeyFunc = (RegCloseKeyFuncP)lib_.resolve("RegCloseKey");
    valid_ = valid_ && (bool)RegCloseKeyFunc;

    if(!valid_) {
      error_string_ = lib_.errorString();
      return;
    }
  }
  else {
    error_string_ = lib_.errorString();
  }
}

LONG WAL::API::Advapi32::RegOpenKeyEx(_In_     HKEY    hKey,
                                      _In_opt_ LPCWSTR lpSubKey,
                                      _In_     DWORD   ulOptions,
                                      _In_     REGSAM  samDesired,
                                      _Out_    PHKEY   phkResult) {
  LONG ret = -1;

  if(RegOpenKeyExFunc) {
    ret = RegOpenKeyExFunc(hKey, lpSubKey, ulOptions, samDesired, phkResult);
  }

  return ret;
}

LONG WAL::API::Advapi32::RegCloseKey(_In_ HKEY hKey) {
  LONG ret = -1;

  if(RegCloseKeyFunc) {
    ret = RegCloseKeyFunc(hKey);
  }

  return ret;
}
