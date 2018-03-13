#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack.c"
int main()
{
    printf("Hello world!\n");
    int x;
    char c[]="(5+4)-(4/2)";
    char s[strlen(c)];
    convert(c,s);
    int i=0;
    for(i=0;i<strlen(s);i++)
        printf("%c",s[i]);

        x=eval(s);
        printf("\n\n");
        printf("%d",x);



    return 0;
}
