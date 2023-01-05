#include <stdio.h>

#define MAX 5

static int count=0; // Number of elements in stack

int push(int *stack,int data){  
  if(count < MAX){
    stack[count++]=data;
    return 0;
  }else{
    printf("Stack full\n");
    return -1;
  }
}
int top(int *stack){
  return count;
}

int pop(int *stack){
  int data;
  if(count==0){
    printf("Stack empty\n");
    return -1;
  }
  data=stack[--count];
  return data;
}
 
int main(){
  int stack[MAX];

  push(stack,23);
  push(stack,13);
  push(stack,24);
  push(stack,3);
  push(stack,6);

  // Full stack
  push(stack,7);
  
  printf("%d\n",pop(stack));
  printf("%d\n",pop(stack));
  printf("%d\n",pop(stack));
  printf("%d\n",pop(stack));
  printf("%d\n",pop(stack));
  // Empty Stack
  printf("%d\n",pop(stack));
  
  return 0;
  }
