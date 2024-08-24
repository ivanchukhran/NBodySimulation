#ifndef UTILS_H_
#define UTILS_H_

#include "body.h"

float randomFloat(float min, float max);
float randomPosition(float min, float max);
float randomVelocity(float min, float max);
float randomMass(float min, float max);
float randomRadius(float min, float max);
float computeForce(float mass1, float mass2, float distance);
float euclideanDistance(float* a, int a_size, float* b, int b_size);

#endif // UTILS_H_
