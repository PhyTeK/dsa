/*
  Laboration 1

  Swaping two elements inside an array

  INPUT

  arr[]={1,2,3,4}

  OUTPUT

  {1,3,2,4}
  
  Write a function called swap(int i, int j)
  that change place of i with j indexes.


  swap(1,2) = swap(2,1)
  
*/
#include <stdio.h>

void swap(int *a,int * b){
  int tmp;
  
  tmp = *a;  // *a the value which the pointer a points to
  *a = *b;   // The value pointed by a as become the value pointed by b
  *b = tmp;  // Copy "tmp value" of a to the value pointed by 
}

void printArray(int *a,int n){   // a points to a[0], n=size of a
  int i;
  printf("{");
  for(i=0;i<n;i++)
    if(i<n-1)
      printf("%d,", a[i]);  // Or *(a+i)
    else
      printf("%d", a[i]);  // Or *(a+i)
  puts("}");
}


void reverse(int *a,int n){
  int i=0;
  
  while(??){
    swap(??);
    i++;
  }
}

int main(){

  int arr[5]={2,4,3,6,1};

  printArray(arr,5);
  swap(&arr[1],&arr[3]);  // Swap 4 with 6
  printArray(arr,5);
  reverse(arr,5);
  printArray(arr,5);
  
  return 0;
}
