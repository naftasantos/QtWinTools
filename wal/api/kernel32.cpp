#include "kernel32.h"

WAL::API::Kernel32::Kernel32(QObject* parent)
  : QObject(parent),
    lib_("Kernel32.dll"),
    GetLastErrorFunc(NULL) {
  Load();
}

WAL::API::Kernel32::~Kernel32() {

}

void WAL::API::Kernel32::Load() {
  valid_ = false;

  if(lib_.load()) {
    valid_ = true;

    GetLastErrorFunc = (GetLastErrorFuncP)lib_.resolve("GetLastError");
    valid_ = valid_ && (bool)GetLastErrorFunc;

    if(!valid_) {
      error_string_ = lib_.errorString();
    }
  }
  else {
    error_string_ = lib_.errorString();
  }
}

DWORD WAL::API::Kernel32::GetLastError(VOID) {
  DWORD ret = -1;

  if(GetLastErrorFunc) {
    ret = GetLastErrorFunc();
  }

  return ret;
}
