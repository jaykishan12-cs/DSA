#include<stdio.h>
#include<math.h>
#include<string.h>
#define SS 100


// #define OPERATOR (-1)
#define OPERAND (-2)

#define ADDO 1
#define SUBO 2
#define DIVPO 3
#define MULO 4
#define POWO 5
#define MODEO 6

typedef struct {
    int items[SS];
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

int getType(char symbol)
{
    switch (symbol)
    {
        case '+':return ADDO;
        case '-':return SUBO;
        case '*':return MULO;
        case '/':return DIVPO;
        case '%':return MODEO;
        case '^':return POWO;
            
        default : return OPERAND;
    }
}

int calculate(char postfix[], Stack *s) {
    int i = 0;
    int len = strlen(postfix);
    char currentSymbol;
    int type, num,num1, num2, result;

    while (i<len) {
        currentSymbol = postfix[i];
        type = getType(currentSymbol);

        if (type == OPERAND) {
            num = currentSymbol - '0';
            push(s, num);
        } else {
            num1 = pop(s);
            num2 = pop(s);

            switch (type) {
                case ADDO:
                    result = num2 + num1;
                    break;
                case SUBO:
                    result = num2 - num1;
                    break;
                case MULO:
                    result = num2 * num1;
                    break;
                case DIVPO:
                    result = num2 / num1;
                    break;
                case POWO:
                    result = (int)pow(num2, num1);
                    break;
                case MODEO:
                    result = num2 % num1;
                    break;
                default:
                    result = 0;
            }
            push(s, result);
        }
        i++;
    }
    return pop(s);
}

int main()
{
    Stack s;
    s.top = -1;
    int res;

    char postfix[100];
    printf("Enter postfix expression : ");
    scanf("%s", postfix);

    res = calculate(postfix,&s);

    printf("Result : %d\n",res);
    printf("top = %d",s.top);
}
