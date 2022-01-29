#include<stdio.h>
#include<stdlib.h>
void test();
void display_reverse();
struct node
{
	int data;
	struct node* next;
};
struct node* head = NULL;

int main()
{
	test();
    display_reverse();
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

void display_reverse()
{
	int i=0;
	int arr[100];
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct node*temp=(struct node*)malloc(sizeof(struct node));
		for(temp = head;temp != NULL;temp = temp->next)
		{
			i=i+1;
			arr[i]=temp ->data;
		}
	}
	int k;
	k=i;
	printf("\nThe elements in reverse order are:");
	for(i=k;i>0;i--)
	{
		printf("%d ",arr[i]);
	}
}
