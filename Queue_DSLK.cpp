#include<iostream>
#include<conio.h>
#include<malloc.h>
using namespace std;
struct Queue
{
	int x;
	Queue *next;
	Queue *prev;
};

Queue *FIRST = NULL;
Queue *LAST = NULL;

int isEmpty()
{
	return (FIRST==NULL);
}

Queue *MakeNode(int x)
{
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->x=x;
	q->next=NULL;
	q->prev = NULL;
}
Queue *EnQueue(int x)
{
	Queue *q = MakeNode(x);
	q->next=LAST;
	LAST->prev = q;
	LAST = q;
}
void DeQueue()
{
	Queue *q;
	q = FIRST;
	FIRST = FIRST->prev;
	FIRST->next = NULL;
	free (q);
}
void inXuoi()
{
	Queue *i;
	for(i = FIRST;i!= NULL;i=i->prev)
	    cout<<i->x<<endl;
}
void inNguoc()
{
	Queue *i;
	for(i = LAST;i!= NULL;i=i->next)
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
			FIRST = MakeNode(x);
			LAST = FIRST;
		}else{
			EnQueue(x);
		}

	}
	DeQueue();
	inXuoi();
	cout<<"----------------\n";
	inNguoc();
	getch();
}

