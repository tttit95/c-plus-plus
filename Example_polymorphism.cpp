#include <conio.h>
#include <stdio.h>
#include <string.h>
class NhanVien
{
private:
	char hoten[50];
	char masothue[30];
public:
	//them 2 ham nay
	void setName(char ht[50]){
		strcpy(this->hoten,ht);
	}
	void setMaSoThue(char ms[30]){
		strcpy(this->masothue,ms);
	}
	char *getHoTen()
	{
		return this->hoten;
	}
	char *getMaSoThue()
	{
		return this->masothue;
	}
	virtual  void Nhap()
	{
		printf(" Day la Ham Ao");
	}
	virtual void hienthi()
	{
		printf("\nHo ten nhan vien: %s \nMa so thue: %s",this->hoten,this->masothue);
	}
	virtual float Luong()
	{
		return 0;
	}
};
class NVBienChe :public NhanVien
{
private:
	float MucLuong;
	public:
		float getMucluong()
		{
			return this->MucLuong;
		}
		void Nhap()
		{
			//them cho nay
			char ht[50];
			char ms[30];
			printf("Nhap ho ten :");
			fflush(stdin);
			gets(ht);
			setName(ht);
			printf("Nhap ma so thue:");
			fflush(stdin);
			gets(ms);
			setMaSoThue(ms);
			printf("Nhap muc luong :");
			scanf("%f",&this->MucLuong);
		}
		void hienthi()
		{
            printf("\nHo ten nhan vien: %s \nMa so thue: %s",getHoTen(),getMaSoThue());
			printf("Muc luong: %d",this->MucLuong);
		}
		float Luong()
		{
			return this->MucLuong=(this->MucLuong -(this->MucLuong*8/100));
		}
};
class NVThoiVu :public NhanVien
{
	int sogiolv;
	int Tiencong;
	public:
		int getTienCong()
		{
			return this->Tiencong;
		}
		int getSogiolv()
		{
			return this->sogiolv;
		}
		void Nhap()
		{
            //them cho nay
			char ht[50];
			char ms[30];
			printf("Nhap ho ten :");
			fflush(stdin);
			gets(ht);
			setName(ht);
			printf("Nhap ma so thue:");
			fflush(stdin);
			gets(ms);
			setMaSoThue(ms);
			printf("Nhap so gio lam viec:");
			scanf("%d",&this->sogiolv);
			printf("Nhap tien cong lam cho 1 gio:");
			scanf("%d",&this->Tiencong);
		}
		void hienthi()
		{
            printf("\nHo ten nhan vien: %s \nMa so thue: %s",getHoTen(),getMaSoThue());
			printf("So gio lam viec: %d",this->sogiolv);
			printf("Tien cong: %d",this->Tiencong);
		}
		float Luong()
		{
			if(this->sogiolv <= 40)
				return(this->sogiolv*this->Tiencong);
			else
				return (this->sogiolv*1.5*this->Tiencong);
		}
};
int main()
{
	NhanVien *nv[50];
	int i,sl;
	printf("Nhap vao so luong nhan vien:");
	scanf("%d",&sl);
	for(i=0;i<sl;i++)
	{
		char luachon;
		printf("Nhap vao NV [B]ien che hay NV [T]hoi vu:");
		fflush(stdin);
		scanf("%c",&luachon);
		if(luachon == 'B'|| luachon == 'b')
		{
			nv[i]=new NVBienChe;
			nv[i]->Nhap();
		}
		else
		{
			nv[i]=new NVThoiVu;
			nv[i]->Nhap();
		}
	}
	printf("\nDanh sach nhan vien va luong la:");
	for (i=0;i<sl;i++)
	{
		printf("-----------------------\n");
		nv[i]->hienthi();
		printf("%f",nv[i]->Luong());
	}
	getch();
}