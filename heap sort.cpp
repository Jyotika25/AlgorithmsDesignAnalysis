//Heap sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//void heap_sort();

//void heap_adjust(int, int);
void heap_adjust(int n, int i, int *arr_sort) {
  int large = i, left = 2 * i + 1, right = 2 * i + 2,t;

  // adjest left child
  if (left < n && arr_sort[left] > arr_sort[large])
    large = left;

  // adjest right child
  if (right < n && arr_sort[right] > arr_sort[large])
    large = right;


  if (large != i) {
    //Swapping Values
    t = arr_sort[i];
    arr_sort[i] = arr_sort[large];
    arr_sort[large] = t;
    heap_adjust(n, large,arr_sort);
  }
}


void heap_sort(int *arr_sort, int size) {
	int i,t,a;
  for (i = size / 2 - 1; i >= 0; i--)
    heap_adjust(size, i,arr_sort);

  for (i = size - 1; i >= 0; i--) {
    //Swapping Values
    t = arr_sort[0];
    arr_sort[0] = arr_sort[i];
    arr_sort[i] = t;
    heap_adjust(i, 0, arr_sort);

    /*printf("\nHeap Sort Iteration %d : ", i);
    for (a = 0; a < size; a++) {
      printf("\t%d", arr_sort[a]);
    } */ }
    for(i = 0; i < size; i++)
            printf("%d  ", arr_sort[i]);
        printf("\n");
}



int main() {
  int i;
  int arr_sort[30000],size;
  clock_t t1,t2;
  double t3;

  printf("\nEnter the size of array\n");
  scanf("%d",&size);
  //best case
  for (i = 0; i < size; i++)
  arr_sort[i]=i;
  t1=clock();
  heap_sort(arr_sort, size);
  t2 = clock();
  t3= (t2-t1);
 printf("\n best Time %g\n",t3);

 //average case
  for (i = 0; i < size; i++)
  arr_sort[i]=rand();
  t1=clock();
  heap_sort(arr_sort, size);
  t2 = clock();
  t3= (t2-t1);
 printf("\n average Time %g\n",t3);
 
  //worst case
  for (i = size; i > 0; i--)
  arr_sort[i]=i;
  t1=clock();
  heap_sort(arr_sort, size);
  t2 = clock();
  t3= (t2-t1);
 printf("\n worst Time %g\n",t3);
	return 0;


}

