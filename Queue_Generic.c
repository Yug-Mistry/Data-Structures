#include <stdio.h>

void enqueue(int *queue, int *front, int *rear, int size, int item){
	if(*rear == (size - 1)){
		printf("Queue is full !\n");
		return;
	}
	else if( *front == -1){
		*front += 1;
	}

	queue[*rear + 1] = item;
	*rear += 1;
}

int dequeue(int *queue, int *front, int *rear){
	if(*front == -1){
		printf("Queue is empty !\n");
		return 0;
	}
	int i = queue[*front];
	if(*front == *rear){
		*front = *rear = -1;
		return i;
	}
	*front += 1;
	return i;
}

void display(int *queue, int *front, int *rear, int size){
	int temp[size], f = -1, r = -1;
	while(*front != -1){
		int t = dequeue(queue, front, rear);
		if(t){
			printf("%d| ", t);
			enqueue(temp, &f, &r, size, t);
		}
	}
	printf("\n");
	
	while(f != -1){
		int t = dequeue(temp, &f, &r);
		if(t)
			enqueue(queue, front, rear, size, t);
	}
}
