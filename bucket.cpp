// Bucket Sort in C programming
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int getMax(int array[], int size)
{
  int max = array[0];
  for (int i = 1; i < size; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}
void bucketSort(int array[], int size)
{
  // The size of bucket must be at least the (max+1) but
  // we cannot assign declare it as int bucket(max+1) in C as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int bucket[100000];
  const int max = getMax(array, size);
  for (int i = 0; i <= max; i++)
  {
    bucket[i] = 0;
  }
  for (int i = 0; i < size; i++)
  {
    bucket[array[i]]++;
  }
  for (int i = 0, j = 0; i <= max; i++)
  {
    while (bucket[i] > 0)
    {
      array[j++] = i;
      bucket[i]--;
    }
  }

  for (int i = 0; i < size; ++i)
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main()
{
 int i,n, arr[30000];
    clock_t t1,t2;
    double t;
    printf("enter number of elements :");
    scanf("%d",&n);

//best case
    for(i=0;i<n;i++)
    {
        arr[i]=i;
    }
    t1=clock();
    bucketSort(arr,n);
    t2=clock();
    t=double(t2-t1);
    printf("\n Best case %g \n",t);
//avg case
    for(i=0;i<n;i++)
    {
        arr[i]=rand();
    }
    t1=clock();
    bucketSort(arr,n);
    t2=clock();
    t=t2-t1;
    printf("Average Case %g\n",t);
//worst case
    for(i=n;i>0;i--)
    {
        arr[i]=i;
    }
    t1=clock();
    bucketSort(arr,n);
    t2=clock();
    t=t2-t1;
    printf("Worst Case %g\n",t);
    return 0;
}
