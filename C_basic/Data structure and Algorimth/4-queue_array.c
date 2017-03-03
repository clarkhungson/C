// Coding by Hung Son - Clark, sdt: (+84)164 944 5637, email: hungsona93@gmail.com
// Queue installed on an array

#include <stdio.h>

#define MAX 100
typedef struct {
	int head, tail, count;
	int node[MAX];
} queue;

void QueueInitialize(queue *q)
{
	q -> head = 0;
	q -> tail = 0;
	q -> count = 0;
	return;
}

int QueueEmpty(queue q)
{
	return (q.count <= 0);
}

void Push(queue *q, int x)
{
	if (q -> count == MAX)
		printf("Queue is full!\n");
	else 
	{
		q -> node[q -> tail] = x;
		if (q -> tail == MAX - 1)
			q -> tail = 0;
		else
			(q -> tail)++;
		q -> node[q -> tail] = x;
		q -> count++;
	}
	return;
}

int Pop(queue *q)
{
	int x;
	if (QueueEmpty(*q))
		printf("Queue is empty!\n");
	else
	{
		x = q-> node[q -> head];
		if (q -> head == MAX - 1)
			q -> head = 0;
		else
			(q -> head)++;
		q -> count--;
	}
	return x;
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