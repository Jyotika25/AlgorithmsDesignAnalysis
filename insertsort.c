#include<stdio.h>

#include<time.h>

#include<stdlib.h>

void insertionSort(int array[], int size)

{
	int i, key, j, k;
	for (i = 1; i < size; i++)
	{ key = array[i];
 	  j = i-1;
		while (j >= 0 && array[j] > key)
		 {

           array[j+1] = array[j];

           j = j-1;

       }

       array[j+1] = key;

	}

   printf("\n Sorted array: \n");

   for(k=0;k<size;++k)
   {
		printf("%d", array[k]);
		printf(" ");

   }

}

int main()
	{
    int size, i, arr[30000], n_arr;
	clock_t t1, t2;
    double t;
	printf("Enter size of array:");
    scanf("%d", &size);

    //Best Case

    for(i=size; i>0; i--)
    arr[i]  = i;
	t1 = clock();
    insertionSort(arr, size);
	t2 = clock();
    t =(double) (t2 - t1);
    printf("\n Time: %g", t);
return 0;

}
