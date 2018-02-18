/* Exercise 1-21.
 * Write a program entab that replaces strings of blanks by the minimum number
 * of tabs and blanks to achieve the same spacing. Use the same tab stops as
 * for detab. When either a tab or a single blank would suffice to reach a tab
 * stop, which should be given preference?
 */

#include <stdio.h>

#define TAB 4 // Number of spaces of one tab.

main()
{
    int c, i = 0, j;

    while((c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            ++i; /* This is a counter of white spaces. */
            if((i % TAB) == 0)   /* Every group of a number of 'TAB' */
                putchar('\t');   /* spaces is replaced by a tab. */
        }
        else
        {

        for(j = 0; j < (i % TAB); ++j)  /* Every group smaller than */
            putchar(' ');               /* 'TAB' spaces is untouched. */

        putchar(c); /* Well, there exist other characters but spaces. */
        i = 0;
        }
    }
}
