#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
using namespace std;
struct DL{
	char tenDL[100];
	char sdt[];
	float doanhthu;
	DL *tiep;
};
struct TP{
	char tenTP[100];
	TP *tptiep;
	DL *troDL;
};
int MemberDL(char tendl[],DL *dl)
{
	DL *p = dl;
	while(p!=NULL && (strcmp(p->tenDL,tendl)!= 0))
	    p = p->tiep;
	    if(p!=NULL)
	        return 1;
		else
		    return 0;
}
int MemberTP(char tentp[],TP *tp)
{
	TP *p = tp;
	while(p!=NULL && (strcmp(p->tenTP,tentp)!= 0))
	    p = p->tptiep;
	    if(p!=NULL)
	        return 1;
		else
		    return 0;
}
TP *getTP(char tentp[],TP *tp)
{
	TP *p = tp;
	while(p!=NULL && strcmp(p->tenTP,tentp)!=0)
		p=p->tptiep;
	return p;
}
TP *MakeTP(char tentp[])
{
	TP *q = new TP;
	strcpy(q->tenTP,tentp);
	q->tptiep = NULL;
	q->troDL = NULL;
	return q;
}
DL *MakeDL(char tendl[],char sdt[],float dt)
{
	DL *q = new DL;
	strcpy(q->tenDL,tendl);
	strcpy(q->sdt,sdt);
	q->doanhthu = dt;
	q->tiep = NULL;
	return q;
}
TP *InsertTP(char tentp[],TP *tp)
{
	TP *q = MakeTP(tentp);
	TP *p = tp,*lp = tp;
	if(tp == NULL || (strcmp(tp->tenTP,tentp) == 1) )
	{
		q->tptiep = tp;
		tp = q;
	}else{
		while(p!= NULL && (strcmp(p->tenTP,tentp) == -1))
		{
			lp = p;
			p = p ->tptiep;
		}
		if(p!=NULL && (strcmp(p->tenTP,tentp)!=0) || p == NULL)
		{
			q->tptiep = p;
			lp->tptiep = q;
		}
	}
	return tp;
}
DL *InsertDL(char tendl[],char sdt[],float dt,TP *tp)
{
	DL *q = MakeDL(tendl,sdt,dt);
	DL *p = tp->troDL;
	if(!MemberDL(tendl,p))
	{
        if(tp->troDL == NULL)
		{
			tp->troDL = q;
		}else{
			while(p->tiep!=NULL)
			{
				p=p->tiep;
			}
			p->tiep = q;
		}
	}
	
	return tp->troDL;
}
void showTP(TP *tp)
{
	TP *p = tp;
	while(p!=NULL){
		cout<<p->tenTP<<endl;
		p = p->tptiep;
	}
}
void showDL(DL *dl)
{
	DL *p = dl;
	while(p!=NULL){
		cout<<p->tenDL<<endl;
		p = p->tiep;
	}
}
void output(TP*tp,DL *dl)
{
	TP *p1 = tp;
	DL *p2 = NULL;
	while(p1 != NULL)
	{
		cout<<p1->tenTP<<endl;
		p2 = p1->troDL;
		while(p2!= NULL)
		{
			cout<<"----"<<p2->tenDL<<endl;
			p2 = p2->tiep;
		}
		p1 = p1->tptiep;
	}
}
float DoanhThu(char tentp[],TP *tp)
{
	TP *p1 = tp;
	DL *p2 = NULL;
	int dt = 0;
	if(MemberTP(tentp,tp))
	{
		while(p1!=NULL && strcmp(p1->tenTP,tentp)!= 0)
		{
			p1=p1->tptiep;
		}
        if(p1!= NULL)
        {
			p2 = p1->troDL;
			while(p2 != NULL)
			{
				dt = dt + p2->doanhthu;
				p2 = p2->tiep;
			}
        }
		return dt;
	}
	return 0;
}
void xoaDL(TP *tp,char tendl[],char tentp[])
{
    TP *p1 = tp;
	if(MemberTP(tentp,tp))
	{
        while(p1!=NULL && strcmp(p1->tenTP,tentp)!= 0)
		{
			p1=p1->tptiep;
		}
	}
}
int main()
{
	char str[100],sdt[11];
	int dt;
	TP *tp = NULL,*s=NULL;
	DL *dl = NULL;
	for(int i = 0;i<3;i++){
		gets(str);
		tp = InsertTP(str,tp);
	}
	cout<<"--------"<<endl;
	showTP(tp);
	fflush(stdin);
	
	do{
        cout<<"Nhap ten thanh pho can nhap dl"<<endl;
        gets(str);
	}while(!MemberTP(str,tp));
	
	s = getTP(str,tp);
	
	for(int i = 0;i<3;i++){
        fflush(stdin);
		gets(str);
		fflush(stdin);
		gets(sdt);
		fflush(stdin);
		cin>>dt;
		dl = InsertDL(str,sdt,dt,s);

	}
	cout<<"--------"<<endl;
	output(tp,dl);
	fflush(stdin);
	gets(str);

	cout<<DoanhThu(str,tp);

	getch();
}



