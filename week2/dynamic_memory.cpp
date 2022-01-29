#include<stdio.h>
#include<stdlib.h>
struct student 
{
	char name[20];
	int rollnumber;
	char department[10];
	int marks;
};
int main()
{
	struct student *ptr;
	int i,n;
	printf("Enter the number of students\n");
	scanf("%d",&n);
	ptr = (struct student*)malloc(n*sizeof(struct student));
	if(ptr == NULL)
	{
		printf("Memory is not allocated\n");
		exit(0);
	}
	printf("Memory is allocated successfully\n");
	for(i=0;i<n;i++)
	{   
	    printf("Enter the student %d details\n",i+1);
		scanf("%s\n %d\n %s\n %d",&(ptr+i)->name,&(ptr+i)->rollnumber,&(ptr+i)->department,&(ptr+i)->marks);
	}
	printf("students details are:\n");
	for(i=0;i<n;i++)
	{
		printf("%s %d %s %d\n",(ptr+i)->name,(ptr+i)->rollnumber,(ptr+i)->department,(ptr+i)->marks);
	}
	return 0;
	
}
