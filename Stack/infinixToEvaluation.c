#include<stdio.h>
#include<string.h>
#include<math.h>

#define SS 100

// Type classification
#define LEFTPAREN (-1)
#define RIGHTPAREN (-2)
#define OPERATOR (-3)
#define OPERAND (-4)

// Evaluation codes
#define ADDO 1
#define SUBO 2
#define DIVPO 3
#define MULO 4
#define POWO 5
#define MODEO 6

// Operator precedence
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
} CharStack;

typedef struct {
    int items[SS];
    int top;
} IntStack;

int isEmptyChar(CharStack s) { return s.top == -1; }
int isFullChar(CharStack s) { return s.top == SS - 1; }

void pushChar(CharStack *ps, char symbol) {
    if (isFullChar(*ps)) {
        printf("Char Stack Overflow!!");
        return;
    }
    ps->items[++ps->top] = symbol;
}

char popChar(CharStack *ps) {
    if (isEmptyChar(*ps)) {
        printf("Char Stack Underflow!!");
        return '\0';
    }
    return ps->items[ps->top--];
}

char peekChar(CharStack s) {
    if (isEmptyChar(s)) return '\0';
    return s.items[s.top];
}

int isEmptyInt(IntStack s) { return s.top == -1; }
int isFullInt(IntStack s) { return s.top == SS - 1; }

void pushInt(IntStack *ps, int value) {
    if (isFullInt(*ps)) {
        printf("Int Stack Overflow!!");
        return;
    }
    ps->items[++ps->top] = value;
}

int popInt(IntStack *ps) {
    if (isEmptyInt(*ps)) {
        printf("Int Stack Underflow!!");
        return 0;
    }
    return ps->items[ps->top--];
}

int getType(char symbol) {
    switch (symbol) {
        case '(': return LEFTPAREN;
        case ')': return RIGHTPAREN;
        case '+': case '-': case '*': case '/': case '%': case '^': return OPERATOR;
        default: return OPERAND;
    }
}

int getType2(char symbol) {
    switch (symbol) {
        case '+': return ADDO;
        case '-': return SUBO;
        case '*': return MULO;
        case '/': return DIVPO;
        case '%': return MODEO;
        case '^': return POWO;
        default: return OPERAND;
    }
}

int getPrec(char op) {
    switch (op) {
        case '+': return ADDPREC;
        case '-': return SUBPREC;
        case '/': return DIVPREC;
        case '*': return MULPREC;
        case '^': return POWPREC;
        case '%': return MODEPREC;
        case '(': return LEFTPARANPREC;
        default: return NONE;
    }
}

void infinixToPostfix(char infinix[], char postfix[], CharStack *stack) {
    int len = strlen(infinix);
    char currSymbol, stackTop;
    int type, i = 0, p = 0;

    while (i < len) {
        currSymbol = infinix[i];
        type = getType(currSymbol);

        switch (type) {
            case OPERAND:
                postfix[p++] = currSymbol;
                break;

            case LEFTPAREN:
                pushChar(stack, '(');
                break;

            case RIGHTPAREN:
                while ((stackTop = popChar(stack)) != '(')
                    postfix[p++] = stackTop;
                break;

            case OPERATOR:
                while (!isEmptyChar(*stack) &&
                       getPrec(currSymbol) <= getPrec(peekChar(*stack))) {
                    postfix[p++] = popChar(stack);
                }
                pushChar(stack, currSymbol);
                break;
        }
        i++;
    }

    while (!isEmptyChar(*stack))
        postfix[p++] = popChar(stack);

    postfix[p] = '\0';
}

int calculate(char postfix[]) {
    IntStack s;
    s.top = -1;
    int i = 0;
    char currentSymbol;
    int type, num1, num2, result;

    while (postfix[i] != '\0') {
        currentSymbol = postfix[i];
        type = getType(currentSymbol);

        if (type == OPERAND) {
            pushInt(&s, currentSymbol - '0');
        } else {
            int opType = getType2(currentSymbol);
            num1 = popInt(&s);
            num2 = popInt(&s);
            switch (opType) {
                case ADDO: result = num2 + num1; break;
                case SUBO: result = num2 - num1; break;
                case MULO: result = num2 * num1; break;
                case DIVPO: result = num2 / num1; break;
                case POWO: result = (int)pow(num2, num1); break;
                case MODEO: result = num2 % num1; break;
                default: result = 0;
            }
            pushInt(&s, result);
        }
        i++;
    }
    return popInt(&s);
}

int main() {
    CharStack stack;
    stack.top = -1;
    char infinix[SS], postfix[SS];

    printf("Enter Infix Expression : ");
    scanf("%s", infinix);

    infinixToPostfix(infinix, postfix, &stack);

    printf("\nINFIX    : %s", infinix);
    printf("\nPOSTFIX  : %s", postfix);

    int eva = calculate(postfix);
    printf("\nEVALUATION: %d\n", eva);

    return 0;
}
