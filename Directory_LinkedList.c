#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define pn_size 14
#define n_size 50

typedef struct node{
	int cust_id;
	char phone_number[pn_size];
	char name[n_size];
	struct node *next;
} node;

typedef struct{
	node *head;
	node *tail;
}linkedList;

node *tmp=NULL;

void init(linkedList *list)
{
	list->head = NULL;
	list->tail = NULL;
}

node* create(int id,char *pn,char *name)
{
	int i=0;
	tmp=(node *)calloc(1,sizeof(node));
	if(tmp != NULL)
	{		
		tmp->cust_id = id;
		while(*pn != '\0' && i < pn_size-1)
		{
			tmp->phone_number[i] = pn[i];
			i++;
		}
		tmp->phone_number[i] = '\0';
		i=0; 
		while(*name != '\0' && i < n_size-1)
		{
			tmp->name[i] = name[i];
			i++;
		}
		tmp->next = NULL;
	}	
	return tmp;			
}

void insertFirst(linkedList *list,int id,char *pn,char *name)
{
	tmp = create(id,pn,name);
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
		return;
	}
	tmp->next = list->head;
	list->head = tmp;
	list->tail->next = list->head;
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
	
	if(list->head == list->tail )
		list->tail = list->head = NULL;
	else
		list->tail->next = list->head = tmp->next;
			
	x = tmp->cust_id;
	free(tmp);
	return x;
	
}

