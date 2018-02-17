/* Exercise 1-14
 * Write a program to print a histogram of the frequencies of different
 * characters in its input.
 */

#include <stdio.h>

int count[0xff];

main()
{
    char c;

    while((c = getchar()) != EOF)
        count[c]++;

    for (int i = 0; i < 0xff; i++)
    {
        printf("[0x%02x]: ", i);
        for (int j = 0; j < count[i]; ++j)
            putchar('*');
        putchar('\n');
    }
}
