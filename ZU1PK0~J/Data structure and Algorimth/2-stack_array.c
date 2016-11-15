#include <stdio.h>
#define MAX 100
typedef struct {
	int top;
	int data[MAX];
} stack;

void StackInitial(stack *s) 
{
	s->top = -1;
	return;
}

int isStackEmpty(stack s)
{
	return (s.top == -1);
}

int isStackFull(stack s){
	return (s.top == MAX - 1);
}

void Push(stack *s, int x)
{
	if(isStackFull(*s))
	{
		printf("Stack is full!\n");
		return;
	}
	else
	{
		s->top++;
		s->data[s->top] = x;
		return;
	}
}

int Pop(stack *s)
{
	if(isStackEmpty(*s))
	{
		printf("Stack is empty\n");
		return;
	}
	else
	{
		return s->data[s->top--];
	}
}

int main()
{
	int a;

	// Creating stack and initialing
	stack *s = (stack *) malloc(sizeof(stack));
	StackInitial(s);
	printf("%d\n", isStackEmpty(*s));

	// Push and Pop
	Push(s, 10);
	Push(s, 20);
	Push(s, 50);

	a = Pop(s);
	printf("%d\n", a);
	a = Pop(s);
	printf("%d\n", a);
	
	return 0;
}