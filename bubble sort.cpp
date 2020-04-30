#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void bubble_sort( int A[ ], int n ) {
    int temp=0,i,k;

    for(k = 0; k< n-1; k++) {
        // (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations
        for(i = 0; i < n-k-1; i++) {
            if(A[ i ] > A[ i+1] ) {
                // here swapping of positions is being done.
                temp=0;
                temp = A[ i ];
                A[ i ] = A[ i+1 ];
                A[ i + 1] = temp;
            }
        }
    }
   
     for(i = 0; i < n; i++)
            printf("%d  ", A[i]);
        printf("\n");
}
int main()
{
    int i,n, arr[100000];
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
    bubble_sort(arr,n);
    t2=clock();
    t=t2-t1;
    printf("\n Best case %g \n",t);
//avg case
    for(i=0;i<n;i++)
    {
        arr[i]=rand();
    }
    t1=clock();
    bubble_sort(arr,n);
    t2=clock();
    t=t2-t1;
    printf("Average Case %g\n",t);
//worst case
    for(i=n;i>0;i--)
    {
        arr[i]=i;
    }
    t1=clock();
    bubble_sort(arr,n);
    t2=clock();
    t=t2-t1;
    printf("Worst Case %g\n",t);
    return 0;
}

