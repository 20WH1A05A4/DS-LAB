#include <stdio.h>
int linear_search(int arr[20],int size,int key);
int main()
{
	int arr[20] ,size, i, key,position;
	printf("Enter the size of array \n");
	scanf("%d",&size);
	printf("enter the elements into array\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter the key to be searched\n");
	scanf("%d",&key);
	position = linear_search(arr,size,key);
	if(position == -1)
	{
		printf("Element is not found\n");
	}
	else
	{
		printf("element %d is found at position %d\n",key,position);
	}
	return 0;
}
int linear_search(int arr[20],int size,int key)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arr[i] == key)
		
			return i+1;
		
	}
	return -1;
}
