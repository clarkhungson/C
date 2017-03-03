// Coding by Hung Son - Clark, sdt: (+84)164 944 5637, email: hungsona93@gmail.com
// Queue installed on a linked list

#include <stdio.h>

struct node 
{
	int item;
	struct node *next;
};

typedef struct node *queuenode;
typedef struct {
	queuenode head;
	queuenode tail;
} queue;

void QueueInitialize(queue *q)
{
	q -> head = q -> tail = NULL;
	return;
}

int QueueEmpty(queue q)
{
	return (q.head == NULL);
}

void Push(queue *q, int x)
{
	queuenode p;
	p = (queuenode) malloc (sizeof(struct node));
	p -> item = x;
	p -> next = NULL;

	if ( q -> head == NULL)
	{
		q -> head = q -> tail = p;
	}
	else
	{
		q -> tail -> next = p;
		q -> tail = q -> tail -> next;
	}
	return;

}

int Pop(queue *q)
{
	queuenode p;
	if (QueueEmpty(*q))
	{
		printf("Queue is empty!\n");
		return 0;
	}
	else
	{
		p = q -> head;
		q -> head = q -> head -> next;
		return p -> item;
	}
}

int main()
{
	queue *q = (queue *) malloc(sizeof(queue));
	QueueInitialize(q);
	printf("%d\n", QueueEmpty(*q));

	Push(q, 10);
	Push(q, 20);
	Push(q, 30);
	printf("%d\n", QueueEmpty(*q));

	printf("Pop: %d\n", Pop(q));
	printf("Pop: %d\n", Pop(q));
	printf("Pop: %d\n", Pop(q));
	printf("%d\n", QueueEmpty(*q));

	return 0;
}