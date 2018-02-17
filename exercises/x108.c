#include <stdio.h>

/* Write a program to count blanks tabs and newlines */
main(){
    char c;
    int nblank, ntab, nline;
    nblank = ntab = nline = 0;
    
    while ((c = getchar()) != EOF){
        if (c == '\n')
            nline++;
        if (c == '\t')
            ntab++;
        if (c == 0x20)
            nblank++;
    }
    printf("Blanks:\t%d\nTabs:\t%d\nLines:\t%d\n", nblank, ntab, nline);
}
