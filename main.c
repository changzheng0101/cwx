#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char *argv[]) {
    // write bytecode
    Chunk chunk;
    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN);
    freeChunk(&chunk);

    // run bytecode
    disassembleChunk(&chunk, "test chunk");

    return 0;
}
