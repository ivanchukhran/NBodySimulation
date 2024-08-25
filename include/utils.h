#ifndef UTILS_H_
#define UTILS_H_

#include "body.h"

#define MAX_FLOAT_STR_LENGTH 10
#define BODY_STRING_MAX_LENGTH 256


char* arrToString(const float* arr, int size);
char* bodyToString(const Body* body);

float randomFloat(float min, float max);
float randomPosition(float min, float max);
float randomVelocity(float min, float max);
float randomMass(float min, float max);
float randomRadius(float min, float max);
float euclideanDistance(float* a, int a_size, float* b, int b_size);

#endif // UTILS_H_
