#ifndef RNDDATA_H
#define RNDDATA_H

#include <stdlib.h>
#include <time.h>

#define MIN -100000
#define MAX 100000

int rnd_int(int start, int end);
int *rnd_int_mas(int len, int min, int max);

#endif