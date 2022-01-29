#include<stdio.h>
void bubblesort(int arr[20],int size);
int main()
{
	int arr[20];
	int size,i;
	printf("Enter the size of array\n");
	scanf("%d",&size);
	printf("Enter the elements into array\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	bubblesort(arr,size);
	return 0;	
}
void bubblesort(int arr[20],int size)
{
	int i,j;
	int pass,temp;
	for(pass=0;pass < size;pass++)
	{
		printf("The elements after pass %d are:\n",pass);
		for(i=0;i<size-1;i++)
		{
			if(arr[i] >arr[i+1])
			{
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1]= temp;
			}
			for(j=0;j<size;j++)
			{
				printf("%d ",arr[j]);
			}
			printf("\n");
	     }
    }

}
