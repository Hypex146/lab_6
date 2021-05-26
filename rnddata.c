#include "rnddata.h"

int rnd_int(int start, int end){
    return (start + rand()%(end - start + 1));
}


int *rnd_int_mas(int len, int min, int max){
	srand(time(NULL));
	int *mas = (int*)malloc(len*sizeof(int));
	for (int i=0; i<len; i++){
		mas[i] = rnd_int(min, max);
	}
	return mas;
}



