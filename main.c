#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char *argv[]) {
    // write bytecode
    Chunk chunk;
    initChunk(&chunk);
    // constant is the 1.2 position in value array
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    writeChunk(&chunk, OP_RETURN, 123);

    // run bytecode
    disassembleChunk(&chunk, "test chunk");

    freeChunk(&chunk);
    return 0;
}
