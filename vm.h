#ifndef cwx_vm_h
#define cwx_vm_h

#include "chunk.h"
#include "common.h"
#include "table.h"
#include "object.h"

#define UINT8_COUNT (UINT8_MAX + 1)
#define FRAMES_MAX 64
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)

// A CallFrame represents a single ongoing function call
typedef struct {
    ObjFunction *function;
    // return address
    uint8_t *ip;
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
    // objects linked list node
    Obj *objects;
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