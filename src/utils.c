#include "../include/utils.h"
#include <stdlib.h>
#include <math.h>

float randomFloat(float min, float max) {
    return min + ((float) rand() / (float)RAND_MAX) * (max - min);
}

float randomPosition(float min, float max) {
    return randomFloat(min, max);
}

float randomVelocity(float min, float max) {
    return randomFloat(min, max);
}

float randomMass(float min, float max) {
    return randomFloat(min, max);
}

float randomRadius(float min, float max) {
    return randomFloat(min, max);
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
