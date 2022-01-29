#include<stdio.h>
int stack[100],choice,size,top,x,i;
void push();
void pop();
void display();
int main()
{
	top = -1;
	printf("Enter the size of stack(max = 100):\n");
	scanf("%d",&size);
	printf("\tSTACK OPERATIONS USING ARRAY\n");
	printf("\t _________________\n");
	printf("\t1.PUSH\n\t2.POP\n\t3.DISPLAY\n\t4.EXIT\n");
	do
	{
		printf("Enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					push();
					break;
				}
			case 2:
			{
				pop();
				break;
				}	
			case 3:
			{
				display();
				break;
				}	
			case 4:
			{
				printf("\t EXIT POINT\n");
				break;
				}	
			default:
			{
				printf("\tPlease enter the valid choice (1/2/3/4)\n");
				break;
				}	
				
		}
	}
	while(choice != 4);
	return 0;
	
}
void push()
{
	if(top == size -1)
	{
		printf("STACK OVERFLOW\n");
	}
	else
	{
		printf("Enter the value to be pushed\n");
		scanf("%d",&x);
		top++;
		stack[top] = x;
	}
}
void pop()
{
	if(top == -1)
	{
		printf("STACK UNDERFLOW\n");
	}
	else
	{
		printf("The popped element is %d\n",stack[top]);
		top--;
	}
}
void display()
{
	if(top >= 0)
	{
		printf("The elements in STACK are:\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
		printf("Press next choice\n");
	}
	else
	{
		printf("The STACK is empty\n");
	}

}
