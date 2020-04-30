#include<stdio.h>
#include<time.h>
#include<stdlib.h>


// Radix Sort in C Programming
#include <stdio.h>
int getMax(int array[], int n)
{
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}
void countingSort(int array[], int size, int place)
{
  int output[size + 1];
  int max = (array[0] / place) % 10;
  for (int i = 1; i < size; i++)
  {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];
  for (int i = 0; i < max; ++i)
    count[i] = 0;
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];
  for (int i = size - 1; i >= 0; i--)
  {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }
  for (int i = 0; i < size; i++)
    array[i] = output[i];
}
void radixsort(int array[], int size)
{
  int max = getMax(array, size);
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
int main()
{
   int i, n, array[100000];
    clock_t t1,t2;
    double t;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        array[i]=i;
    }
    t1=clock();
   radixsort(array, n);
  printArray(array, n);
    t2=clock();
    t=double(t2-t1);
    printf("\n Best time is %g \n\n\n",t);
    
    for(i = 0; i < n; i++)
    {
        array[i]=rand();
    }
    t1=clock();
     radixsort(array, n);
  printArray(array, n);
    t2=clock();
    t=double(t2-t1);
    printf("\n Average time is %g\n\n\n",t);
    
    for(i = n; i >0; i--)
    {
        array[i]=i;
    }
    t1=clock();
     radixsort(array, n);
  printArray(array, n);
    t2=clock();
    t=double(t2-t1);
    printf("\n worst time is %g\n",t);
    

 
}

/*

int max(int a[], int n)
{
    int large = a[0], i;
    for(i = 1; i < n; i++)
    {
        if(large < a[i])
            large = a[i];
    }
    return large;
}


void RadixSort(int a[], int n)
{
    int bucket[100000][100000], bucket_count[10];
    int i, j, k, remainder, NOP=0, divisor=1, large, pass;

    large = max(a, n);
    printf("The large element %d\n\n",large);
    while(large > 0)
    {
        NOP++;
        large/=10;
    }

    for(pass = 0; pass < NOP; pass++)
    {
        for(i = 0; i < 10; i++)
        {
            bucket_count[i] = 0;
        }
        for(i = 0; i < n; i++)
        {
            remainder = (a[i] / divisor) % 10;
            bucket[remainder][bucket_count[remainder]] = a[i];
            bucket_count[remainder] += 1;
        }

        i = 0;
        for(k = 0; k < 10; k++)
        {
            for(j = 0; j < bucket_count[k]; j++)
            {
                a[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;

        for(i = 0; i < n; i++)
            printf("%d  ",a[i]);
        printf("\n");
    }
}

int main()
{
    int i, n, a[100000];
    clock_t t1,t2;
    double t;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        a[i]=i;
    }
    t1=clock();
    RadixSort(a,n);
    t2=clock();
    t=double(t2-t1);
    printf("\n Best time is %g \n\n\n",t);

 for(i = 0; i < n; i++)
    {
        a[i]=rand();
    }
    t1=clock();
    RadixSort(a,n);
    t2=clock();
    t=double(t2-t1);
    printf("\n Average time is %g\n\n\n",t);
    
    for(i = n; i >0; i--)
    {
        a[i]=i;
    }
    t1=clock();
    RadixSort(a,n);
    t2=clock();
    t=double(t2-t1);
    printf("\n worst time is %g\n",t);
    

    return 0;
}*/


