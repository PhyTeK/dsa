/* 
   Uppgift:
   Given an array arr of N integer,
   Find and display all partitions that has a sum equal to 5.

   arr[] = {1,3,2,1,1,2,4,5}

   T.ex {3,2}
        {1,4}
        {1,1,1,2}
        {5}
        {1,2,2}

   Pseudocode1:

   Sort arr -> {1,1,1,2,2,3,4,5}
   Declare Sum
   Loop from first element to last one
   Set Sum=0
      Add element to Sum
      If Sum < 5 
        Sum with next
      If Sum > 5 
        
      If Sum = 5
        Display partition
   


   Pseudocode 2
   
   Build partitions by increasing length
   
   Loop nbe from 1 to N
     Sum all nbe elements from arr
      If Sum < 5 
        Sum with next
      If Sum > 5 
        No partition
      If Sum = 5
        return partition
   
	
*/
#include <stdio.h>


int binarysearch(int *arr,int x, int low, int high){
  int mid;
  
  while(low<high){
    mid=(low+high)/2;
    if(x==arr[mid])
      return mid;
    else if(x>arr[mid])
      low=mid+1;
    else	
      high=mid-1;
  }
}

int subsum(int *a,int n){
  int sum=0;
  for(int i=0;i<n;i++)
    sum += a[i];
  return sum;
}
  

int main(){
  int arr[] = {1,3,2,1,1,2,4,5,7,6};
  int n=sizeof(arr)/sizeof(arr[0]);
  int i,j=0,k,l;
  int sum=0,N=5;

  int pivot=5;
  int L[n];

  // Collect all values <= pivot
  for (i=0;i<n;i++){
    if (arr[i]<= pivot)
      L[j++] = arr[i];
  }

  // Create all possible partitions from L array
  // {1,3,2,1,1,2,4,5}
  // {5}
  // {3,2} {4,1}
  // {1,1,3} {1,2,2}
  // {1,1,1,2}

  int b[n];
  j=0;
  for(i=0;i<j;i++){
    
    b[j++]=arr[i];
    
    
    
    if (subsum(b,j) == pivot){
      count++;
      printf("count=%d",count);
    }
  }
  
  // Merge values from L[]
    sum=0;
    i=0;
    while (1){

      if(sum<pivot) {
	sum+=arr[i];
	printf("%d ",arr[i]);
      }
      
      i++;
      if(i>n) break;
    }
     
  
 return 0;
}
