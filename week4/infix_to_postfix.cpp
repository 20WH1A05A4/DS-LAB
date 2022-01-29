#include<stdio.h>
#include<string.h>
#include<conio.h>
#define MAX 20
char stack[MAX];
int top=-1;
char pop(void);  /*declaration of  pop function*/
void push(char item); /*declaration of  push function*/
int prcd(char symbol)  /*checking the precedence*/
{
   switch(symbol) /*assigning values for symbols*/
   {
        case '+':
        case '-': return 2;
					 break;
		case '*':
		case '/': return 4;
					 break;
		case '^': return 6;
					 break;
		case '(':
		case ')':
		case '#': return 1;
					 break;
  }
  //return;
}
int isoperator(char symbol)  /*assigning  operators*/
{
   switch(symbol)
   {
       case '+':
       case '*':
       case '-':
	   case '/':
       case '^':
       case '%':
       case '(':
       case ')':return 1;
					 break;
	   default:return 0;
	}
 }
/*converting infix to postfix*/
void convertip(char infix[],char postfix[])
{
	int i,symbol,l,j=0;
	stack[++top]='#';
   l=strlen(infix);
	for(i=0;i<l;i++)
	{
	  symbol=infix[i];
	  if(isoperator(symbol)==0)
	  {
			postfix[j]=symbol;
			j++;
	  }
	  else
	  {
			if(symbol=='(')
			push(symbol); /*function call  for pushing elements into the stack*/
			else if(symbol==')')
			{
				while(stack[top]!='(')
				{
				  postfix[j]=pop();
				  j++;
				}
				pop();  /*function call  for popping elements into the stack*/
			}
			else
			{
			  if(prcd(symbol)>prcd(stack[top]))
			  push(symbol);
			  else
			  {
					while(prcd(symbol)<=prcd(stack[top]))
					{
					 postfix[j]=pop();
					 j++;
					}
					push(symbol);
			  }/*end of else */
			}/*end of else */
		} /*end of else */
	}/*end of for loop*/
	while(stack[top]!='#')
	{
		postfix[j]=pop();
		j++;
	}
	postfix[j]='\0'; /*null terminate string*/
 }
/*main program*/
int main()
 {
	  char infix[20],postfix[20];
      printf("enter the valid infix string \n");
      gets(infix);
      convertip(infix,postfix);    /*function call   for converting infix to postfix */
      printf("the corresponding postfix string is:\n");
      puts(postfix);
      getch();
  }
/*push operation*/
void push(char item)
{
    top++;
    stack[top]=item;
 }
/*pop operation*/
char pop()
{
    char a;
    a=stack[top];
    top--;
    return a;
 }
