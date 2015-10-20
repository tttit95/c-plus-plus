#include<conio.h>
#include<stdio.h>
#include<malloc.h>
//code tren congdongcviet
typedef int ElementType;
typedef struct Node{
   ElementType Element;
   Node*Next;
};

typedef Node* Set;

Set MakeNullSet(){
   Node* S=(Node*)malloc(sizeof(Node));
   S->Next=NULL;
   return S;
}

Node*Make_Node(ElementType X){
   Node* P=(Node*)malloc(sizeof(Node));
   P->Element=X;
   P->Next=NULL;
   return P;
}

char Empty_Set(Set S){
   return S->Next==NULL;
}

int Check(ElementType X,Set S){
   Set temp=S;
   while(!Empty_Set(temp)){
      if(temp->Element == X)
         return 1;
      else
         temp=temp->Next;
   }
   return 0;
}

void InsertSet(ElementType X,Set S){
   Node *P=Make_Node(X);
   if(Check(X,S)==0){
      P->Next=S->Next;
      S->Next=P;
   }
}

void Union(Set A,Set B,Set &C){
   Set temp1,temp2;
   temp1=A->Next;
   temp2=B->Next;
   while(temp1!=NULL){
      InsertSet(temp1->Element,C);
      temp1=temp1->Next;
   }
   while(temp2!=NULL){
      InsertSet(temp2->Element,C);
      temp2=temp2->Next;
   }
}

void Intersection(Set A,Set B,Set &C){
   Set temp=A->Next;
   while(temp!=NULL){
      if(Check(temp->Element,B)==1)
         InsertSet(temp->Element,C);
      temp=temp->Next;
   }
}

void Difference(Set A,Set B,Set &C){
   Set temp=A->Next;
   while(temp!=NULL){
      if(Check(temp->Element,B)==0)
         InsertSet(temp->Element,C);
      temp=temp->Next;
   }
}

Set Input(){
   Set S=MakeNullSet();
   ElementType X;
   printf("\nNhap -1 de ket thuc\n");
   do{
      scanf("%d",&X);
      if(X!=-1)
         InsertSet(X,S);
   }while(X!=-1);
   return S;
}
void Bubble_Sort(Set L) {
	for(Set i= L->Next; i!=NULL; i=i->Next)
		for(Set j=i->Next; j!=NULL; j=j->Next)
			if(i->Element>j->Element)
			{
				ElementType temp = i->Element;
				i->Element = j->Element;
				j->Element = temp;
			}
}

void Output(Set S){
   Set temp=S;
   while(!Empty_Set(temp)){
      printf("%3d",temp->Next->Element);
      temp=temp->Next;
   }
}

int main(){
   //clrscr();
   Set A,B,C;
   C = MakeNullSet();
   printf("\nNhap tap hop A");
   A = Input();
	Bubble_Sort(A);
   Output(A);

   printf("\nNhap tap hop B");
   B = Input();
   Bubble_Sort(B);
   Output(B);

   printf("\nHop cua hai tap hop A va B:");
   Union(A,B,C);
   Bubble_Sort(C);
   Output(C);

   printf("\nGiao cua hai tap hop A va B:");
   C = MakeNullSet();
   Intersection(A,B,C);
   Output(C);

   printf("\nA\\B:");
   C = MakeNullSet();
   Difference(A,B,C);
   Output(C);
   printf("\n");
   getch();
}
