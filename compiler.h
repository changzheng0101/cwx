#ifndef CWX_COMPILER_H
#define CWX_COMPILER_H

#include "vm.h"
#include "object.h"

ObjFunction *compile(const char *source);

#endif //CWX_COMPILER_H
