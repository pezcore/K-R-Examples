/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines. */		    
#include <stdio.h>
#define MAXLINE 10000

int stripline(char s[], int lim);

main(){
    char s[MAXLINE];
    int i = 0, len;

    while((len = stripline(s, MAXLINE)) > 0){
		/* this if statement is the part that "deletes entirely blank lines" */
		if (len > 1) printf("%s", s);
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

/* stripline: read a line into s and "end" it by putting a \n\0 after the last
 * non whitespace char */
int stripline(char buf[], int lim){
    /* read a whole line into the buffer */
	int i;
    if ((i = getline(buf, lim) - 1) == -1)
		return 0;
    
    while(buf[i] == 0x20 || buf[i] == '\n' || buf[i] == '\t')
        --i;

    buf[++i] = '\n'; /* put the newline back */      
	buf[++i] = '\0';

    return i ;
}


/* here are some trailing spaces */                          
/* there are two blank lines after this one */


/* here are some trailing tabs and spaces */						

