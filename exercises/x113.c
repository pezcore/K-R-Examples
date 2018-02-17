/* Exercise 1-13
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging.
 */

#include <stdio.h>

int wordlengths[0xff];

main(){
    char c, size = 0, state = 0; 

    while ((c = getchar()) != EOF) {
        if (!(c == '\t' || c == 0x20 || c == '\n')) {
            size++;
            if (!state) state = 1;
        }
        else if (state){
            wordlengths[size]++;
            size = 0;
        }
    }

    for (int i = 1; i < 256; i++){
        printf("%d:\t", i);
        for (int j = 0; j < wordlengths[i]; j++)
            putchar('*');
        putchar('\n');
    }
}
