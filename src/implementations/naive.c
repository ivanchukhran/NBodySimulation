#include <stdlib.h>
#include <math.h>

#include "../../include/implementations/naive.h"
#include "../../include/bodySystem.h"
#include "../../include/utils.h"

static void naiveInitialization(BodySystem* system) {
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

float euclideanDistance(float* a, int a_size, float* b, int b_size) {
    int minSize = a_size < b_size ? a_size : b_size;
    int maxSize = a_size > b_size ? a_size : b_size;
    float* minArray = a_size < b_size ? a : b;
    float* maxArray = a_size > b_size ? a : b;

    float acc = 0.0;
    for (int i = 0; i < minSize; i++) {
        for (int j = 0; j < N_DIM; j++) {
            acc += pow(minArray[i] - maxArray[i], 2);
        }
    }
    for (int i = minSize; i < maxSize; i++) {
        acc += pow(maxArray[i], 2);
    }
    float distance = sqrt(acc);
    return distance;
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
    freeBodySystem(system);
}

BodySystemImplementation getNaiveImplementation() {
    BodySystemImplementation implementation;
    implementation.init = naiveInitialization;
    implementation.step = naiveStep;
    implementation.free = naiveFree;
    return implementation;
}
