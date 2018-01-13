
// #include <stdio.h>
//
// /*  The macro continuation operator (\) is used to continue a macro that is too long for a single line */
// #define  message_for(a, b)  \
//    printf(#a " and " #b ": We love you!\n")
// /* The Stringize (#) Operator */
//
// int main(void) {
//    message_for(Carole, Debra7);
//    return 0;
// }
// /*
// When the above code is compiled and executed, it produces the following result −
//
// Carole and Debra7: We love you!
// */












// /* The Token Pasting (##) Operator */
//
// #include <stdio.h>
//
// #define TokenPaster(u) printf ("ToKeN" #u " = %d\n", token##u); //This example shows the concatenation of token##n into token34
//
// int main(void) {
//    int token78 = 40;
//    TokenPaster(78);
//    return 0;
// }
// /*
// When the above code is compiled and executed, it produces the following result −
//
//  token34 = 40
//
//
// It happened so because this example results in the following actual output from the preprocessor −
//
//  printf ("token34 = %d", token34);
//
// */













// /* The Defined() Operator */
//
// #include <stdio.h>
//
// //#define MESSAGE "YEAHHH!"
//
// #if !defined (MESSAGE)
//    #define MESSAGE "You wish!"
// #endif
//
// int main(void) {
//    printf(" Here is the message:  %s\n", MESSAGE);
//    return 0;
// }
/*
// When the above code is compiled and executed, it produces the following result −
//
// Here is the message: You wish!
//
// */

















//
