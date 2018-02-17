/* Write a function reverse(s) that reverses the character string s. Use it to
 * write a program that reverses its input a line at a time.*/
#include <stdio.h>
#define MAXLINE 10000

void reverse(char s[]){
    int i = 0;
    char c;

    /* find the end of the line */
    while (s[i] != 0) ++i;
    i--;
    if (s[i] == '\n') i--;

    int j = 0;
    while (j < i) {
        c = s[j];
        s[j] = s[i];
        s[i] = c;
        --i;
        ++j;
    }
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

int main(){
    int len;
    char s[MAXLINE];

	while((len = getline(s, MAXLINE)) > 0){
        reverse(s);
        printf("%s",s);
    }

    return 0;
}
