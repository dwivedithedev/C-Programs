#include<stdio.h>
#include<conio.h>
#define True 1
#define False 0

/*
Program of Linked List and its operation implementation
with Menu based choices.
1. Insert a Node (Beginning, End, At a position).
2. Delete a Node (Beginning, End, At a position).
3. Display Nodes Linked list
4. Searching a Node element (Sorted and Unsorted list).


By Vaibhav Dwivedi
*/

typedef struct node
{
	int info;
	struct node *next;
}Node;

Node * create_node();

int isempty(Node *);
void display(Node *);
int count_node(Node *);

void insert_beg(Node **);
void insert_end(Node **);
void insert_pos(Node **);

void delete_beg(Node **);
void delete_end(Node **);
void delete_pos(Node **);

void search_unsort(Node *);
void search_sort(Node *);

void main()
{
	int item,ch,ch1;
	Node *Start = NULL;
do {
	printf("\n\tMenu Board\n\n");
	printf("\n1. Insert\n2. Delete \n3. Searching \n4. Display()\n Enter you option:- ");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1: printf("\n\tChoose an Option\n1. To insert in the beginning\n2. To insert in the end\n3. To insert at specific postion.\n Enter you option:- ");
				scanf("%d", &ch1);
				switch(ch1)
					{
					case 1: insert_beg(&Start);
							break;
					case 2: insert_end(&Start);
							break;
					case 3: insert_pos(&Start);
							break;
					case 4: break;
							default: printf("Wrong option entered");
					}
					break;
		case 2: printf("\n\tChoose an Option\n1. To delete from the beginning\n2. To delete from the end\n3. To delete from specific postion.\n Enter you option:- ");
				scanf("%d", &ch1);
				switch(ch1)
					{
					case 1: delete_beg(&Start);
							break;
					case 2: delete_end(&Start);
							break;
					case 3: delete_pos(&Start);
							break;
					case 4: break;
					default: printf("Wrong option entered");
					}
					break;

		case 3: display(Start);
				printf("\n\t Search on type of list? \n1. Sorted \n2. Unsorted\n Enter you option:- ");
				scanf("%d", &ch1);

				switch(ch1)
				{
					case 1: search_unsort(Start);
					break;

					case 2: search_unsort(Start);
					break;
				}
				break;

		case 4: display(Start);
				break;
		default: printf("\t\t !!! ABORT ABORT ABORT !!!\t\t");
		break;
	}
}while(1);
}


Node * create_node()
{	Node *nptr;
	int item;
	nptr=(Node *)malloc(sizeof(Node));
	if(nptr == NULL)
	{
		printf("Overflow! Memory allocated nahi hai..");
	}

	printf("\nEnter the value you want to be inserted: ");
	scanf("%d", &item);
	nptr->info=item;
	nptr->next=NULL;
	return nptr;
}
int isempty(Node *Start)
{
	if(Start==NULL)
		return True;
		else
		return False;
}
void display(Node *Start)
{
	Node *temp=Start;
	if(isempty(temp))
	{
		printf("\nList is empty.\n\n");
		return;
	}
	printf("\nLinked list is as: \n");
	while(temp != NULL)
	{
		printf("\t %d \n",temp->info);
		temp=temp->next;
	}
}
int count_node(Node *Start)
{
	Node*temp = Start;
	int count =0;

	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}
void insert_beg(Node **Start)
{
	Node *nptr=create_node();
	nptr->next=*Start;
	*Start=nptr;
	printf("\nNode inserted.\n\n");
}
void insert_end(Node **Start)
{
	Node *temp=*Start;
	Node *nptr=create_node();
	if(isempty(temp))
		*Start=nptr;
	else
	{
		while(temp->next != NULL)
		temp=temp->next;
		temp->next=nptr;
	}
	printf("\nNode inserted.\n\n");
}
void insert_pos(Node **Start)
{
	int i,pos,count;
	Node *nptr=create_node();
	Node *temp=*Start;
	printf("\nEnter the position where you want to insert the value:- \t");
	scanf("%d",&pos);
	count=count_node(temp);
	if(pos>count+1 || pos==0)
	{
	printf("\n Wrong position!\n\n");
	return;
	}
	if(pos==1)
	{
	nptr->next=*Start;
	*Start=nptr;
	}
	else
	{
	for(i=1;i<pos-1;i++)
	temp=temp->next;
	nptr->next=temp->next;
	temp->next=nptr;
	}
	printf("\nNode inserted..\n\n");
}

void delete_beg(Node ** Start) {
  Node * temp = * Start;
  if (isempty(temp)) {
    printf("\nUnderflow: List is empty!");
    return;
  } *Start=temp->next;
  printf("\nNode deleted.");
}
void delete_end(Node ** Start) {
  Node * temp = * Start;
  Node * save;
  if (isempty(temp)) {
    printf("\nUnderflow: List is empty!");
    return;
  }
  if (temp->next == NULL)
    *Start = NULL;
  else {
    while (temp->next != NULL) {
      save = temp;
      temp = temp->next;
    }
    save->next = NULL;
  }

  printf("\nNode deleted.");
}
void delete_pos(Node ** Start) {
  Node *temp = *Start, *save;
  int i, pos, count;
  if (isempty(temp)) {
    printf("\nUnderflow: List is empty!");
    return;
  }
  printf("\nEnter the position of the node to be deleted: ");
  scanf(" % d", & pos);
  count = count_node(temp);
  if (pos > count || pos == 0) {
    printf("\nInvalid position!");
    return;
  }
  if (pos == 1)
    *Start=temp->next;
  else {
    for (i = 1; i < pos; i++) {
      save = temp;
      temp = temp->next;
    }
    save->next=temp-> next;
  }
  printf("\nNode deleted.");
}

void search_unsort(Node *Start)
{
	Node *ptr=Start;
	int item,pos=1;
	printf("\n\n Enter the value to be searched: ");
	scanf("%d", &item);

	while(ptr!=NULL)
	{
		if(item==ptr->info)
		{
			printf("\n Value found at position: %d \n\n", pos);
			return;
		}
		else
		{
			ptr=ptr->next;
			pos++;
		}

	}	printf("Value not found!");
}

void search_sort(Node *Start)
{
	Node *ptr=Start;
	int item, pos=1;
	printf("\n\nEnter the value to be searched");
	scanf("%d", &item);

	while(ptr->next != NULL)
	{
		if(item<ptr->info)
			{
			printf("\nValue not found.");
			return;
			}
		else if(item==ptr->info)
			{
			printf("\nValue found at position: %d",pos);
			return;
			}
		else
			{
			ptr=ptr->next;
			pos++;
			}
	}
			printf("\nValue not found.");
}

















