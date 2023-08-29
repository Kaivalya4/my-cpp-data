//a function which can take variable number of argument
//we onlu define first parameter of the function  - func(int fixedparam,...)  - three dots says it is variadic function
//define a va_list variable
//begin and end the argu list with va_strat and va_end  - these are macros
//ex - add(3,1,2,3) = 6 , add(6,20,20,20,10,20,10)=100
 #include<stdio.h>
 #include<stdarg.h>    //we need this library
 int add(int args , ...)
 {
     va_list ap;    // variable_list variable . ap(argument parameter)
     va_start(ap,args);
     //Process
     int i = 0,sum =0 ;
     for(i=0;i<args;i++)
     {
         sum += va_arg(ap, int);    //another macros - the second parameter is the type we want to be processed.
     }
     va_end(ap);
     return sum;
 }
int main()
{
    printf("add = %d",add(3,1,2,3));
    return 0;
}
 /*
 va_arg ,va_start etc . are called macros(like function but not a function) . basically compiler replaces these words with preexisting codes that perform
 operation
 */
