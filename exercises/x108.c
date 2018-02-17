/* Exercise 1-8
 * Write a program to count blanks tabs and newlines
 */

#include <stdio.h>

main()
{
    char c;
    int nblank, ntab, nline;
    nblank = ntab = nline = 0;
    
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            nline++;
        if (c == '\t')
            ntab++;
        if (c == ' ')
            nblank++;
    }
    printf("Blanks:\t%d\nTabs:\t%d\nLines:\t%d\n", nblank, ntab, nline);
}
