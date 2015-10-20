#include<iostream>
#include<conio.h>
#include<malloc.h>
using namespace std;
struct Stack
{
	int x;
	Stack *next;
};
Stack *F = NULL;
int isEmpty()
{
	return (F == NULL);
}
Stack *MakeNode(int x)
{
	Stack *p;
	p = (Stack *)malloc(sizeof(Stack));
	p->x = x;
	p->next = NULL;
	return p;
}
Stack Push(int x)
{
	Stack *s = MakeNode(x);
	s->next = F;
	F = s;
}
Stack Pop()
{
	Stack *p;
	p = F;
	F = F->next;
	free (p);
}
void in()
{
	Stack *i;
	for(i = F;i!= NULL;i=i->next)
	    cout<<i->x<<endl;
}
int main()
{
	int x;
	while(1)
	{
		cin>>x;
		if(x==0)
		    break;
		if(isEmpty())
		{
			F = MakeNode(x);
		}else{
			Push(x);
		}
		
	}
	Pop();
	in();
	getch();
}
