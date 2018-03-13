#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define SIZE 1000

typedef struct {

    int top;
    int ar[SIZE];
    char op[SIZE];

}stack;

void initializestack(stack * s);
int pop(stack *s);
void push (stack*s, int val);
int isEmty(stack *s);
int top (stack *s);
int eval(char c[] );
void convert(char in[], char post[]);
char popc(stack *s);
void pushc (stack*s, char val);
char topc (stack *s);
int priority(char x);










#endif // STACK_H_INCLUDED
