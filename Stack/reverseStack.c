#include<stdio.h>
#include<stdlib.h>
#define SS 10
#define STACK_OVERFLOW 0
#define STACK_UNDERFLOW -32768
#define PUSH_SUCCESS 2
#define INVALID_NUMBER 1

typedef struct Stack{
	int top;
	int nums[SS];
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

void pushAtBottom(Stack *ps, int val)
{
    if(isEmpty(*ps))
    {
        push(ps,val);
        return;
    }

    int temp;
    temp = pop(ps);
    pushAtBottom(ps,val);
    push(ps,temp);
}

void reverseStack(Stack *ps)
{
    if(isEmpty(*ps))
    {
        return;
    }

    int temp = peek(*ps);
    pop(ps);
    reverseStack(ps);
    pushAtBottom(ps,temp);
    
}
int main()
{
    Stack s;
    s.top =-1;
    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);

    display(s);
    reverseStack(&s);
    display(s);
}