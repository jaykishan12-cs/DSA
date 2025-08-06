#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SS 10
#define STACK_OVERFLOW 0
#define STACK_UNDERFLOW -32768
#define PUSH_SUCCESS 2
#define INVALID_NUMBER 1

#define LEFTPARANTHESIS 1
#define RIGHTPARANTHESIS 1

#define LEFTCURLYBRACKET 2
#define RIGHTCURLYBRACKET 2

#define LEFTSQUAREBRACKET 3
#define RIGHTSQUAREBRACKET 3

#define INAVLID_BRACKET 0

#define OPENING 4
#define CLOSING 5

typedef struct Stack
{
    int top;
    char nums[SS];
} Stack;

int isEmpty(Stack s)
{
    if (s.top == -1)
        return 1;

    return 0;
}

int isFull(Stack s)
{
    if (s.top == SS - 1)
        return 1;

    return 0;
}

int push(Stack *ps, int x)
{
    if (isFull(*ps))
    {
        return STACK_OVERFLOW;
    }

    ps->top++;
    ps->nums[ps->top] = x;

    return PUSH_SUCCESS;
}
int pop(Stack *ps)
{
    int temp;
    if (isEmpty(*ps))
        return STACK_UNDERFLOW;

    return ps->nums[ps->top--];
}

int peek(Stack s)
{
    if (isEmpty(s))
        return STACK_UNDERFLOW;

    return s.nums[s.top];
}
void display(Stack s)
{
    int i;
    for (i = s.top; i >= 0; i--)
    {
        printf("%d ", s.nums[i]);
    }
    printf("\n");
}

int getType(char symbol)
{
    switch (symbol)
    {
    case ')':
        return RIGHTPARANTHESIS;

    case '(':
        return LEFTPARANTHESIS;

    case '}':
        return RIGHTCURLYBRACKET;

    case '{':
        return LEFTCURLYBRACKET;

    case '[':
        return LEFTSQUAREBRACKET;

    case ']':
        return RIGHTSQUAREBRACKET;
    default:
        return INAVLID_BRACKET;
    }
}

int getOpeningOrCLosing(char symbol)
{
    switch (symbol)
    {
    case '(':
    case '{':
    case '[':
        return OPENING;

    default:
        return CLOSING;
    }
}

bool check(Stack *ps, char str[])
{
    int i = 0;
    int len = strlen(str);
    for (i = 0; i < len; i++)
    {
        char currentSymbol = str[i];
        int type = getType(currentSymbol);
        int oc = getOpeningOrCLosing(currentSymbol);
        if (oc == OPENING)
        {
            push(ps, currentSymbol);
        }
        else
        {
            if (isEmpty(*ps))
            {
                return false;
            }

            int top = peek(*ps);
            int topType = getType(top);
            if (topType == LEFTPARANTHESIS && type == RIGHTPARANTHESIS || topType == LEFTCURLYBRACKET && type == RIGHTCURLYBRACKET || topType == LEFTSQUAREBRACKET && type == RIGHTSQUAREBRACKET)
            {
                pop(ps);
            }
            else{
                return false;
            }
        }
    }

    if(isEmpty(*ps))
        return true;
    return false;
}
int main()
{
    Stack s;
    s.top = -1;

    char string[100];
    printf("Enter string: ");
    gets(string);
 
    
    if(check(&s,string))
        printf("\n VALID PARNATEHSIS");
    else
        printf("\n INVALID PARAENTESIS");
    
}