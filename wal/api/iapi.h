#ifndef IAPI_H
#define IAPI_H

#include <QString>

namespace WAL {
  namespace API {
    class IApi {
    public:
      QString error_string() { return error_string_; }
      bool valid() { return valid_; }

      virtual ~IApi() {}
      IApi() {}
    protected:
      bool valid_ = false;
      QString error_string_ = "No Error";
      virtual void Load() = 0;
    };
  }
}
#endif // IAPI_H
