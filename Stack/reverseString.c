#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SS 10
#define STACK_OVERFLOW 0
#define STACK_UNDERFLOW -32768
#define PUSH_SUCCESS 2
#define INVALID_NUMBER 1

typedef struct Stack{
	int top;
	char nums[SS];
}Stack;

int isEmpty(Stack s)
{
	if(s.top == -1)
		return 1;

	return 0;
}

int isFull(Stack s)
{
	if(s.top == SS -1)
		return 1;

	return 0;
}

int push(Stack *ps,int x)
{
	if(isFull(*ps))
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
	if(isEmpty(*ps))
		 return STACK_UNDERFLOW;

	return ps->nums[ps->top--];
}

int peek(Stack s)
{
	 if(isEmpty(s))
		return STACK_UNDERFLOW;

	return s.nums[s.top];

}
void display(Stack s)
{
	int i;
	for(i = s.top ;i>=0;i--)
	{
		printf("%d ",s.nums[i]);
	}
	printf("\n");
}

void reverseString(Stack *ps,char string[],char reverseString[])
{
    int len = strlen(string);
    int i= 0;
    for(i=0;i<len;i++)
    {
        push(ps,string[i]);
    }

    int j =0;
    while(!isEmpty(*ps))
    {
        char top = peek(*ps);
        reverseString[j] = top;
        pop(ps);
        j++;
    }
	reverseString[j] = '\0';
}       

int main()
{
    Stack s;
	s.top = -1;
    char string[100],stringReverse[100];
    printf("Enter string to reverse: ");
    gets(string);

    reverseString(&s,string,stringReverse);
    printf("Reversed String: %s\n", stringReverse);

}