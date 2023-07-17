#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	struct node *prev;
	int data;
	struct node *next;
} node;

typedef struct{
	node *head;
	node *tail;
}dLinkedList;

node *tmp=NULL;

node* create(int x)
{
	tmp = (node *)calloc(1,sizeof(node));
	if(tmp != NULL)
	{	
		tmp->prev = NULL;
		tmp->data = x;
		tmp->next = NULL;
	}	
	return tmp;			
}

void insertFirst(dLinkedList *list,int data)
{
	tmp = create(data);
	if(tmp == NULL)
	{
		printf(" Memory full \n");
		return;
	}
	if( list->head == NULL)
	{
		list->head = tmp;
		list->tail = tmp;
		list->tail->next = list->head;
		list->head->prev = list->tail;
		return;
	}
	tmp->next = list->head;
	list->head->prev = tmp; //2nd node prev
	list->head = tmp;
	list->head->prev = list->tail;//1st node prev
	list->tail->next = list->head;
	return;
}

int deleteFirst(dLinkedList *list)
{
	tmp = list->head;
	int x = 0;
	if(tmp == NULL)
	{
		printf("List Empty\n");
		return x;
	}
	tmp->next->prev = list->tail;
	list->head = tmp->next;
	
	if(tmp->next == tmp)
	{
		list->tail = NULL;
		list->head = NULL;	
	}
	else
	{
		list->head->prev = list->tail;
		list->tail->next = list->head;
	}
		
	x = tmp->data;
	free(tmp);
	return x;
	
}

void insertLast(dLinkedList *list,int x)
{
	tmp = create(x);
	if(tmp == NULL)
	{
		printf("Memory Full\n");
		return;
	}
	if(list->tail == NULL)
	{
		list->tail = tmp;
		list->head = tmp;
		list->head->prev = list->tail;
		list->tail->next = list->head;
		return;
	}
	list->tail->next = tmp;
	tmp->prev = list->tail;
	list->tail = tmp;
	list->head->prev = list->tail;
	list->tail->next = list->head;
}

int deleteLast(dLinkedList *list)
{
	tmp = list->tail;
	int x = 0;
	if(tmp == NULL)
	{
		printf(" List empty\n");
		return x;
	}	
	tmp = tmp->prev;
	x = list->tail->data;
	list->tail = tmp;
	tmp = tmp->next;
	list->head->prev = list->tail;
	list->tail->next = list->head;
	free(tmp);
	return x;	
}

void insertPos(dLinkedList *list,int x,int pos)
{
	node *tmp1 = list->head;
	tmp = create(x);
	
	if(tmp == NULL)
	{
		printf("Memory Full\n");
		return;
	}
	if(pos <= 0 )
	{
		printf(" Invalid position\n");
		return;
	}
	if ( pos == 1 )
	{
		if( tmp1 == NULL)
		{
			list->head = tmp;
			list->tail = tmp;
			list->head->prev = list->tail;
			list->tail->next = list->head;
		}
		else
		{
			tmp->next = tmp1;
			tmp1->prev = tmp;
			list->head = tmp;
			list->head->prev = list->tail;
			list->tail->next = list->head;
		}
		return;
	}	
	
	int n = 1;
	node *tmp2 = NULL;
	do
	{
		tmp2 = tmp1;	//tmp2 represent the node previous to the new node after insertion
		tmp1 = tmp1->next;	//tmp1 represent the node next to the new node after insertion
		n++;
	}while( tmp1 != list->head && n < pos);
	if(n != pos)
	{
		printf("Invalid position\n");
		return;
	}
	
	tmp->next = tmp1;
	tmp->prev = tmp2;	
	tmp2->next = tmp;
	
	if(tmp1 == list->head)
	{
		list->tail = tmp;
		list->head->prev = list->tail;
		list->tail->next = list->head;
	}
	else
	{
		tmp1->prev = tmp;
	}	
}

int deletePos(dLinkedList *list,int pos)
{
	int x = 0;
	tmp = list->head;
	
	if( pos <= 0 )
	{
		printf(" Invalid position\n");
		return x;
	}
	if(tmp == NULL)
	{
		printf("List is Empty\n");
		return x;	
	}	
	if(pos == 1)
	{
		x = tmp->data;
		tmp->next->prev = list->tail;
		list->head = tmp->next;
		if( tmp->next == tmp)
		{
			list->tail = NULL;
			list->head = NULL;
		}
		else
		{
			list->head->prev = list->tail;
			list->tail->next = list->head;
		}
		free(tmp);
		return x;
	}	
	int n = 1;
	node *tmp1 = NULL;
	do
	{
		tmp1 = tmp;	//tmp1 represent previous of the node to be deleted
		tmp = tmp->next; //tmp represent the node to be deleted
		n++;
	}while( tmp->next != list->head && n < pos);
	if( n != pos)
	{
		printf("Invalid position\n");
		return x;
	}
	
	x = tmp->data;
	tmp1->next = tmp->next;
	
	if(tmp->next == list->head)
	{
		list->tail = tmp1;
		list->head->prev = list->tail;
		list->tail->next = list->head;
	}
	else
		tmp->next->prev = tmp1;
	free(tmp);
	return x;
}

int deleteData(dLinkedList *list,int dat)
{
	int x = 0; 
	tmp = list->head;
	if( tmp == NULL )
	{
		printf("List Empty\n");
		return x;
	}
	int n = 1;
	if(tmp->data != dat)
	{
		tmp = tmp->next;
		n++;
	}
	while(tmp != list->head && tmp->data != dat )
	{
		tmp = tmp->next;
		n++;
	}
	if(tmp == list->head)
	{
		printf("Value not found\n");
		return x;
	}
	x = deletePos(list,n);
	return x;
}

void display(dLinkedList *list)
{
	tmp = list->head;
	if(tmp == NULL)
	{
		printf("List Empty\n");
		return;
	}
	printf(" %d ",tmp->data);
	tmp = tmp->next;
	while( tmp != list->head)
	{
		printf("--> %d ",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");	
	return;	
}

void displayRev(dLinkedList *list)
{
	tmp = list->tail;
	if(tmp == NULL)
	{
		printf("List Empty\n");
		return;
	}
	printf(" %d ",tmp->data);
	tmp = tmp->prev;
	while( tmp != list->tail)
	{
		printf("--> %d ",tmp->data);
		tmp = tmp->prev;
	}
	printf("\n");	
	return;	
}
