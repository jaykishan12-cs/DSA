#include<stdio.h>
#include<string.h>

#define SS 100

//for getting which char it is
#define LEFTPAREN (-1)
#define RIGHTPAREN (-2)
#define OPERATOR (-3)
#define OPERAND (-4)

// for getting the precision of the operator
#define ADDPREC 1
#define SUBPREC 1
#define DIVPREC 2
#define MULPREC 2
#define POWPREC 3
#define MODEPREC 3
#define LEFTPARANPREC 0
#define NONE 99

typedef struct {
    char items[SS];
    int top;
}Stack;

int isEmpty(Stack s){ return s.top == -1;}
int isFull(Stack s){ return s.top == SS-1;}

void push(Stack *ps,char symbol)
{
    if(isFull(*ps))
    {
        printf("Stack Overflow!!");
        return;
    }


    ps->items[++ps->top] = symbol;
}

char pop(Stack *ps){
    if(isEmpty(*ps))
    {
        printf("Stack underflow");
        return '\0';
    }

    return ps->items[ps->top--];
}

char peek(Stack s)
{
    if(isEmpty(s)) return '\0';
    return s.items[s.top];
}

//functioj to get the type of character liek ( + - % *)
int getType(char symbol)
{
    switch (symbol)
    {
        case '(':
            return LEFTPAREN;
            break;
        case ')':
            return RIGHTPAREN;
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            return OPERATOR;
        
        default : return OPERAND;
    }
}

int getPrec(char op)
{
    switch(op)
    {
        case '+': return ADDPREC;
        case '-': return SUBPREC;
        case '/': return DIVPREC;
        case '*': return MULPREC;
        case '^': return POWPREC;
        case '%': return MODEPREC;
        case '(': return LEFTPARANPREC;
        default : return NONE;
    }
}

void infinixToPostfix(char infinix[],char postfix[])
{
    Stack stack;
    stack.top = -1;

    int len = strlen(infinix);
    char currSymbol,stackTop;

    int type,i,p,prec;
    i=0;
    p=0;

    while(i < len)
    {
        currSymbol = infinix[i];
        type = getType(currSymbol);

        switch(type)
        {
            case OPERAND :
                postfix[p++] = currSymbol;
                break;

            case LEFTPARANPREC:
                push(&stack,'(');
                break;

            case RIGHTPAREN:
                while((stackTop = pop(&stack)) != '(')
                    postfix[p++] = stackTop;
                break;

            case OPERATOR:
                prec = getPrec(currSymbol);

                while(!isEmpty(stack) && prec <= getPrec(peek(stack)))
                    postfix[p++] = pop(&stack);
                
                push(&stack,currSymbol);
                break;
        }

        i++;
    }
    
    while(!isEmpty(stack))
        postfix[p++] = pop(&stack);

    postfix[p] = '\0';


}

int main()
{
    char infinix[SS],postfix[SS];
    
    printf("Enter Infinix Expression : ");
    gets(infinix);
    infinixToPostfix(infinix,postfix);

    printf("\n INFINIX : %s",infinix);
    printf("\n POSTFIX : %s",postfix);

    return 0;
}