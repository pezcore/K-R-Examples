#include <stdio.h>

main(){
    char c,d;
    while((c = getchar()) != EOF){
        while (c == 0x20)
            c = getchar();
        putchar(c);
    }
}
