﻿#ifndef DEMO_VALUE_H
#define DEMO_VALUE_H

#include "common.h"

typedef double Value;

typedef struct {
    int capacity;
    int count;
    Value *values;
} ValueArray;

void initValueArray(ValueArray *array);

void writeValueArray(ValueArray *array, Value value);

void freeValueArray(ValueArray *array);

void printValue(Value value);


#endif //DEMO_VALUE_H
