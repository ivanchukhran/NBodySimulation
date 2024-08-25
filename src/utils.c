#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../include/utils.h"

char* arrToString(const float* arr, int size) {
    if (arr == NULL || size <= 0) {
        return NULL;
    }
    int max_length = 2 + (size * MAX_FLOAT_STR_LENGTH) + (size - 1) * 2 + 1;
    char* str = (char*) malloc(max_length * sizeof(char));
    if (str == NULL) {
        return NULL;
    }
    strcpy(str, "[");
    int current_position = 1;
    for (int i = 0; i < size; i++) {
        int chars_written = snprintf(str + current_position, max_length - current_position,
                                     "%.3e", arr[i]);
        if (chars_written < 0 || chars_written >= max_length - current_position) {
            free(str);
            return NULL;
        }
        current_position += chars_written;
        if (i < size - 1) {
            if (current_position + 2 >= max_length) {
                free(str);
                return NULL;
            }
            strcat(str, ", ");
            current_position += 2;
        }
    }
    if (current_position + 1 >= max_length) {
        free(str);
        return NULL;
    }
    strcat(str, "]");
    return str;
}

char* bodyToString(const Body* body) {
    if (body == NULL) {
        return NULL;
    }
    char * str = (char*) malloc(BODY_STRING_MAX_LENGTH * sizeof(char));
    if (str == NULL) {
        return NULL;
    }
    int chars_written = snprintf(str, BODY_STRING_MAX_LENGTH, "Body (pos: %s, vel: %s, mass: %.3e, radius: %.3e)",
                                 arrToString(body->positions, N_DIM), arrToString(body->velocities, N_DIM),
                                 body->mass, body->radius);
    if (chars_written < 0 || chars_written >= BODY_STRING_MAX_LENGTH) {
        free(str);
        return NULL;
    }
    return str;
}

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
    int minSize = a_size <= b_size ? a_size : b_size;
    int maxSize = a_size > b_size ? a_size : b_size;
    float* minArray = a_size <= b_size ? a : b;
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
