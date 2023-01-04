#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a,int *b){
  int tmp = *a;
  *a=*b;
  *b=tmp;
}

void bubble(int *arr,int n){
  int i=0,j=0;
  
  while(j<n){
    i=0;
    while(i<n){
      if(arr[i+1]<arr[i])
	swap(&arr[i],&arr[i+1]);
      i++;
    }
    j++;
  }   
}
	
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
      int m = l + (int)((r - l) / 2);
 
        // Sort first and second halves
        mergeSort(arr, l, m);
	
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}


void testmergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
      
      int m = l + (int)((r - l) / 2);
      printf("m=%d\n",m);
      // Sort first and second halves
      mergeSort(arr, l, m);
      printf("  m=%d\n",m);
      
      mergeSort(arr, m + 1, r);
      printf("    m=%d\n",m);
    }
}

#define N 10000

int main(){

  int arr[N];
  clock_t t;

  for(int i=0;i<N;i++)
    arr[i]=rand()%100+1;
  
  t=clock();
  mergeSort(arr,0,N);
  t=clock()-t;
  printf("t2=%f\n",((double)t)/CLOCKS_PER_SEC);
  t=clock();
  bubble(arr,N);
  t=clock()-t;
  printf("t1=%f\n",((double)t)/CLOCKS_PER_SEC);
  
  return 0;
}
