#ifndef cwx_chunk_h
#define cwx_chunk_h

#include "common.h"

// each instruction has a one-byte operation code
typedef enum
{
    OP_RETURN,
} OpCode;

// “chunk” to refer to sequences of bytecode
// the data will store in a vector structure (we call this Chunk)
typedef struct
{
    int count;
    int capacity;
    uint8_t *code;
} Chunk;

void initChunk(Chunk *chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);

#endif