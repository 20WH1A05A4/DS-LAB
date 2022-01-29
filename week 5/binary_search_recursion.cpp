#include <stdio.h>
int binary_recursion(int a[10], int key, int low, int high);
int a[10], size, low, high, mid;
int main(int argc, char **argv)
{
	int key, i;
	printf("Enter the size of array\n");
	scanf("%d", &size);
	printf("Enter the elements into the array\n");
	for(i = 0; i < size; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Enter the element to be searched\n");
	scanf("%d", &key);
	int position = binary_recursion(a, key, 0, size - 1);
	if(position == -1)
	{
		printf("Element is not found\n");
	}
	else
	{
		printf("element %d is found at position %d\n", key, position);
	}
	return 0;
}
int binary_recursion(int a[10], int key, int low, int high)
{
	while(low <= high)
	{
		mid = (low+high) / 2;
		if(a[mid] == key)
		{
			return mid+1;
		}
		else if(a[mid] < key)
		{
			return binary_recursion(a, key, mid+1, size-1);
		}
		else
		{
			return binary_recursion(a, key, 0, mid-1);
		}
	}
	return -1;
}
