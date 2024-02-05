#ifndef cwx_vm_h
#define cwx_vm_h

#include "chunk.h"
#include "common.h"

typedef struct {
    Chunk *chunk;
    //  always points to the next instruction, not the one currently being handled.
    uint8_t *ip;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();

void freeVM();

InterpretResult interpret(Chunk *chunk);


#endif