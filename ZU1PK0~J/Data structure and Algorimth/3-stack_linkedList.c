// Coding by Hung Son - Clark, sdt: 0164 944 5637, email: hungsona93@gmail.com
// 

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	struct node *next;
};
typedef struct node *stacknode;
typedef struct {
	stacknode top;
} stack;

void StackInitial(stack *s)
{
	s->top = NULL;
	return;
}
int StackEmpty(stack s)
{
	return (s.top == NULL);
}
void Push(stack *s, int x)
{
	stacknode p;
	p = (stacknode) malloc(sizeof(struct node));
	p->item = x;
	p->next = s->top;
	s->top = p;
	return;
}

int Pop(stack *s)
{
	stacknode p;
	if (StackEmpty(*s))
	{
		printf("Stack is empty\n");
	}
	else
	{
		p = s->top;
		s->top = s->top->next;
		return p->item;
	}
}

int main()
{
	int a = 0;
	stack *s = (stack *) malloc(sizeof(stack));
	StackInitial(s);
	printf("%d\n", StackEmpty(*s));
	Push(s, 10);
	Push(s, 20);
	Push(s, 30);
	a = Pop(s);
	printf("%d\n", a);
	a = Pop(s);
	printf("%d\n", a);

	return 0;
}