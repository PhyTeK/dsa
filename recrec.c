#include <stdio.h>

int recursive(int c){

  if(c>8)
    return c;
  printf("c=%d\n",c);
  printf("ret1: %d\n",recursive(c+1));
  
  printf("cc=%d\n",c);
  printf("ret2: %d\n",recursive(c+2));
  
  return c;
}

int main(){

  int count=0;
  printf("return value: %d\n",recursive(count));
  
  return 0;
}
