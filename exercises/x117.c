/* Exercise 1-17
 * Write a program to print all input lines that are longer than 80 characters.
 */

#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);
char line[MAXLINE];

main()
{
    int i, len, max;
    
    while((len = getline(line, MAXLINE)) > 0)
        if(len > 80)
            printf("%d:\t%s", len, line);
}

/* getline:  read a line into s, return length  */
int getline(char s[],int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

/* This line is longer than the minimum eighty characters. blah blah blah blah blah blah blah blah */
