#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int data;
	struct node *next;
} node;

typedef struct{
	node *head;
	node *tail;
}linkedList;

node *tmp=NULL;

node* create(int x)
{
	tmp=(node *)calloc(1,sizeof(node));
	if(tmp != NULL)
	{		
		tmp->data = x;
		tmp->next = NULL;
	}	
	return tmp;			
}

void insertFirst(linkedList *list,int data)
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
		tmp->next = list->head;
		return;
	}
	tmp->next = list->head;
	list->head = tmp;
	list->tail->next = tmp;
	return;
}

int deleteFirst(linkedList *list)
{
	tmp = list->head;
	int x = 0;
	if(tmp == NULL)
	{
		printf("List Empty\n");
		return x;
	}
	list->head = tmp->next;
	list->tail->next = tmp->next;
	
	if(tmp->next == tmp)
	{
		list->tail = NULL;
		list->head = NULL;
	}
		
	x = tmp->data;
	free(tmp);
	return x;
	
}

void insertLast(linkedList *list,int x)
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
		list->tail->next = list->head;
		return;
	}
	list->tail->next = tmp;
	list->tail = tmp;
	list->tail->next = list->head;
}

int deleteLast(linkedList *list)
{
	tmp = list->head;
	int x = 0;
	if(tmp == NULL)
	{
		printf(" List empty\n");
		return x;
	}
	while(tmp->next->next != list->head)
		tmp = tmp->next;
	x = list->tail->data;
	list->tail = tmp;
	tmp = tmp->next;
	list->tail->next = list->head;
	free(tmp);
	return x;	
}

void insertPos(linkedList *list,int x,int pos)
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
			list->tail->next = list->head;
		}
		else
		{
			tmp->next = tmp1;
			list->head = tmp;
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
	tmp2->next = tmp;
	tmp ->next = tmp1;
	if(tmp1 == list->head)
	{
		list->tail = tmp;
		list->tail->next = list->head;
	}
}

int deletePos(linkedList *list,int pos)
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
		list->head = tmp->next;
		list->tail->next = list->head;
		if( tmp->next == tmp)
		{
			list->tail = NULL;
			list->head = NULL;	
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
		printf("Invalid Position\n");
		return x;
	}
	x = tmp->data;
	tmp1->next = tmp->next;
	if(tmp->next == list->head)
	{
		list->tail = tmp1;
		list->tail->next = list->head;
	}
	free(tmp);
	return x;
}

int deleteData(linkedList *list,int dat)
{
	int x = 0; 
	tmp = list->head;
	if( tmp == NULL )
	{
		printf("List Empty\n");
		return x;
	}
	int n = 1;
	while(tmp != list->head && tmp->data != dat )
	{
		tmp = tmp->next;
		n++;
	}
	if(tmp == NULL)
	{
		printf("Value not found\n");
		return x;
	}
	x = deletePos(list,n);
	return x;
}

void display(linkedList *list)
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
