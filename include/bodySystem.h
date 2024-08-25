#ifndef BODY_SYSTEM_H_


#define BODY_SYSTEM_H_

#include "body.h"
#define N_BODIES 10

typedef struct {
    Body *bodies;
    int size;
} BodySystem;

// Function pointer types for the n-body implementation
typedef void (*InitializeSystemFunc)(BodySystem* system);
typedef void (*StepSystemFunc)(BodySystem* system, float dt);
typedef void (*FreeSystemFunc)(BodySystem* system);

typedef struct {
    InitializeSystemFunc init;
    StepSystemFunc step;
    FreeSystemFunc free;
} BodySystemImplementation;

extern BodySystemImplementation getNaiveImplementation();
extern BodySystemImplementation getBarnesHutImplementation();
extern BodySystemImplementation getCUDAImplementation();

#endif // BODY-SYSTEM_H_
