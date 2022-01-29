#include<stdio.h>
#include<stdlib.h>
void test();
void display();
void insert_begin();
void insert_end();
void insert_before();
void insert_after();
void deletion_first();
void deletion_end();
void deletion_before();
void deletion_specified_node();
void count_nodes();
void search_element();
struct node
{
	int data;
	struct node* next;
};
struct node* head = NULL;

int main()
{
	test();
	display();
	insert_begin();
    display();
	insert_end();
	display();
	insert_before();
	insert_after();
	display();
   	deletion_first();
   	display();
	deletion_end();
	display();
	deletion_specified_node();
	display();
    //display_reverse();
    count_nodes();
	//display();
	search_element();
	
	return 0;
}
void test()
{
	struct node*n1=(struct node*)malloc(sizeof(struct node));
	if(n1 == NULL)
	{
		printf("Overflow\n");
	}
	else
	{
		n1->data = 20;
		n1-> next = NULL;
	}
	head = n1;
	struct node*n2 = (struct node*)malloc(sizeof(struct node));
	if(n2 == NULL)
	{
		printf("Overflow\n");
	}
	else
	{
		n2->data = 30;
		n2-> next = NULL;
	}
	n1 ->next = n2;
}
void display()
{
	struct node*temp;
	temp = head;
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("\nThe elements are:");
		while(temp != NULL)
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
	printf("\n");
} 
void insert_begin()
{
	int x;
	printf("\nEnter the element to be insert(insert begin)\n");
	scanf("%d",&x);
	struct node*nn = (struct node*)malloc(sizeof(struct node));
	if(nn == NULL)
	{
		printf("Overflow\n");
	}
	nn ->data = x;
	if(head == NULL)
	{
	    head = nn;
	    nn-> next = NULL;
	}
	else
	{
		nn->next = head;
		head = nn;
	}
}
void insert_end()
{
	int x;
	printf("\nEnter the element to be insert(insert end)\n");
	scanf("%d",&x);
	struct node*nn = (struct node*)malloc(sizeof(struct node));
	if(nn == NULL)
	{
		printf("Overflow\n");
	}
	nn ->data = x;
	if(head == NULL)
	{
		nn->next = head;
		head = nn;
	}
	else
	{
		struct node*temp = (struct node*)malloc(sizeof(struct node));
		if(temp == NULL)
		{
			printf("Overflow\n");
		}
		temp = head;
		while(temp -> next != NULL)
		{
			temp = temp->next;
		}
		temp->next = nn;
		nn->next = NULL;
	}
}
void insert_before()
{
	int a,x;
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	struct node*ptemp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element before which you want to insert \n");
    scanf("%d",&a);
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else if(a == head ->data)
	{
		insert_begin();
		//display();
	}
	else
	{
	
	//	printf("Enter the element before which you want to insert \n");
		//scanf("%d",&a);
		printf("enter the element to be inserted(insert_before)\n");
		scanf("%d",&x);
		ptemp = head; 
		temp=head->next;
		while((temp->data != a) && (temp != NULL))
		{
			ptemp = temp;
			temp = temp->next;
		}
		if(temp == NULL)
		{
			printf("No data found\n");
		}
		else
		{
			struct node*nn= (struct node*)malloc(sizeof(struct node));
			nn ->data = x;
			ptemp ->next = nn;
			nn->next = temp;
		
		}
	}
	
}
void insert_after()
{
	int a,x;
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	struct node*ptemp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element after which you want to insert \n");
    scanf("%d",&a);
	if(head == NULL)
	{
		printf("no data found\n"); 
	}

	else
	{
	
	//	printf("Enter the element before which you want to insert \n");
		//scanf("%d",&a);
		
		ptemp = head; 
		temp=head->next;
		while((ptemp->data != a) && (ptemp != NULL))
		{
			ptemp = temp;
			temp = temp->next;
	    }
	        if(temp==NULL )
			{
		  //	printf("enter the element to be inserted(insert_before)\n");
		    //scanf("%d",&x);
				insert_end();
			}
			else
			{
				struct node*nn= (struct node*)malloc(sizeof(struct node));
				printf("enter the element to be inserted(insert_before)\n");
		   	 	scanf("%d",&x);
				nn ->data = x;
				ptemp ->next = nn;
				nn->next=temp;
			}
	    
	}
}
void deletion_first()
{
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct node*temp=(struct node*)malloc(sizeof(struct node));
		temp = head;
		int x=temp->data;
		head = head->next;
		printf("\nThe deleted element is:%d\n",x);
		free(temp);
		
	}
}
void deletion_end()
{
	int x;
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct node*temp=(struct node*)malloc(sizeof(struct node));
    	struct node*ptemp=(struct node*)malloc(sizeof(struct node));
    	ptemp = head;
    	temp = head->next;
    	while(temp -> next != NULL)
    	{
    		ptemp = temp;
    		temp = temp -> next;
		}
	    x=temp->data;
	    ptemp->next = NULL;
		printf("\nThe deleted element is:%d\n",x);
		free(temp);
	
	}
}
void deletion_specified_node()
{
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	int a;
	printf("Enter the element to be deleted\n");
	scanf("%d",&a);
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp = head;
	if(a == head->data)
	{
		head = head->next;
		free(temp);
		//deletion_first();
	}
	else
	{
		struct node*ptemp=(struct node*)malloc(sizeof(struct node));
		struct node*temp=(struct node*)malloc(sizeof(struct node));
		ptemp = head;
		temp = head->next;
		while((temp->data != a) && (temp!= NULL))
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
		//	struct node*p;
		//	p=temp->next;
			ptemp->next = temp->next;
			free(temp);
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
		//printf("\nThe elements are:");
		while(temp != NULL)
		{
			//printf("%d ",temp->data);
			temp = temp->next;
			count++;
		}
		printf("The number of nodes:%d",count);
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
	//	printf("\nThe elements are:");
	    int i=1;
		while(temp != NULL)
		{
			//int i=1;
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
