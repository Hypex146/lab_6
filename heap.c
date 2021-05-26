#include "heap.h"


static void swap(int *mas, int first_index, int second_index){
	int tmp = mas[first_index];
	mas[first_index] = mas[second_index];
	mas[second_index] = tmp;
}


static void heap_one_more(int *mas, int len, int root_index){
	int largest_index = root_index;
	int left_index = 2 * root_index + 1;
	int right_index = left_index + 1;
	
	if (left_index<len && mas[left_index]>mas[largest_index]){
		largest_index = left_index;
	}
	
	if (right_index<len && mas[right_index]>mas[largest_index]){
		largest_index = right_index;
	}
	
	if (root_index!=largest_index){
		swap(mas, root_index, largest_index);
		heap_one_more(mas, len, largest_index);
	}
}


static void do_heap(int *mas, int len){
	for (int i=len-1; i>=0; i--){
		heap_one_more(mas, len, i);
	}
}


void heap_sort(int *mas, int len){
	do_heap(mas, len);
	for (int i=len-1; i>0; i--){
		swap(mas, 0, i);
		heap_one_more(mas, i, 0);
	}
}

