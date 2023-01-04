#include <stdio.h>
#include <stdlib.h>

void print(int *list,int n){
  for(int i=0;i<n;i++)
    printf("%d ",list[i]);
  puts("");
}
  
void swap(int *a,int*b){
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}

#define N 10000


void bubble(int *list,int n){
  int i,flag=0,count=0;

  while(flag != 1){
    flag=1;
    for(i=0;i<n-1;i++){
      if(list[i+1]<list[i]){
	swap(&list[i+1],&list[i]);
	flag=0;
	count++;
      }
    }
  }
  
  printf("%d\n",count);

}
int main(){
  int c;
  int alist[]={3,2,4,7,5,1,6,8};
  int blist[N];
  int i,n=sizeof(alist)/sizeof(alist[0]);
  print(alist,n);

  while((c=getchar()) != '.'){
      for(i=0;i<n-1;i++){
	if(alist[i+1]<alist[i])
	  swap(&alist[i+1],&alist[i]);
      }
      print(alist,n);
    }


  for(i=0;i<N;i++)
    blist[i]=rand()%100+1;

  //print(blist,N);
  bubble(blist,N);
  //#print(blist,N);

  
  return 0;
}
