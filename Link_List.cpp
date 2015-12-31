#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
using namespace std;
class NhanVien{
	private:
		char *manv;
		char *tennv;
		int sdt;
	public:
        NhanVien *next;
        NhanVien(){
            manv = new char[11];
			tennv = new char[50];
			strcpy(this->manv,"");
			strcpy(this->tennv,"");
			this->sdt = 0;
			this->next = NULL;
        }
		NhanVien(char mnv[],char tnv[],int sdt){
			manv = new char[11];
			tennv = new char[50];
			strcpy(this->manv,mnv);
			strcpy(this->tennv,tnv);
			this->sdt = sdt;
			this->next = NULL;
		}
		char *getManv(){
			return this->manv;
		}
		char *getTenNV(){
			return this->tennv;
		}
		int getSdt(){
			return this->sdt;
		}
		
};
class DanhBa
{
	private:
        char mnv[11];
		char tnv[50];
		int sdt;
		NhanVien *q,*p;
		NhanVien *first;
	public:
        DanhBa(){
			this->first=NULL;
		}
		void TaoDanhBa(){
  		 	do{
                fflush(stdin);
                cout<<"Nhap Ma Sinh Vien: ";
				gets(mnv);
				if(strcmp(mnv,"")==0){
					break;
				}
				fflush(stdin);
				cout<<"Nhap Ho Ten Sinh Vien: ";
				gets(tnv);
				fflush(stdin);
				cout<<"Nhap So Dien Thoai: ";
				cin>>sdt;
    			q = new NhanVien(mnv,tnv,sdt);
				if(this->first == NULL){
					this->first = q;
				}else{
					p = this->first;
					while(p->next!=NULL){
						p=p->next;
					}
					p->next=q;
				}
			}while(strcmp(mnv,"")!=0);
		}
		void inDanhBa(){
			NhanVien *p;
			p = this->first;
			while(p!=NULL){
				cout<<"Ma Nhan Vien: "<<p->getManv();
				cout<<"Ho Ten Nhan Vien: "<<p->getTenNV();
				cout<<"So Dien Thoai: "<<p->getSdt();
				cout<<endl;
				p=p->next;
			}
		}
		void SapXep(){
			
			NhanVien *p,*q;
			for(p = this->first;p!=NULL;p=p->next)
			{
				for(q = p->next;q!=NULL;q=q->next)
				{
					
					if(strcmpi(p->getManv(),q->getManv())>0)
					{
						NhanVien tam,*temp;
						temp = p->next;
						p->next = q->next;
						q->next = temp;
						tam = *p;
						*p = *q;
						*q = tam;
					}
				}
			}
		}
};
int main(){
	DanhBa db;
	db.TaoDanhBa();
	db.SapXep();
	db.inDanhBa();
	getch();
}
