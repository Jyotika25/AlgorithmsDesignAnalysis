////Quick Sort


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void quicksort(int number[],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main(){
   int i, count, number[35000];
    double t2,t1,t;
   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);
    //best
   for(i=0;i<count;++i)
     number[i]=i;
     t1=clock();
    quicksort(number,0,count-1);
    printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);
    t2=clock();
    t=(double)(t2-t1);
    printf("\nbest TIME:%g\n",t);
   //average
   for(i=0;i<count;++i)
     number[i]=rand();
     t1=clock();
    quicksort(number,0,count-1);
    printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);
    t2=clock();
    t=(double)(t2-t1);
    printf("\n average TIME:%g\n",t);
 //worst
   for(i=count;i>0;--i)
     number[i]=i;
     t1=clock();
    quicksort(number,0,count-1);
    printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);
    t2=clock();
    t=(double)(t2-t1);
    printf("\n worst TIME:%g\n",t);

   return 0;
}

