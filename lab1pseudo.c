/* 
   DSA Laboration 1
   ----------------

   fun1(int N)
     loop N times
       O(1) operation (t.ex j=1)

   fun2(int N)
     loop N times
        loop N times

   fun3(int N)
     k=0
     loop from N/2 to N by 1
        loop from 2 to N by 2 times increment
          j=2*j
	  print k
          k += N/2
        
    fun4(int N)
      Other test

   main:
    Set N a Big number
    clock_t t;

    loop for n=1 to N  
        t=clock()
        fun1(n)
        print clock() - t 

*/
