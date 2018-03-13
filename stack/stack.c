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
char topc() (stack *s)
{
    if (!isEmty(s))
        return s->op[s->top];
    else
    {
        printf("\nUnderflow\n");
        exit(1);
    }
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
void convert(char in[], char post[])
{
    stack s;
    int i;
    initializestack(&s);
    int prec(char ch)
    {
        if (ch =='+')
            return 1;
        else if ( ch == '-')
            return 1;
        else if (ch == '/')
            return 2;
        else if (ch == '*')
            return 2;
            else return 0;
        }
    for(i = 0; in[i] != '\0'; ++i)
    {
               switch(in[i])
       {


            case '1':
                strcat(post,'1');
                break;
            case '2':
                strcat(post,'2');
                break;
            case '3':
                strcat(post,'3');
                break;
            case '4':
                strcat(post,'4');
                break;
            case '5':
                strcat(post,'5');
                break;
            case '6':
                strcat(post,'6');
                break;
            case '7':
                strcat(post,'7');
                break;
            case '8':
                strcat(post,'8');
                break;
            case '9':
                strcat(post,'9');
                break;
            case '+':
                while(!isEmty(&s))
                {
                    strcat(post,popc(&s));
                }
                pushc(&s,'+');
                break;

            case '-':
                while(!isEmty(&s))
                {
                    strcat(post,popc(&s));
                }
                pushc(&s,'+');
                break;
            case '/':
                if(prec(top(&s)) > 1)
                    strcat(post,pop(&s));
                pushc(&s,'/');
                break;
            case '*':
                if(prec(top(&s)) > 1)
                    strcat(post,pop(&s));
                pushc(&s,'*');
                break;
            default :

                break;
       }

        while(!isEmty(&s))
        {
            strcat(post,popc(&s));
        }

    }
}
