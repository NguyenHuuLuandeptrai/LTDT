#include<stdio.h>
#include<stdlib.h>
void BFS(int a[10][10], int m);
int main(){
	int a[10][10];
	int m;
	FILE *fp;
	fp = fopen("C:\\Test.txt","r");
	if(fp == NULL){
		printf("\nKhong ton tai file!");
		exit(0);
	}
	else{
		fscanf(fp,"%d",&m);
		for(int i=1 ; i<=m ; i++){
			for(int j=1 ; j<=m ; j++){
				fscanf(fp,"%d",&a[i][j]);
			}
		}
		fclose(fp);
	}
	printf("---Breadth Frist Search---\n");
	for(int i=1 ; i<=m ; i++){
		for(int j=1 ; j<=m ; j++){
			printf(" %d ",a[i][j]);
		}
		printf("\n");
	}
	fclose(fp);
	
	BFS(a,m);
}
void BFS(int a[10][10], int m){
	int T[10], t = 0, v = 0, x=0 , d[10];
	for(int i = 1 ; i<=m ; i++){
		d[i] = 0; 
	}
	printf("\nNhap vao phan tu dau tien: ");
	scanf("%d",&v);
	while(v>m){
		printf("Nhap sai, nhap lai!");
		printf("\nNhap vao phan tu dau tien: ");
		scanf("%d",&v);
	}
	T[0] = v;
	t++;
	d[v] = -1;
	
	while(t>0){
		x = T[0];
		printf(" %d ",x);
		for(int i=0 ; i<m ; i++){
			T[i] = T[i+1];
		}
		t--;
		//Tim ke cua x:
		for(int i = 1 ; i<=m ; i++){
			if((a[i][x] != 0) && d[i]==0){
				T[t] = i;
				d[i] = -1;
				t++;
			}
		}
	}
}
