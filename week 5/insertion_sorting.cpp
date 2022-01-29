#include <stdio.h>
void insertionsort(int arr[10], int size);
int  main()
{
	int arr[10];
	int size, i;
	printf("Enter the size of array\n");
	scanf("%d", &size);
	printf("Enter the array values\n");
	for(i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	insertionsort(arr,size); 
	return 0;
}

void insertionsort(int arr[10], int size)
{
	int i, j, k, l = 1;
	int temp;
	for( i = 1; i < size ; i++)
	{
		temp = arr[i];
		for( j = i ; j > 0 && temp < arr[j - 1]; j--) 
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
		printf("the elements after iteration %d are:", l++);
		for(k = 0; k < size; k++)
			printf("%d ", arr[k]);
		printf("\n");
	}
}
