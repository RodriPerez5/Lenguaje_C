

#include <stdio.h>

int main() {

   int sum = 17, count = 5;

   double mean = (double) sum / count;//ES LO MISMO QUE PONER: =((double) sum) / count;   //PER NO ES LO MISMO QUE PONER: =(double) (sum / count);
   printf("Value of mean : %f\n", mean );
}






// ///////////////////////////////////INTEGER PROMOTION////////////////////////////
// #include <stdio.h>
//
// int main() {
//    int  i = 7;
//    char c = 'c'; /* ascii value is 99 */
//
//    int sum = i + c;
//    printf(" Value of sum: %d\n", sum );
// }
// /*
// When the above code is compiled and executed, it produces the following result −
//
//  Value of sum: 106
//
// Here, the value of sum is 116 because the compiler is doing integer promotion and converting the..
// ..value of 'c' to ASCII before performing the actual addition operation.
// */









// ////////////////////////////USUAL ARITHMETIC CONVERSION/////////////////////////
// #include <stdio.h>
//
// int main() {
//    int  i = 7;
//    char c = 'c'; /* ascii value is 99 */
//
//    float sum = i + c;
//    printf(" Value of sum: %f\n", sum );
// }
// /*
// When the above code is compiled and executed, it produces the following result −
//
// Value of sum : 106.000000
//
// Here, it is simple to understand that first c gets converted to integer (integer promotion), but..
// ..as the final value is double, usual arithmetic conversion applies and the compiler converts i and..
// ..c into 'float' and adds them yielding a 'float' result.
// */















//