void insertLast(linkedList *list,int id,char *pn,char *name)
{
	tmp = create(id,pn,name);
	if(tmp == NULL)
	{
		printf("Memory Full\n");
		return;
	}
	if(list->tail == NULL)
	{
		list->tail = tmp;
		list->head = tmp;
		list->tail->next =  tmp;
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
	if(tmp->next == list->head)
	{
		x = tmp->cust_id;
		list->head = list->tail = NULL;
		return x;
	}
	while(tmp->next->next != list->head)
		tmp = tmp->next;
	x = list->tail->cust_id;
	list->tail = tmp;
	tmp = tmp->next;
	list->tail->next = list->head;
	free(tmp);
	return x;	
}

void insertPos(linkedList *list,int id,char *pn,char *name,int pos)
{
	node *tmp1 = list->head;
	tmp = create(id,pn,name);
	
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
		}
		else
		{
			tmp->next = tmp1;
			list->head = tmp;
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
		list->tail = tmp;
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
		x = tmp->cust_id;
		list->head = tmp->next;
		if( list->tail == list->head)
			list->head = list->tail = NULL;
		else
			list->tail->next = list->head;
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
	x = tmp->cust_id;
	tmp1->next = tmp->next;
	if(tmp->next == list->head)
		list->tail = tmp1;
	free(tmp);
	return x;
}

int deleteId(linkedList *list,int id)
{
	int x = 0; 
	tmp = list->head;
	if( tmp == NULL )
	{
		printf("List Empty\n");
		return x;
	}
	int n = 1;
	do
	{
		if( tmp->cust_id == id )
		{	
			break;
		}
		tmp = tmp->next;
		n++;
	}while(tmp != list->head);
	if(tmp == list->head && n !=1)
	{
		printf("Value not found\n");
		return x;
	}
	x = deletePos(list,n);
	return x;
}

int deletePNo(linkedList *list,char *pn)
{
	int x = 0; 
	tmp = list->head;
	if( tmp == NULL )
	{
		printf("List Empty\n");
		return x;
	}
	int n = 1,flag=0,i=0;
	do
	{
		while(i < pn_size-1 && pn[i] == tmp->phone_number[i])		
			i++;
		if(i == pn_size - 1)
		{
			flag=1;
			break;
		}
		tmp = tmp->next;
		n++;
	}while(tmp != list->head && flag == 0 );
	if(tmp == list->head && flag==0 && n!=1)
	{
		printf("Value not found\n");
		return x;
	}
	x = deletePos(list,n);
	return x;
}

int deleteName(linkedList *list,char *name)
{
	int x = 0; 
	tmp = list->head;
	if( tmp == NULL )
	{
		printf("List Empty\n");
		return x;
	}
	int n = 1,flag=0,i=0;
	do
	{
		while(i < n_size-1 && name[i] == tmp->name[i])		
			i++;
		if(i == n_size - 1)
		{
			flag=1;
			break;
		}
		tmp = tmp->next;
		n++;
	}while(tmp != list->head && flag == 0);
	if(tmp == list->head && flag==0 && n!=1)
	{
		printf("Value not found\n");
		return x;
	}
	x = deletePos(list,n);
	return x;
}

void searchId(linkedList *list,int id)
{
	int x = 0; 
	tmp = list->head;
	if( tmp == NULL )
	{
		printf("List Empty\n");
		return;
	}
	int n = 1;
	do
	{
		if(tmp->cust_id == id)
			break;
		tmp = tmp->next;
		n++;
	}while(tmp != list->head);
	if(tmp == list->head && n!=1)
	{
		printf("Not found\n");
		return;
	}
	printf("|ID: %8d |\tName: %50s |\tPhone no: %15s|\n",tmp->cust_id,tmp->name,tmp->phone_number);
}

void searchPNo(linkedList *list,char *pn)
{
	int x = 0; 
	tmp = list->head;
	if( tmp == NULL )
	{
		printf("List Empty\n");
		return;
	}
	int n = 1,flag=0,i=0;
	do
	{
		while(i < pn_size-1 && pn[i] == tmp->phone_number[i])		
			i++;
		if(i == pn_size - 1)
		{
			flag=1;
			break;
		}
		tmp = tmp->next;
		n++;
	}while(tmp != list->head && flag == 0 );
	if(tmp == list->head && flag==0 && n!=1)
	{
		printf("Not found\n");
		return;
	}
	printf("|ID: %8d |\tName: %50s |\tPhone no: %15s|\n",tmp->cust_id,tmp->name,tmp->phone_number);
}

void searchName(linkedList *list,char *name)
{
	int x = 0; 
	tmp = list->head;
	if( tmp == NULL )
	{
		printf("List Empty\n");
		return;
	}
	int n = 1,flag=0,i=0;
	do
	{
		while(i < n_size-1 && name[i] == tmp->name[i])		
			i++;
		if(i == n_size - 1)
		{
			flag=1;
			break;
		}
		tmp = tmp->next;
		n++;
	}while(tmp != list->head && flag == 0 );
	if(tmp == list->head && flag==0 && n!=1)
	{
		printf("Not found\n");
		return;
	}
	printf("|ID: %8d |\tName: %50s |\tPhone no: %15s|\n",tmp->cust_id,tmp->name,tmp->phone_number);
}
/*
void insertOrder(linkedList *list,int id,char* name,char *no)
{
	node *tmp1 = list->head;
	int n = 1;	
	if(tmp1 == NULL)
	{
		insertPos(list,id,no,name,n);
		return;
	}
	if( tmp1->cust_id > id)
	{
		insertPos(list,id,no,name,n);
		return;
	}
	n++;
	while(tmp1->next != list->head && tmp1->next->cust_id <= id)
	{		
		tmp1 = tmp1->next;
		n++;
	}
	insertPos(list,id,no,name,n);
}

void displaySorted(linkedList *list) 
{
	tmp = list->head;
	if(tmp == NULL)
	{
		printf("List Empty\n");
		return;
	}
	linkedList tl;
	init(&tl);
	do
	{
		insertOrder(&tl,tmp->cust_id,tmp->name,tmp->phone_number);
		tmp = tmp->next;
	}while(tmp!=list->head);
	node *prev = NULL;
	tmp = tl.head;
	printf("---------------------------------------------------------------------------------------------------------\n");
	do
	{
		printf("|ID: %8d |\tName: %50s |\tPhone no: %15s|\n",tmp->cust_id,tmp->name,tmp->phone_number);
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}while( tmp != tl.head);
	printf("----------------------------------------------------------------------------------------------------------\n");	
	return;	
}
*/
void display(linkedList *list) 
{
	tmp = list->head;
	if(tmp == NULL)
	{
		printf("List Empty\n");
		return;
	}	
	printf("---------------------------------------------------------------------------------------------------------\n");
	do
	{
		printf("|ID: %8d |\tName: %50s |\tPhone no: %15s|\n",tmp->cust_id,tmp->name,tmp->phone_number);
		tmp = tmp->next;
	}while( tmp != list->head);
	printf("----------------------------------------------------------------------------------------------------------\n");	
	return;	
}

bool isEmpty(linkedList *list)
{
	return (list->head == NULL)?true:false;
}
