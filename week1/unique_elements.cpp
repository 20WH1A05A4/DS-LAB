#include<stdio.h>
int main()
{
	int arr[20];
	int size, i,count,j;
	printf("Enter the size of array\n");
	scanf("%d",&size);
	printf("Enter the elements into array\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<size;i++)
    {
        count = 0;
		for(j=0;j<size;j++)
		{	
		    	
			if(arr[i] == arr[j])
			{
			   count += 1;	
			}
		}
		if(count <= 1)
		{
			printf("%d\n",arr[i]);
	    } 
	    
    }
    return 0;
}
