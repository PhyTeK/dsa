#include <stdio.h>
#include <math.h>

int hashdouble(int key,int M){
  int i=1;
  int result = key%M + i*key%7;

  return result;
}


int hashmult(int key,int M){
  double A=0.61803398;
  return (int)(M*key*A)% M;

}

int hashMidSquare(int key){
  int k2=key*key;
  double kd=(double)k2;
  int nbd=(int)(log10(k2)+1);
  int r=1,result=0;
  int i;

  // 9679*9679=93683041 -> result=8

  for(i=0;i<nbd/2;i++){
    kd /= 10;
    
    result=(int)((kd-(int)(kd))*10*r);
  }

  
  return result;
}

int main(){
  int arr[]={4322, 1334, 1471, 9679, 1989, 6171, 6173, 4199};
  int n = sizeof(arr)/sizeof(arr[0]);
  int i;


  
  for(i=0;i<n;i++){
    printf("h(%d)=%d\n",arr[i],hashdouble(arr[i],20));

  }
  
  return 0;
}
