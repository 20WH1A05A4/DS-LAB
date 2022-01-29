#include<stdio.h>
#include<stdlib.h>
void test();
void display();
struct node
{
	int data;
	struct node* next;
};
struct node* head = NULL;
struct node* head1 = NULL;

int main()
{
	test();
	display();
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
	struct node*n3=(struct node*)malloc(sizeof(struct node));
	if(n3 == NULL)
	{
		printf("Overflow\n");
	}
	else
	{
		n3->data = 50;
		n3-> next = NULL;
	}
	head1 = n3;
	struct node*n4 = (struct node*)malloc(sizeof(struct node));
	if(n4 == NULL)
	{
		printf("Overflow\n");
	}
	else
	{
		n4->data = 60;
		n4-> next = NULL;
	}
	n3 ->next = n4;
    //struct node*temp = (struct node*)malloc(sizeof(struct node));
	//temp= head;
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
		printf("\nThe elements are after concatenating are:");
     	while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = head1;
		temp = head;
		while(temp != NULL)
		{
			printf("%d  ",temp->data);
			temp = temp->next;
		}
	}
} 
