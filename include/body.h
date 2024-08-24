#ifndef BODY_H_
#define BODY_H_

#define N_DIM 3

#define G 6.67408e-11

#define MIN_POS_VALUE 0
#define MAX_POS_VALUE 1000

#define MIN_VEL_VALUE -100
#define MAX_VEL_VALUE 100

#define MIN_MASS_VALUE 1
#define MAX_MASS_VALUE 1e3

#define MIN_RADIUS_VALUE 1
#define MAX_RADIUS_VALUE 1e2

typedef struct {
    float positions[N_DIM];
    float velocities[N_DIM];
    float radius;
    float mass;

} Body;

void initBody(Body *body);
void freeBody(Body *body);

#endif // BODY_H_
