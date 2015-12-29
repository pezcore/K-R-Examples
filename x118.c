/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines. */            

#include <stdio.h>
#define MAXLINE 10000

int stripline(unsigned char s[], int lim);

main(){
    char s[MAXLINE];
    int i, len;

    while((len = stripline(s, MAXLINE)) > 0)
        printf("%d:\t%s", len, s);
}

/* getline:  read a line into s, return length  */
/* s includes the \0 but len only give number of chars inculding the \n but not
 * the \0 */
int getline(char s[],int lim) {
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

int stripline(unsigned char buf[], int lim){
    /* read a whole line into the buffer */
    int i = getline(buf, lim) -2 ;

    if (i > 0)
        while((i > 1) && (buf[i] == 0x20 || buf[i] == '\t' ))
            i--;

    buf[++i] = '\n';
    buf[++i] = 0;

    return i ;
}
