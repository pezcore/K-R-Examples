/* Exercise 1-13
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging.
 */

#include <stdio.h>


main()
{
    int wordlengths[0xff], i; /* array to store word lengths */
    /* initialize the wordlengths array to all zero */
    for (i = 0; i < 0xff; ++i)
        wordlengths[i] = 0;

    char c, size = 0, state = 0; 

    while ((c = getchar()) != EOF)
    {
        if (!(c == '\t' || c == 0x20 || c == '\n'))
        {
            size++;
            if (!state) state = 1;
        }
        else if (state)
        {
            wordlengths[size - 1]++;
            size = 0;
        }
    }

    for (int i = 1; i <= 0xff; i++)
    {
        printf("%3d: ", i);
        for (int j = 0; j < wordlengths[i - 1]; j++)
            putchar('*');
        putchar('\n');
    }
}
