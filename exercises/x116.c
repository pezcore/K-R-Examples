/* K&R2: 1.9, Character Arrays, exercise 1.16

STATEMENT:

revise the main routine of the longest-line programme so it will correctly
print the length of the arbitrarily long input lines including as much of th
possible text.

Note: I assert this is not possible. "revise the main routine" is taken to mean
changes must be made **only** to the implementation of the function main. Since
getline's implementation only reads chars into an array upto a finite size, it
cannot be used, unmodified, to read lines of "arbitrarily long" length.
*/

#include <stdio.h>
#include <limits.h>
#define MAXLINE 1000   /* maximum input line length */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
main()
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getline(line, INT_MAX)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)  /* there was a line */
        printf("%d:\t%s", max, longest);
    return 0;
}

/* getline:  read a line into s, return length  */
int getline(char s[],int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
