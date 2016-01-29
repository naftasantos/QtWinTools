#include "reg_key.h"

#include <QDebug>

WAL::Registry::RegKey::RegKey(QObject *parent)
  : QObject(parent) {
  if(advapi32_.IsValid()) {
    LONG ret = advapi32_.RegOpenKeyEx(HKEY_CURRENT_USER,
                                      L"",
                                      0,
                                      KEY_ALL_ACCESS,
                                      &key_);

    if(ERROR_SUCCESS != ret) {
      qCritical() << "Unable to load current user";
    }
  }
}

WAL::Registry::RegKey::~RegKey() {

}
