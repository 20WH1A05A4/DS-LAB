#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
int queue[100],size,front=-1,rear=-1,i,choice,x;
int main()
{
	printf("Enter the size of stack(max = 100)\n");
	scanf("%d",&size);
	printf("\tQUEUE USING ARRAY \n");
	printf("\t1.Insertion\n\t2.Deletion\n\t3.Display\n\t4.Exit\n");
	//printf("Enter the choice\n");
	//scanf("%d",&choice);
    do
	{
		printf("Enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					enqueue();
					break;
				}
			case 2:
				{
					dequeue();
					break;
				}
			case 3:
		     	{
				    display();
					break;
		        }
		    
		    case 4:
		    	{
		    		printf("EXIT\n");
		    		break;
				}
			default:
			{
				printf("Enter the valid choice\n");
				break;
				}	
				
		}
		
	}while(choice!=4);
	return 0;
}
void enqueue()
{
	if(rear == size-1)
	{
		printf("queue is full\n");
	}
	else if(front == -1 && rear == -1)
	{
			front = 0;
			rear = 0; 
			printf("enter the element\n");
			scanf("%d",&x);
			queue[rear] =x;
	}
	else
	{
		printf("enter the element\n");
		scanf("%d",&x);
		rear++;
		queue[rear] = x;
    }
	
}
void dequeue()
{
	if(front == -1 && rear == -1)
	{
		printf("queue is empty\n");
	}
	else 
	{  
	    printf("deleted element is:%d\n",queue[front]);
	    front++;
    }
}
void display()
{
	if(front == -1)
	{
		printf("queue is empty\n");
	}
	else
	{
		printf("The queue elements are:\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",queue[i]);
		}
	}
}
