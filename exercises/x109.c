/* Exercise 1-9
 * Write a program to copy its input to its output, replacing each sring of one
 * or more blanks by a single a single blank.
 */

#include <stdio.h>

main(){
    char c;

    while((c = getchar()) != EOF){
        putchar(c);
        if (c == 0x20){
            while ((c=getchar()) == 0x20);
            putchar(c);
        }
    }
}
