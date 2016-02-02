#include "reg_key.h"

#include <QDebug>
#include <QTextStream>

WAL::Registry::RegKey::RegKey(QObject *parent)
  : QObject(parent),
    advapi32_(this),
    kernel32_(this),
    key_(NULL) {

  QTextStream err(stderr);
  QTextStream out(stdout);

  if(advapi32_.valid()) {
    LONG ret = advapi32_.RegOpenKeyEx(HKEY_CURRENT_USER,
                                      L"",
                                      0,
                                      KEY_ALL_ACCESS,
                                      &key_);

    if(ERROR_SUCCESS != ret) {
      if(kernel32_.valid()) {
        err << QString("Unable to load current user: %1").arg(
                         QString::number(kernel32_.GetLastError())) << endl;
      }
      else {
        err << QString("Unable to load current user") << endl;
      }

      err.flush();
    }
    else {
      HKEY tmp;

      ret = advapi32_.RegOpenKeyEx(key_,
                                   L"blablabla",
                                   0,
                                   KEY_ALL_ACCESS,
                                   &tmp);

      if(ERROR_SUCCESS != ret) {
        if(kernel32_.valid()) {
          err << QString("Unable to load key: %1").arg(
                           QString::number(kernel32_.GetLastError())) << endl;
        }
        else {
          err << QString("Unable to load key") << endl;
        }

        err.flush();
      }
      else {
        advapi32_.RegCloseKey(tmp);
        out << "Success" << endl;
      }
    }
  }
  else {
    err << "Advapi is not valid. " << advapi32_.error_string() << endl;
  }
}

WAL::Registry::RegKey::~RegKey() {
  if(key_) {
    advapi32_.RegCloseKey(key_);
  }
}
