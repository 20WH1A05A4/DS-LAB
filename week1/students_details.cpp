#include<stdio.h>
struct student
{
	int rollno;
	char name[10];
	int marks;
	char department[5];
}; 
int main()
{
	struct student s;
	int i;
	printf("Enter student details \n");
	for(i =0; i<2;i++)
	{
	  printf("enter student %d details:",i+1);
	  scanf("%d %s %d %s",&s.rollno,&s.name,&s.marks,&s.department);	
    }
	printf("The student details are\n");
	for(i =0; i<2;i++)
	{
      printf("Roll.no:%d\nName:%s\nMarks:%d\nDepartment:%s\n",s.rollno,s.name,s.marks,s.department);	
	}
	return 0;
}
