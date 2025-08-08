#include<stdio.h>
#include<string.h>
#include<math.h>
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

//function to get the type of character like ( + - % *)
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

void infinixToPostfix(char infinix[],char postfix[],Stack *stack)
{
    

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
                postfix[p++] = '<';

                while (i < len && getType(infinix[i]) == OPERAND) {
                    postfix[p++] = infinix[i];
                    i++;
                }

                postfix[p++] = '>';
                i--; 
              
                break;

            case LEFTPARANPREC :
                push(stack,'(');
                break;

            case RIGHTPAREN:
                while((stackTop = pop(stack)) != '(')
                    postfix[p++] = stackTop;
                break;

            case OPERATOR:
                prec = getPrec(currSymbol);

                while(!isEmpty(*stack) && prec <= getPrec(peek(*stack)))
                    postfix[p++] = pop(stack);
                
                push(stack,currSymbol);
                break;
        }

        i++;
    }
    
    while(!isEmpty(*stack))
        postfix[p++] = pop(stack);

    postfix[p] = '\0';


}
int calculate(char postfix[], Stack *s) {
    int i = 0, num1, num2, result;
    char ch;
    
    while (postfix[i] != '\0') {
        ch = postfix[i];

        if (ch == '<') {
            i++;
            int num = 0;
            while (postfix[i] != '>' && postfix[i] != '\0') {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(s, num); // push the complete number
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^') {
            num1 = pop(s);
            num2 = pop(s);

            switch (ch) {
                case '+': result = num2 + num1; break;
                case '-': result = num2 - num1; break;
                case '*': result = num2 * num1; break;
                case '/': result = num2 / num1; break;
                case '%': result = num2 % num1; break;
                case '^': result = pow(num2, num1); break;
            }

            push(s, result);
        }

        i++; // move to next character
    }

    return pop(s);
}

int main()
{
    Stack stack;
    stack.top = -1;
    char infinix[SS],postfix[SS];
    
    printf("Enter Infinix Expression : ");
    gets(infinix);
    infinixToPostfix(infinix,postfix,&stack);

    int res =  calculate(postfix,&stack);

    printf("\n INFINIX : %s",infinix);
    printf("\n POSTFIX : %s",postfix);
    printf("\n evaluation : %d",res);

    return 0;
}