#include<stdio.h>
#include<stdlib.h>
void BacVoHuong(int a[10][10], int m);
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
	BacVoHuong(a,m);
}
void BacVoHuong(int a[10][10], int m){
	int x = 0, bac = 0;
	printf("\nNhap dinh can tinh bac: ");
	scanf("%d",&x);
		for(int j=1 ; j<=m ; j++){
			//Tinh bac khuyen
			if(x==j){
				if(a[x][j] != 0){
					bac = (a[x][j]*2)+1;
				} 
			}
			else{
				if(a[x][j] != 0){
					bac+=1;
				}
			}
				
		}
	printf("\nBac cua dinh %d = %d",x,bac);
}
