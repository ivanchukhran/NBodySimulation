#include <stdio.h>
#include <stdlib.h>
#include "../include/body.h"
#include "../include/bodySystem.h"
#include "../include/implementations/naive.h"
#include "../include/utils.h"


int main(int argc, char* argv[]) {
    BodySystem system;
    BodySystemImplementation implementation = getNaiveImplementation();
    implementation.init(&system);
    for (int i = 0; i < N_BODIES; i++) {
        printf("%d\t%s\n", i, bodyToString(&system.bodies[i]));
    }
    implementation.step(&system, 0.1);
    implementation.free(&system);
    return 0;
}
