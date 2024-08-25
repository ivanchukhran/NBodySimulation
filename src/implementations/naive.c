#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../../include/implementations/naive.h"
#include "../../include/bodySystem.h"
#include "../../include/utils.h"

static void naiveInitialization(BodySystem* system) {
    system->size = N_BODIES;
    system->bodies = (Body*)malloc(system->size * sizeof(Body));
    for (int i = 0; i < system->size; i++) {
        for (int j = 0; j < N_DIM; j++) {
            system->bodies[i].positions[j] = randomPosition(MIN_POS_VALUE, MAX_POS_VALUE);
            system->bodies[i].velocities[j] = randomVelocity(MIN_VEL_VALUE, MAX_VEL_VALUE);
            system->bodies[i].mass = randomMass(MIN_MASS_VALUE, MAX_MASS_VALUE);
            system->bodies[i].radius = randomRadius(MIN_RADIUS_VALUE, MAX_RADIUS_VALUE);
        }
    }
}

float computeForce(float mass1, float mass2, float distance) {
    return G * mass1 * mass2 / pow(distance, 2);
}

static void naiveStep(BodySystem* system, float dt) {
    for (int i = 0; i < system->size; i++) {
        Body* body1 = &system->bodies[i];
        for (int j = 0; j < system->size; j++) {
            Body* body2 = &system->bodies[j];
            if (i == j) {
                continue;
            }
            float forceProjection;
            float distance = euclideanDistance(body1->positions, N_DIM, body2->positions, N_DIM);
            for (int k = 0; k < N_DIM; k++) {
                forceProjection = computeForce(body1->mass, body2->mass, distance);
                body1->velocities[k] += forceProjection * dt / body1->mass;
                body1->positions[k] += body1->velocities[k] * dt;
            }
        }
    }
}

static void naiveFree(BodySystem* system) {
    free(system->bodies);
}

BodySystemImplementation getNaiveImplementation() {
    BodySystemImplementation implementation;
    implementation.init = naiveInitialization;
    implementation.step = naiveStep;
    implementation.free = naiveFree;
    return implementation;
}
