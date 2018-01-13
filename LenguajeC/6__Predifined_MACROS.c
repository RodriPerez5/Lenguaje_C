

#include <stdio.h>

main() {

   printf("\n File :%s\n", __FILE__ );
   printf(" Date :%s\n", __DATE__ );  
   printf(" Time :%s\n", __TIME__ );
   printf(" Line :%d\n", __LINE__ );
   printf(" ANSI :%d\n\n", __STDC__ );
//
}

/*
When the above code in a file test.c is compiled and executed, it produces the following result −

File :6__PREPROCESSORS.c
Date :Oct  8 2017
Time :00:38:08
Line :8
ANSI :1
*/
