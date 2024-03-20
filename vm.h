#ifndef cwx_vm_h
#define cwx_vm_h

#include "chunk.h"
#include "common.h"
#include "table.h"
#include "object.h"

#define UINT8_COUNT (UINT8_MAX + 1)
#define FRAMES_MAX 64
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)

// A CallFrame represents a single ongoing function call(with own local variables)
typedef struct {
    ObjClosure *closure;
    // point to run code
    uint8_t *ip;
    // point to vm first stack that this function can use (return address)
    Value *slots;
} CallFrame;

// this is use for run byte code, input chunk ,push data to stack and run
typedef struct {
    CallFrame frames[FRAMES_MAX];
    int frameCount;
    // stack to do calculate
    Value stack[STACK_MAX];
    // point to where the next value to be pushed will go
    Value *stackTop;
    Table globals;
    Table strings;
    ObjString *initString;
    ObjUpvalue *openUpvalues;
    // total bytes managed by VM
    size_t bytesAllocated;
    //  the threshold that triggers the next gc
    size_t nextGC;
    // objects linked list node
    Obj *objects;
    int grayCount;
    int grayCapacity;
    Obj **grayStack;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

void initVM();

void freeVM();

InterpretResult interpret(const char *source);

void push(Value value);

Value pop();


#endif