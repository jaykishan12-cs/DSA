#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SS 100

#define LEFTPAREN (-1)
#define RIGHTPAREN (-2)
#define OPERATOR (-3)
#define OPERAND (-4)

#define ADDPREC 1
#define SUBPREC 1
#define DIVPREC 2
#define MULPREC 2
#define POWPREC 3
#define MODEPREC 3
#define LEFTPARANPREC 0
#define NONE 99



//stack 
typedef struct{
    char items[SS];
    int top;
}Stack;

//to check overflow and underflow
int isEmpty(Stack s){ return s.top == -1;}
int isFull(Stack s){ return s.top == SS-1;}

//stack basic operation
//push to stack
void push(Stack *ps,char symbol)
{
    if(isFull(*ps))
    {
        printf("Stack Overflow!!");
        return;
    }
    ps->items[++ps->top] = symbol;
}

//to remove leement
char pop(Stack *ps){
    if(isEmpty(*ps))
    {
        printf("Stack underflow");
        return '\0';
    }

    return ps->items[ps->top--];
}

//to see the top element
char peek(Stack s)
{
    if(isEmpty(s)) return '\0';
    return s.items[s.top];
}


//to get the type of the charcter
int getTpe(char symbol){
    switch(symbol)
    {
        case '(':
            return LEFTPAREN;

        case ')':
            return RIGHTPAREN;

        case '+':
        case '-':
        case '*':
        case '^':
        case '/':
        case '%':
            return OPERATOR;

        default :
            return OPERAND;
    }
}

//to get the precision of operator
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
        case ')': return LEFTPARANPREC;
        default : return NONE;
    }
}

// to convert the epression to prefix
void infixTOPrefix(char infix[],char prefix[]){

    Stack s;
    s.top = -1;
    int i=0,p=0;
    int type,prec;
    char currentSymbol;

    int len = strlen(infix);
    char currSymbol,stackTop;
    strrev(infix);

    while(i<len)
    {
        currentSymbol = infix[i];
        type= getTpe(currentSymbol);

        switch(type)
        {
            case OPERAND:
                prefix[p++] = currentSymbol;
                break;

            case RIGHTPAREN:
                push(&s,')');
                break;

            case LEFTPAREN:
                while((stackTop = pop(&s))!=')')
                {
                    prefix[p++] = stackTop;

                }
                break;

            case OPERATOR:
                prec = getPrec(currentSymbol);
                while(!isEmpty(s) && prec < getPrec(peek(s)))
                {
                    prefix[p++] = pop(&s);
                }
                push(&s,currentSymbol);
                break;
        }//end of switch
        i++;
    }//end of while

    
    while(!isEmpty(s))
        prefix[p++] = pop(&s);

    prefix[p] = '\0';

    strrev(prefix);
}

int main()
{
    
    char infix[SS],prefix[SS];

    printf("\nEnter Infix Expression : ");
    gets(infix);

    infixTOPrefix(infix,prefix);

    printf("\n INFIX : %s",strrev(infix));
    printf("\n PREFIX : %s",prefix);
}