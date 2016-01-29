#include "advapi32.h"

#include <QDebug>

WAL::API::Advapi32::Advapi32() :
  lib_("Advapi32.dll"),
  valid_(false),
  RegOpenKeyExFunc(NULL) {

  lib_.setParent(this);

  load();
}

WAL::API::Advapi32::~Advapi32() {

}

void WAL::API::Advapi32::load() {
  valid_ = true;

  RegOpenKeyExFunc = (RegOpenKeyExFuncP)lib_.resolve("RegOpenKeyExW");
  valid_ = valid_ && (bool)RegOpenKeyExFunc;

  if(!valid_) {
    qDebug() << QString("Error opening function: %1").arg(lib_.errorString());
  }
}

bool WAL::API::Advapi32::IsValid() {
  return valid_;
}

LONG WAL::API::Advapi32::RegOpenKeyEx(_In_     HKEY    hKey,
                                      _In_opt_ LPCWSTR lpSubKey,
                                      _In_     DWORD   ulOptions,
                                      _In_     REGSAM  samDesired,
                                      _Out_    PHKEY   phkResult) {
  LONG ret = -1;

  if(RegOpenKeyExFunc) {
    ret = RegOpenKeyEx(hKey, lpSubKey, ulOptions, samDesired, phkResult);
  }

  return ret;
}
