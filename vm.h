#ifndef cwx_vm_h
#define cwx_vm_h

#include "chunk.h"
#include "common.h"

#define STACK_MAX 256

// this is use for run byte code

typedef struct {
    Chunk *chunk;
    // always points to the next instruction, not the one currently being handled.
    uint8_t *ip;
    // stack to do calculate
    Value stack[STACK_MAX];
    // point to where the next value to be pushed will go
    Value *stackTop;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();

void freeVM();

InterpretResult interpret(const char *source);

void push(Value value);

Value pop();


#endif