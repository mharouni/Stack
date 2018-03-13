#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack.c"
int main()
{
    printf("Hello world!\n");
    int x=9;
    char c[10]="3+(2-3)";
    char s[10];
    convert(c,s);
    printf("%s",s);


    return 0;
}
