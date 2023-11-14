#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void BacVoHuong(int a[10][10], int m);
void BacCoHuong(int a[10][10], int m);
bool KtrDoThi(int a[10][10], int m);
int main(){
	FILE *fp;
	int m, a[10][10];
	fp = fopen("C:\\Test.txt","r");
	if(fp == NULL){
		printf("\nKhong tim thay tap tin!");
		exit(0);
	}
	else{
		fscanf(fp,"%d",&m);
		for(int i=1 ; i<=m ; i++){
			for(int j=1 ; j<=m ; j++){
				fscanf(fp,"%d",&a[i][j]);
			}
		}
	}
	fclose(fp);
	for(int i=1 ; i<=m ; i++){
			for(int j=1 ; j<=m ; j++){
				printf(" %d ",a[i][j]);
			}
			printf("\n");
	}
	if(KtrDoThi(a,m)==true){
		printf("\nDay la do thi vo huong!");
		printf("\nAn phim bat ki de tinh tong bac dinh nhap tu ban phim!");
		getch();
		BacVoHuong(a,m);
	}
	else{
		printf("\nDay la do thi co huong!");
		printf("\nAn phim bat ki de tinh tong bac dinh nhap tu ban phim!");
		getch();
		BacCoHuong(a,m);
	}
	
}
void BacVoHuong(int a[10][10], int m){
	int x = 0, bac = 0;
	printf("\nNhap dinh can tinh bac: ");
	scanf("%d",&x);
		for(int j=1 ; j<=m ; j++){
			//Tinh bac khuyen
			if(x==j && a[x][j]!=0){
				bac = (a[x][j]*2);
			}
		}
		for(int j=1 ; j<=m ; j++){
			if(x!=j && a[x][j] != 0 ){
				bac +=a[x][j];
			}
		}
	printf("\nBac cua dinh %d = %d",x,bac);
}

void BacCoHuong(int a[10][10], int m){
	int x = 0, degin = 0, degout = 0;
	printf("\nNhap vao dinh can tinh bac: ");
	scanf("%d",&x);
	//tinh bac vao: 
	for(int i=1 ; i<=m ; i++){
		if(a[i][x] != 0){
			degin += a[i][x];
		}
	}
	//tinh bac ra: 
	for(int j=1 ; j<=m ; j++){
		if(a[x][j] != 0){
			degout += a[x][j];
		}
	}
	//Xuat ra ket qua sau khi tinh
	printf("\nTong bac vao cua dinh %d la: %d",x,degin);
	printf("\nTong bac ra cua dinh %d la: %d",x,degout);
}
bool KtrDoThi(int a[10][10], int m){
	for(int i=1 ; i<=m ; i++){
		for(int j=1 ; j<=m ; j++){
			if(a[i][j] != a[j][i]){
				return false;
			}
		}
	}
	return true;
}
