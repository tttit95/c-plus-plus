#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
void ChuyenDoi(float so, int k){
    char chuso[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    FILE *f;
	int a;
	char mang1[100],mang2[11];
	int i = 0,j = 0;
	float b;
	//lay phan nguyen
	a = (int)so;
	//lay phan thap phan
	b = so - a;
	//chuyen doi phan nguyen

	while(a > 0)
	{
		int tam;
		mang1[i] = chuso[a % k];
		a = a / k;
		i++;
	}
	//chuyen doi phan thap phan
	while(j!=10)
	{
		b = b * k;
		mang2[j] = chuso[(int)b];
		b = b - (int)b;
		j++;
	}
	cout<<"Ket Qua Chuyen So "<<so<<" Sang He Co So "<<k<<" La : ";
	for(int m = 0;m<i;m++)
	{
		cout<<mang1[m];
	}
	cout<<".";
	for(int m = 0;m<j;m++)
	{
		cout<<mang2[m];
	}
	//ghi ket qua vao file
	f=fopen("ketqua.txt","wt");
	fprintf(f,"%s","Ket Qua: ");
    for(int m = 0;m<i;m++)
        fprintf(f,"%c",mang1[m]);
    fprintf(f,"%c",'.');
    for(int m = 0;m<j;m++)
        fprintf(f,"%c",mang2[m]);
    fclose(f);
	
	
}
main()
{
	float so;
	int coso;
	cout<<"Nhap vao so can chuyen doi : ";
	cin>>so;
	cout<<"Nhap vao he co so can chuyen doi : ";
	cin>>coso;
	ChuyenDoi(so,coso);
	getch();
}
