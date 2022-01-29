#include <stdio.h>
int linear_recursion(int key, int i);
int a[10], size;

int main(int argc, char **argv)
{
	int key;
	printf("Enter the size of array\n");
	scanf("%d", &size);
	int i;
	printf("Enter the elements into the array\n");
	for(i = 0; i < size; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Enter the element to be searched\n");
	scanf("%d", &key);
	int position = linear_recursion(key, 0);
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
int linear_recursion(int key, int i)
{
	if(i == size)
	{
		return -1;
	}
	else if(a[i] == key)
	{
		return i+1;
	}
	else
	{
		return linear_recursion(key, i+1);
	}
}
