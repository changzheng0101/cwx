#ifndef cwx_chunk_h
#define cwx_chunk_h

#include "common.h"
#include "value.h"

// each instruction has a one-byte operation code
typedef enum {
    OP_CONSTANT,
    OP_NEGATE,
    OP_PRINT,
    OP_JUMP,
    OP_JUMP_IF_FALSE,
    OP_NIL,
    OP_TRUE,
    OP_FALSE,
    OP_POP,
    OP_GET_LOCAL,
    OP_SET_LOCAL,
    OP_GET_GLOBAL,
    OP_DEFINE_GLOBAL,
    OP_SET_GLOBAL,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NOT,
    OP_BACK,
    OP_RETURN,
} OpCode;

// “chunk” to refer to sequences of bytecode
// the data will store in a vector structure (we call this Chunk)
typedef struct {
    int count;
    int capacity;
    uint8_t *code;
    int *lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);

void freeChunk(Chunk *chunk);

void writeChunk(Chunk *chunk, uint8_t byte, int line);

int addConstant(Chunk *chunk, Value value);

#endif