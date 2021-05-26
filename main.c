#include "heap.h"
#include "rnddata.h"
#include "timing.h"
#include <stdio.h>

int get_int(int *a){
    int n;
    do{
        n = scanf("%d", a);
        if (n < 0) return 1;
        if (n == 0){
            printf("Error!\n");
            scanf("%*c");
        }
    } while (n == 0);
    return 0;
}


void print_mas_UI(int *mas, int len){
	printf("mas:\n");
	for (int i=0; i<len; i++){
		printf("%d ", mas[i]);
	}
	printf("\n");
}


void timing_sort_UI(void){
	printf("Enter the count of number\n");
	int len = 0;
	get_int(&len);
	double time_res = 0;
	time_res = timing_sort(len);
	printf("Result -> %.10f\n", time_res);
}


int *generate_mas_UI(int *len){
	printf("Enter the count of number\n");
	int *mas = NULL;
	get_int(len);
	mas = rnd_int_mas(*len, MIN, MAX);
	return mas;
}


int *enter_mas_UI(int *len){
	printf("Enter the count of number\n");
	get_int(len);
	int *mas = (int*)malloc((*len)*sizeof(int));
	printf("Enter number:\n");
	for (int i=0; i<(*len); i++){
		get_int(mas+i);
	}
	return mas;
}


void sort_UI(int *mas, int len){
	heap_sort(mas, len);
}


void free_mas_UI(int **mas, int *len){
	free(*mas);
	*mas = NULL;
	*len = 0;
}



void print_menu(void){
	printf("0) Generate mas\n");
	printf("1) Enter mas\n");
	printf("2) Print mas\n");
	printf("3) Sort mas\n");
	printf("4) Timing (without valgrind!)\n");
	printf("5) Free mas\n");
	printf("6) Exit\n");
}


void UI(void){
	int choice;
	int *mas = NULL;
	int len = 0;
	do{
		print_menu();
		do{
			printf("Select one of the following options\n");
			get_int(&choice);
		} while (choice<0 || choice>6);
		switch (choice){
			case 0:
			{
				if (mas != NULL) free_mas_UI(&mas, &len);
				mas = generate_mas_UI(&len);
				break;
			}
			case 1:
			{
				if (mas != NULL) free_mas_UI(&mas, &len);
				mas = enter_mas_UI(&len);
				break;
			}
			case 2:
			{
				print_mas_UI(mas, len);
				break;
			}
			case 3:{
				sort_UI(mas, len);
				break;
			}
			case 4:{
				timing_sort_UI();
				break;
			}
			case 5:{
				free_mas_UI(&mas, &len);
				break;
			}
			case 6:{
				free_mas_UI(&mas, &len);
				break;
			}
		}
	} while (choice!=6);
}


int main(void){
	printf("Hello, world!\n");
	
	UI();
	
	printf("Bye!\n");
	return 0;
}



