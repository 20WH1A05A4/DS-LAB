#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*next;
	struct node*prev;
};
struct node*head = NULL;

void create_list();
void display();
void insert_end();
void insert_begin();
void insert_before();
void insert_after();
void delete_begin();
void delete_end();
void delete_specific_node();
void count_nodes();
void search_element();
int main()
{
	int choice;
	printf("   OPERATIONS\n----------------\n1.create list\n2.display\n3.insert begin\n4.insert end\n5.insert before\n6.insert after\n7.delete begin\n8.delete end\n9.delete specific node\n10.count nodes\n11.search element\n12.EXIT\n");
	do{
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create_list();
				break;
			case 2:
				display();
				break;
			case 3:
				insert_begin();
				break;
			case 4:
				insert_end();
				break;
			case 5:
				insert_before();
				break;
			case 6:
				insert_after();
				break;
			case 7:
				delete_begin();
				break;
			case 8:
				delete_end();
				break;
			case 9:
				delete_specific_node();
				break;
			case 10:
				count_nodes();
				break;
			case 11:
				search_element();
				break;
			case 12:
				printf("EXIT POINT\n");
				break;
			default:
				printf("Enter the valid choice\n");
				break;			    	
	    }
	}
	while(choice!=12);
	return 0;
}

void create_list()
{
	int n,i;
	printf("Enter  the number of nodes to be inserted:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		insert_end();
	}
}
void display()
{
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct node*temp =head;
		printf("The elements in the list are:");
		while(temp != NULL)
		{
			printf("%d  ",temp->data);
			temp= temp->next;
		}
		printf("\n");
	}
}
void insert_end()
{
	struct node*nn = (struct node*)malloc(sizeof(struct node));
	if(nn == NULL)
	{
		printf("memory is not allocated\n");
	}
	int x;
	printf("Enter the element to be inserted(insert end):");
	scanf("%d",&x);
	nn->data = x;
	if(head == NULL)
	{
		nn->next = NULL;
		nn->prev = NULL;
		head = nn;
	}
	else
	{
		struct node*temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp ->next = nn;
		nn->next = NULL;
		nn->prev = temp;
	}
}	

void insert_begin()
{
	struct node*nn= (struct node*)malloc(sizeof(struct node));
	if(nn==NULL)
	{
		printf("Memory is not allocated\n");
	}
	int x;
	printf("\nEnter the element to be inserted\n");
	scanf("%d",&x);
	nn->data = x;
	if(head == NULL)
	{
		nn->next = NULL;
		nn->prev= NULL;
		head = nn;
	}
	else
	{
		nn->next = head;
		head->prev= nn;
		nn->prev = NULL;
		head = nn;
	}
}
void insert_before()
{
	int a;
	printf("Enter the element before which you want to insert:");
	scanf("%d",&a);
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else if(a == head ->data)
	{
		insert_begin();
	}
	else
	{
		struct node*temp ,*ptemp;
		ptemp= head;
		temp = head ->next;
		while(temp ->data != a && temp != NULL)
		{
			ptemp = temp;
			temp = temp->next;
		}
		if(temp == NULL)
		{
			printf("Element is not found\n");
		}
		else
		{
			int x;
			printf("Enter the value to be inserted:");
			scanf("%d",&x);
			struct node*nn = (struct node*)malloc(sizeof(struct node));
			nn->data = x;
			ptemp ->next = nn;
			nn->next = temp;
			nn->prev= ptemp;
			temp->prev = nn;
		}
	}
}

void insert_after()
{
	int a,x;
	printf("Enter the element after which you want to insert:");
	scanf("%d",&a);
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct node*temp,*ptemp;
		temp = head;
		while(temp != NULL && temp->data != a)
		{
			temp = temp->next;
		}
		if(temp == NULL)
		{
			printf("Element is not found\n");
		}
		else if(temp ->next == NULL)
		{
			insert_end();
		}
		else
		{
			struct node*nn = (struct node*)malloc(sizeof(struct node));
			printf("Enter the element to be inserted:");
			scanf("%d",&x);
			nn->data = x;
			ptemp = temp ->next;
			temp->next = nn;
			nn->next = ptemp;
			nn->prev = temp;
			ptemp->prev = nn;
		}
	}
}

void delete_begin()
{
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct node*temp = head;
		int x;
		x = head ->data;
		head = head ->next;
		free(temp);
		head->prev = NULL;
		printf("\nThe deleted element is %d:",x);
		printf("\n");

	}
}
void delete_end()
{
	int x;
	if(head ==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct node*temp,*ptemp;
		ptemp = head;
		temp= head->next;
		while(temp ->next !=NULL)
		{
			ptemp= temp;
			temp = temp ->next;
		}
		x = temp->data;
		ptemp ->next = NULL;
		printf("\nThe deleted element is %d:\n",x);
		free(temp);
	}
}
void delete_specific_node()
{
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		int x;
		printf("Enter the element to be deleted\n");
		scanf("%d",&x);
		if(x == head->data)
		{
			delete_begin();
		}
		else
		{
			struct node*ptemp,*temp;
			ptemp = head;
			temp = head->next;
			while(temp != NULL && temp->data != x)
			{
				ptemp = temp;
				temp = temp->next;
			}
			if(temp == NULL)
			{
				printf("Element not found");
			}
			else
			{
				struct node*k;
				k = temp->next;
				ptemp ->next = k;
				k->prev = ptemp;
				int a = temp->data;
				printf("Thr deleted element is %d\n",a);
				free(temp);
			}
		}
	}
}
void count_nodes()
{
	struct node*temp;
	int count =0;
	temp = head;
	if(head == NULL)
	{
		printf("The number of nodes: 0\n");
	}
	else
	{
		while(temp != NULL)
		{
			temp = temp->next;
			count++;
		}
		printf("The number of nodes:%d\n",count);
	}
	
}
void search_element()
{
	struct node*temp;
	temp = head;
	int a;
	printf("Enter the element to be searched\n");
	scanf("%d",&a);
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
	    int i=1;
		while(temp != NULL)
		{
			if(temp->data == a)
			{
				printf("The element is found at %d\n",i);
				return;
			}
			else 
			{
				temp = temp->next;
				i=i+1;
			}
		}
		if(temp == NULL)
		{
			printf("Element is not found\n");
		}
	}
}
