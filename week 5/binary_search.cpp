#include<stdio.h>
int binary_search(int arr[20],int low,int high,int key);
int main()
{
	int arr[20],size,i,key,position;
	printf("Enter the size of array\n");
	scanf("%d",&size);
	printf("Enter the values into array\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be searched\n");
	scanf("%d",&key);
	position = binary_search(arr,0,size-1,key);
	if(position == -1)
	{
		printf("Element is not found\n");
	}
	else
	{
		printf("Element %d is found at position %d\n ",key,position);
	}
	return 0;
}
int binary_search(int arr[20],int low,int high,int key)
{
	while(low<= high)
	{
		int mid = (low+high)/2;
		if(arr[mid] == key)
		{
			return mid +1;
		}
		else if(arr[mid] <key)
		{
			low = mid +1;
		}
		else
		{
			high = mid - 1;
		}
		return -1;
	}
}
