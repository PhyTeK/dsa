#include <stdio.h>

int linearsearch(int *a,int n,int key){
  int i;
  for(i=0;i<n;i++)
    if(a[i] == key)
      return i;
  
  return -1;
}

int linearecursive(int *a,int size,int key){
  if(size == 0) return -1;
  else if (a[size-1] == key) return size-1;
  else return linearecursive(a,size-1,key);
}

/*
  ((((size -1) -1 ) -1 ) -1)
 */

/* Uppgift: Write a linear search to find all keys in an array.
 */
void linearall(int *a,int size,int key,int *r,int *c){
  int i,j=0,flag=0;
  for(i=0;i<size;i++)
    if(a[i] == key){
      r[j++]=i;
      *c = *c + 1 ;
    }
}
// Time complexity is linear O(4N) = O(N)
// Space complexity ??
int main(){
  int a[]={2,4,2,7,4,5,6,3,4,5,0,9};
  int n = sizeof(a)/sizeof(a[0]);
  int found[n],nbc=0;
  int res;
  int i,k=4;
  for(i=0;i<n;i++)
    found[i]=0;
  
  printf("Number of elements in array: %d\n",n);
  printf("%d\n",linearsearch(a,n,k));
  printf("%d\n",linearecursive(a,n,k));

  linearall(a,n,k,found,&nbc);

  if(nbc == 0)
    printf("Key %d not found\n",k);
  else{
    printf("Found %d key(s) %d at indexes:",nbc,k);
    for(i=0;i<nbc;i++)
      printf("%d ",found[i]);
  }
  puts("");
}
