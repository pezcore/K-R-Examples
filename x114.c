#include <stdio.h>

/* Write a program to print a histogram of the frequencies of different
 * characters in its input. */

int count[0xff];

main(){
    char c;

    while((c = getchar()) != EOF)
        count[c]++;

    for (int i = 0; i < 0xff; i++){
        printf("[0x%2x]:\t", i);
        for (int j = 0; j < count[i]; ++j)
            putchar('*');
        putchar('\n');
    }
}
