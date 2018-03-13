#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>




void initializestack(stack * s)
{

    s->top= -1;

}
int isEmty(stack *s)
{
    if (s->top > -1)
        return 0;
    else
        return 1;
}void pushc(stack *s, char val)
{
    if (s->top == 1000)
    {
        printf("Overflow");
        exit(1);
    }
    else
    {
        s->top = s->top+1;
        s->op[s->top] = val;
    }

}
void push(stack *s, int val)
{
    if (s->top == 1000)
    {
        printf("Overflow");
        exit(1);
    }
    else
    {
        s->top = s->top+1;
        s->ar[s->top] = val;
    }

}
int pop(stack *s)
{
    int x;
    if (!(isEmty(s)))
    {
        x = s->ar[s->top];
        s->top =s->top- 1;
        return x;
    }
    else
    {
        printf("\nUnderflow\n");
        exit(1);
    }
}
char popc(stack *s)
{
    char x;
    if (!(isEmty(s)))
    {
        x = s->op[s->top];
        s->top =s->top- 1;
        return x;
    }
    else
    {
        printf("\nUnderflow\n");
        exit(1);
    }
}
int top (stack *s)
{
    if (!isEmty(s))
        return s->ar[s->top];
    else
    {
        printf("\nUnderflow\n");
        exit(1);
    }
}
char topc (stack *s)
{
    if (!isEmty(s))
        return s->op[s->top];

}
int eval(char c[] )
{
    int i;
    stack s;
    initializestack(&s);
    int sum=0;
    int x,y;
    for(i = 0; c[i] != '\0'; ++i)
            {

       switch(c[i])
       {
            case '0':
                push(&s,0);
                break;
            case '1':
                push(&s,1);
                break;
            case '2':
                push(&s,2);
                break;
            case '3':
                push(&s,3);
                break;
            case '4':
                push(&s,4);
                break;
            case '5':
                push(&s,5);
                break;
            case '6':
                push(&s,6);
                break;
            case '7':
                push(&s,7);
                break;
            case '8':
                push(&s,8);
                break;
            case '9':
                push(&s,9);
                break;
            case '+':
                x=pop(&s);
                y=pop(&s);
                sum= y+x;
                push(&s,sum);
                sum=0;
                break;

            case '-':
                x=pop(&s);
                y=pop(&s);
                sum= y-x;
                push(&s,sum);
                sum=0;
                break;
            case '/':
                x=pop(&s);
                y=pop(&s);
                sum= y/x;
                push(&s,sum);
                sum=0;
                break;
            case '*':
                x=pop(&s);
                y=pop(&s);
                sum= y*x;
                push(&s,sum);
                sum=0;
                break;
            default :
                break;
       }
    }
    return pop(&s);
}
int priority(char x)
{

    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
        else return 0;
}
void convert(char in[], char post[])
{
    stack stack;
    initializestack(&stack);
    int i,j=0 ;
    for (i=0;i<strlen(in);i++)
    {
        if (isalnum(in[i]))
        {

            post[j]=in[i];
            j++;
        }
        else if (in[i]== '+' || in[i] == '-' || in[i] == '*' || in[i] == '/')
        {



            while (priority(topc(&stack)) >= priority(in[i]))
            {
                post[j]=popc(&stack);
                j++;
            }

            pushc(&stack, in[i]);
        }


        else if (in[i]== '(')
        {
             pushc(&stack,'(');
        }

             else if (in[i] == ')')

             {

             while (!isEmty(&stack) && topc(&stack) != '(' )
             {

                 post[j]= popc(&stack);
                 j++;
             }
             char m;
                m=popc(&stack);
             }

    }
    while(!isEmty(&stack))
    {
        char y;
        y=popc(&stack);
        post[j]=y;
        j++;
    }
    post[j]='\0';
}

