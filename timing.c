#include "timing.h"

double timing_sort(int len){
	clock_t time_start = 0;
	clock_t time_end = 0;
    double timing = 0;
    double time_res = 0;
	for(int i=0; i<REPCOUNT; i++){
		int *mas = rnd_int_mas(len, MIN, MAX);
		time_start = clock();
		heap_sort(mas, len);
		time_end = clock() - time_start;
		timing = (double)time_end / CLOCKS_PER_SEC;
		time_res += timing;
		free(mas);
	}
	time_res /= REPCOUNT;
	return time_res;
}

