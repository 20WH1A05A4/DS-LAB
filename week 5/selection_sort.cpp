#include <stdio.h>
void selectionsort(int arr[10], int size);
int  main()
{
	int arr[10];
	int size, i;
	printf("Enter the size of array\n");
	scanf("%d", &size);
	printf("Enter the array values\n");
	for(i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	selectionsort(arr,size); 
	printf("Array values after sorting are\n");
	for(i = 0; i < size; i++)
		printf("%d ", arr[i]);
	return 0;
}
void selectionsort(int arr[10], int size)
{
	int i,j,k;
	int min_index;
	for( i = 0; i < size - 1; i++)
	{
		printf("Elements after pass %d are:\n", i);
		min_index = i;
		for(j = i+1; j < size ; j++)
		{
			if(arr[j] < arr[min_index])
			{
				min_index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
		
		for(k =0; k < size; k++)
			printf("%d ", arr[k]);
		printf("\n");
	}
	
	
}
