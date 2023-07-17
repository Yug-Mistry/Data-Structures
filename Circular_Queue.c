#include <stdio.h>

void enqueue(int *queue, int *front, int *rear, int size, int item)
{
	if ((*rear + 1) % size == *front)
	{
		printf("Queue is full !\n");
		return;
	}
	else if (*front == -1)
	{
		*front += 1;
	}

	queue[(*rear + 1) % size] = item;
	*rear = (*rear + 1) % size;
}

int dequeue(int *queue, int *front, int *rear, int size)
{
	if (*front == -1)
	{
		printf("Queue is empty !\n");
		return 0;
	}
	int i = queue[*front];
	if (*front == *rear)
	{
		*front = *rear = -1;
		return i;
	}
	*front = (*front + 1) % size;
	return i;
}

void display(int *queue, int *front, int *rear, int size)
{
	int temp[size], f = -1, r = -1;
	while (*front != -1)
	{
		int t = dequeue(queue, front, rear, size);
		if (t)
		{
			printf("%d| ", t);
			enqueue(temp, &f, &r, size, t);
		}
	}
	printf("\n");

	while (f != -1)
	{
		int t = dequeue(temp, &f, &r, size);
		if (t)
			enqueue(queue, front, rear, size, t);
	}
}
