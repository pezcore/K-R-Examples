#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

main(){
    char c, state = 0;
    while ((c = getchar()) != EOF) {
        if ((c == '\t' || c == 0x20) && state) {
            while((c = getchar()) == '\t' || c == 0x20);
            putchar('\n');
            putchar(c);
        }
        else {
            state = 1;
            putchar(c);
        }
    }
}
