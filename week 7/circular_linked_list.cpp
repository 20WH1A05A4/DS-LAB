#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
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
	//	printf("%d ",head->data);
	    while(temp->next!= head)
		{
			printf("%d  ",temp->data);
			temp= temp->next;
		}
		printf("%d",temp->data);
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
		head = nn;
		nn->next = head;
	}
	else
	{
		struct node*temp = head;
		while(temp->next != head)
		{
			temp = temp->next;
		}
		temp ->next = nn;
		nn->next = head;
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
	printf("Enter the element to be inserted\n");
	scanf("%d",&x);
	nn->data = x;
	if(head == NULL)
	{
		head = nn;
		nn->next=head; 
	}
	else
	{
		struct node*temp=head;
		while(temp->next!=head)
		{
			temp = temp->next;
		}
		temp->next=nn;
		nn->next = head;
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
		while(temp ->data != a && temp != head)
		{
			ptemp = temp;
			temp = temp->next;
		}
		if(temp == head)
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
		while( temp->data != a)
		{
			if(temp->next == head)
			{
				printf("Element is not found\n");
				insert_end();
			}
			else
			{
				temp = temp->next;
			}
		}
		if(temp == head)
		{
			printf("Element is not found\n");
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
		}
	}
}

void delete_begin()
{
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else if(head->next == head)
	{
		head = NULL;
		printf("Deletion is done\n");
	}
	else
	{
		struct node*temp = head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=head->next;
		int x;
		x = head ->data;
	    temp = head;
		head = head ->next;
		free(temp);
		printf("The deleted element is %d\n",x);
	//	printf("\n");

	}
}
void delete_end()
{
	int x;
	if(head ==NULL)
	{
		printf("List is empty\n");
	}
	else if(head->next == head)
	{
		free(head);
		head = NULL;
		printf("Node deleted is %d\n",head->data);
	}
	else
	{
		struct node*temp,*ptemp;
		ptemp = head;
		temp= head->next;
		while(temp ->next !=head)
		{
			ptemp= temp;
			temp = temp ->next;
		}
		x = temp->data;
		ptemp ->next = head;
		printf("The deleted element is %d\n",x);
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
			while( temp->data != x)
			{
				if(temp->next == head)
				{
					delete_end();
				}
				else
				{
					ptemp = temp;
					temp = temp->next;
				}
			}
			if(temp == head)
			{
				printf("Element not found");
			}
			else
			{
				struct node*k;
				k = temp->next;
				ptemp ->next = k;
				int a = temp->data;
				printf("The deleted element is %d\n",a);
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
		while(temp->next != head)
		{
			temp = temp->next;
			count++;
		}
		printf("The number of nodes:%d\n",count+1);
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
		while(temp->next != head)
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
		if(temp->data == a)
		{
			printf("The element is found at %d\n",i);
			
		}
		else
		{
			printf("Element is not found\n");
		}
	}
}
