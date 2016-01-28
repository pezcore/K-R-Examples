/* Exercise 1-20. Write a program detab that replaces tabs in the input with
 * the proper number of blanks to space to the next tab stop. Assume a fixed
 * set of tab stops, say every n columns. Should n be a variable or a symbolic
 * parameter? */
#include<stdio.h>
#define n 4

main(){
    int c,i = 0;

    while ((c=getchar())!=EOF){
        if (c == '\t')
            while((!i) || (i%n)){
                putchar(0x20); i++;
            }
        else putchar(c);
		i++;
        if (c == '\n') i=0;
    }
}

			/* This line starts with 3 tabs */
