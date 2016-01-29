#ifndef IAPI_H
#define IAPI_H

class IApi {
public:
  virtual bool IsValid() = 0;
  virtual ~IApi() {}
  IApi() {}
};

#endif // IAPI_H
