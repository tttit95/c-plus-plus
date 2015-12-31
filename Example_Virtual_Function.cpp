#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
class NhanVien{
		char hoten[50];
		char maso[10];
	public:
		NhanVien(char ht[],char ms[]){
			strcpy(hoten,ht);
			strcpy(maso,ms);
		}
		void xuat(){
			cout<<"Ho Ten: "<<this->hoten<<endl;
		}
		virtual float luong(){
			return 0;
		}
};
class NV_BienChe : public NhanVien
{
		float mucluong;
	public:
		NV_BienChe(float ml,char hoten[],char ms[]):NhanVien(hoten,ms){
			mucluong = ml;
		}
		 float luong(){
			return mucluong = (mucluong - mucluong * 80 )/100;
		}
};
class NV_ThoiVu : public NhanVien
{
		int g;
		int tc;
	public:
		NV_ThoiVu(int gio,int tiencong,char hoten[],char ms[]): NhanVien(hoten,ms){
			g = gio;
			tc = tiencong;
		}
		 float luong(){
			if(g <= 40){
				return (g*tc);
			}else{
				return (g*1.5*tc);
			}
		}
};

int main()
{
	NhanVien *nv[50];
	int n,mucluong,tc,select,sogio;
	char hoten[50],maso[10];
	cout<<"Nhap vao so nhan vien : ";
	cin>>n;
	for(int i = 0;i<n;i++ )
	{
		fflush(stdin);
		cout<<"Muon Them Nhan Vien Nao 1: Nhan Vien Ben Che 2: Nhan Vien Thoi Vu";
		cin>>select;
		switch(select)
		{
			case 1:
			{
                cout<<"Nhap vao muc luong ";
				cin>>mucluong;
				fflush(stdin);
				cout<<"Ho Ten";
				gets(hoten);
				fflush(stdin);
				cout<<"Nhap Ma So";
				gets(maso);
				nv[i] = new NV_BienChe(mucluong,hoten,maso);

				break;
			}
			case 2:
			{
                cout<<"Nhap vao tien cong ";
				cin>>tc;
				cout<<"Nhap vao so gio lam viec";
				cin>>sogio;
				fflush(stdin);
				cout<<"Ho Ten";
				gets(hoten);
				fflush(stdin);
				cout<<"Nhap vao ma so";
				gets(maso);
				nv[i] = new NV_ThoiVu(sogio,tc,hoten,maso);
				break;
			}
		}
		
	}
	for(int i = 0;i<n;i++){
		cout<<nv[i]->luong();
	}
	getch();
}
