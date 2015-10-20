#include<conio.h>
#include<iostream>
using namespace std;
struct SetOrder{
	int key;
	int info;
	SetOrder *next;
};

SetOrder *MakeNode(int k,int x){
	SetOrder *q = new SetOrder;
	q->key = k;
	q->info = x;
	q->next = NULL;
	return q;
}
int Member(int k,SetOrder *s)
{
	SetOrder *p = s;
	while(p!=NULL && p->key < k)
	    p=p->next;
	if(p != NULL && p->key == k)
	    return 0;
	else
		return 1;
}
SetOrder * Insert(int k,int x,SetOrder *S)
{
	SetOrder *p = S,*lp = S;
	SetOrder *q = MakeNode(k,x);
	if(S== NULL || S->key > k){
		q->next = S;
		S = q;
	}else{
		while(p!=NULL && p->key < k){
			lp = p;
			p = p->next;
		}
		if(p!= NULL && p->key != k){
			q->next = p;
			lp->next=q;
		}
		if(p==NULL){
            q->next = p;
			lp->next=q;
		}
	}
	return S;
}
void output(SetOrder *s)
{
	SetOrder *p = s;
	while(p!=NULL){
		cout<<p->key<<endl;
		p=p->next;
	}
}
SetOrder * Union(SetOrder *s1,SetOrder *s2,SetOrder *s3)
{

	SetOrder *p;
	for(p = s1;p!= NULL;p=p->next)
	   s3 = Insert(p->key,p->info,s3);
	for(p = s2;p!= NULL;p=p->next){
		if(Member(p->key,s3)){
            s3 = Insert(p->key,p->info,s3);
		}
	}
	return s3;
}
int main()
{
	int n,k,x;
	SetOrder *u,*s1 = NULL,*s2 = NULL,*s3 = NULL;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>k;
		cin>>x;
		s1 = Insert(k,x,s1);
	}
	cout<<"--------------"<<endl;
	output(s1);
	cout<<endl<<"Nhap n ";
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>k;
		cin>>x;
		s2 = Insert(k,x,s2);
	}
	cout<<"--------------"<<endl;
	output(s2);
	u = Union(s1,s2,s3);
	cout<<"--------------"<<endl;
	output(u);
	getch();
}
