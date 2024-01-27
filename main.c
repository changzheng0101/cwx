#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char *argv[]) {
    initVM();

    // write bytecode
    Chunk chunk;
    initChunk(&chunk);
    // constant is the 1.2 position in value array
    int constant = addConstant(&chunk, 2.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);
//    writeChunk(&chunk, OP_NEGATE, 123);

    constant = addConstant(&chunk, 3.4);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    writeChunk(&chunk, OP_ADD, 123);

    constant = addConstant(&chunk, 5.6);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    writeChunk(&chunk, OP_DIVIDE, 123);

    writeChunk(&chunk, OP_RETURN, 123);

    // run bytecode
    disassembleChunk(&chunk, "test chunk");

    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);
    return 0;
}
