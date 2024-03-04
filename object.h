#ifndef CWX_OBJECT_H
#define CWX_OBJECT_H

#include "common.h"
#include "value.h"

#define OBJ_TYPE(value)        (AS_OBJ(value)->type)

#define IS_STRING(value)       isObjType(value, OBJ_STRING)

#define AS_STRING(value)       ((ObjString*)AS_OBJ(value))
#define AS_CSTRING(value)      (((ObjString*)AS_OBJ(value))->chars)

typedef enum {
    OBJ_STRING,
} ObjType;

// Struct Inheritance : Obj* and ObjString* can convert to each other
struct Obj {
    ObjType type;
    struct Obj *next;
};

struct ObjString {
    Obj obj;
    int length;
    char *chars;
    uint32_t hash;
};

ObjString *makeString(char *chars, int length);

ObjString *copyString(const char *chars, int length);

void printObject(Value value);

static inline bool isObjType(Value value, ObjType type) {
    return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

#endif //CWX_OBJECT_H
