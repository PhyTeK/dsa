/*
  Pseudo code

  From Wikipedia:

  A plain language description of the steps in an algorithm or another
  system. Pseudocode often uses structural conventions of a normal
  programming language, but is intended for human reading rather than
  machine reading.
  


  1) Plain language in english
  2) As a recipes: as lite words as possible
  3) Same logical structure than the final code
  4) No programming details like indexes, variables functions names
  

  Example:

  Create a function named sum that sum two numbers
  (see pseudo code for fun next page)
  Set indexes to 0
  Begin
  Ask auser his/her name
  If name start with a 'A'
     Print the name on the screen
  Else
     Start from Begin
  Loop index from 1 to 100
     Called the function sum on the indexes
  Print the sum in a file
  End

  Uppgift:

  Write a pseudo code which describes the following C-code

  int main(){
    int tmp;
    int a=1,b=2;
    printf("a=%d b=%d\n",a,b);
    tmp=a;
    a=b;
    b=tmp;
    printf("a=%d b=%d\n",a,b);
    return 0;
  }

  A poosible solution:
  Set 
  print the two numbers
  Swap these numbers
  print the two numbers


 Uppgift 2
----------
 void fun(int a, int b){
  int r=1;
  if(a!=0 && b != 0)
     r = a/b;
  if(r>0){
     fun(a,r);
  else
     r=0;
  }
  printf("%f", r);
}
  
Pseudo code
----------- 
Begin a function that takes two numbers
    set variable r to 1
    if both numbers are not zero
    set variable r to the quotient of the two numbers
    if r positive
       call recursively the same function with r as the second argument 
    else set r to zero
    print r on the screen
End the function    

 
