#ifndef CWX_COMPILER_H
#define CWX_COMPILER_H

#include "vm.h"
#include "object.h"

ObjFunction *compile(const char *source);

void markCompilerRoots();

#endif //CWX_COMPILER_H
