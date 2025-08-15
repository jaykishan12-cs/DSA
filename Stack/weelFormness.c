#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>
#define EMPTY -400000
#define MAX 10

#define LEFTPARAN 1
#define RIGHTPARAN 2

typedef struct{
    int items[MAX];
    int top;
}Stack;

int isFull(Stack s){return s.top == MAX-1; }
int isEmpty(Stack s){ return s.top == -1;}

void push(Stack *ps, int value) {
    if (isFull(*ps)) {
        printf("Int Stack Overflow!!");
        return;
    }
    ps->items[++ps->top] = value;
}

int pop(Stack *ps) {
    if (isEmpty(*ps)) {
        printf("Int Stack Underflow!!");
        return 0;
    }
    return ps->items[ps->top--];
}

int peek(Stack s) {
    if (isEmpty(s)) return EMPTY;
    return s.items[s.top];
}
int getType(char symbol)
{
    switch(symbol)
    {
        case '(':
            return LEFTPARAN;
            break;

        case ')':
            return RIGHTPARAN;
            break;

    }
}
bool check(char str[])
{
    Stack s;
    s.top = -1;
    char currSymbol;
    int i = 0;
    int len = strlen(str);

    while (i < len)
    {
        currSymbol = str[i];
        int type1 = getType(currSymbol);

        switch (type1)
        {
            case LEFTPARAN:
                push(&s, currSymbol);
                break;

            case RIGHTPARAN:
                if (isEmpty(s))  
                    return false;

                
                    int closing = pop(&s);
                    int type2 = getType(closing);
                    if (type2 != LEFTPARAN)
                        return false;
                
                break;
        }
        i++;
    }

    return isEmpty(s);
}


int main()
{
    char str[100];
    printf("Enter Paranthesis to Check: ");
    gets(str);

    bool res;
    res = check(str);

    if(res)
    {
        printf("\n Valid Paranthesis!!");
    }
    else{
        printf("\n Invalid Paranthesis!!");
    }

    return 0;
}