/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines. */

#include <stdio.h>

int stripline(char s[], int lim);

main(){
    int len;
    while((len = stripline) > 0 );
}

int stripline(char s[], int lim){
    char c,i,j = 0;
    
    while((c=getchar()) != EOF && c != '\n')
        if (c != '\t' && c != 0x20)
            j++;
