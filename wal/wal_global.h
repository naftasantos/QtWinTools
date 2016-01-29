#ifndef WAL_GLOBAL_H
#define WAL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(WAL_LIBRARY)
#  define WALSHARED_EXPORT Q_DECL_EXPORT
#else
#  define WALSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // WAL_GLOBAL_H
