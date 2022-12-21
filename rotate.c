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

/*
  Pseudocode for the reverse function

  Swap a[n-1] with a[0]
  Swap a[n-2] with a[1]
  Swap a[n-3] with a[2] 
  ...
  Return when start = end
  with start=0,1,2 ...
  and  end=n,n-1,n-2, ...

  Define 2 indexes 
    start=0
    end = n-1
    loop as long as start<end
       swap start with end
       start++
       end--
 */


void reverse(int *a,int n){
  int start=0,end=n-1;
  
  while(start<end){
    swap(&a[start],&a[end]);
    start++;
    end--;
  }
}

void rotate(int *a, int n){
  /* 
     Start thinking with an example
     
     2,3,6,4,2,9

     tmp=a[0]

     Loop start here
     a[0]=a[1]
     a[1]=a[2]
     ...
     a[n-2]=a[n-1]
     Loop ends here

     a[n-1]=tmp

     Pseudo code
     -----------
     Save the first element
     Loop from 0 to n-2
          Set element to the next one
     Set last element to the saved first element
  */

  int i,tmp;

  tmp=a[0];
  for(i=0;i<n-1;i++){
    a[i]=a[i+1];
  }
  a[n-1]=tmp;
}

int main(){

  int arr[]={2,4,2,7,9,3,6,1};  // takes 8 times 8 bytes = 64 bytes

  //int arr[6]={'H','e','l','l','o','\0'};

  //  float arr[]={1.23,2.34,3.45,4.56};
  
  int n = sizeof(arr)/sizeof(arr[0]);
  
  printArray(arr,n);
  //  swap(&arr[1],&arr[3]);  // Swap 4 with 6
  //printArray(arr,n);
  reverse(arr,n);
  printArray(arr,n);
  rotate(arr,n);
  printArray(arr,n);
  
  return 0;
}
