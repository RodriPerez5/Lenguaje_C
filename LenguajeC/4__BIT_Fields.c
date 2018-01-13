//////////////////////////////////////////VERMEJOR

/*
 The C programming language offers a better way to utilize the memory space:
 In STRUCTURES you can tell C the WIDTH OF VARIABLES (Bit Fields) what allow the packing of data.
 This is especially useful when memory or data storage is at a premium.


        // Bit Field Declaration //

 struct {
    type [member_name] : width;  //width: Number of bits in the bit-field. The width must be less than or equal to the bit width of the specified type.
 };

*/


/*
  If you will use up to 32 variables each one with a width of 1 bit, then also the status structure will use 4 bytes.
However as soon as you have 33 variables, it will allocate the next slot of the memory and it will start using 8 bytes.
Let us check the following example to understand the concept −
*/

// #include <stdio.h>
// #include <string.h>
//
// /* define simple structure */
// struct {
//    unsigned int widthValidated;
//    unsigned int heightValidated;
// } status1;
//
// /* define a structure with bit fields */
// struct {
//    unsigned int widthValidated : 1;
//    unsigned int heightValidated : 1;
// } status2;
//
// int main( ) {
//    printf( "Memory size occupied by status1: %ld bytes\n", sizeof(status1)); //TUVE QUE CAMBIAR %d POR %ld
//    printf( "Memory size occupied by status2: %ld bytes\n", sizeof(status2)); //TUVE QUE CAMBIAR %d POR %ld
//    return 0;
// }

/*
When the above code is compiled and executed, it produces the following result −

 Memory size occupied by status1: 8 bytes
 Memory size occupied by status2: 4 bytes

*/


/**************************************************************************************************************************************************/


/*
for example, if you need a variable to store a value from 0 to 7, then you can define a bit field with a width of 3 bits as follows −
The above structure definition instructs the C compiler that the age variable is going to use only 3 bits to store the value. If you..
..try to use more than 3 bits, then it will not allow you to do so. Let us try the following example −
*/
#include <stdio.h>
#include <string.h>

struct {
   unsigned int age : 3;
} Age;

int main( ) {

   Age.age = 2;
   printf( "Sizeof( Age ): %ld bytes\n", sizeof(Age) ); //TUVE QUE CAMBIAR %d POR %ld
   printf( "Age.age: %d\n", Age.age );

   Age.age = 7;
   printf( "Age.age: %d\n", Age.age );

   Age.age = 8;//(Alerta amarilla dejada a porpósito)
   printf( "Age.age: %d\n", Age.age );//NO NOS IMPRIME EL 8 PORQUE SE SALIÓ DEL RANGO DEL WIDTH DE BITS ASIGNADO

   return 0;
}


/*
When the above code is compiled it will compile with a warning and when executed, it produces the following result −

Sizeof( Age ): 4
Age.age: 2
Age.age: 7
Age.age: 0

*/










//
