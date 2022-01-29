#include<stdio.h>
struct node
{
	int i;
	char c;
	int var1;
	int var2;
	struct node*ptr;
};
int main()
{
	int var;
	struct node var1;
	struct node var2;
	var1.i = 65;
	var1.c = 'a';
	var1.ptr = NULL;
	var2.i = 45;
	var2.c = 'b';
	var2.ptr = NULL;
	var1.ptr = &var2;
	printf("%d %c",var1.ptr->i,var1.ptr->c);
	return 0;
}
