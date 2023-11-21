#include<stdio.h>
#include<stdlib.h>
void DFS(int a[10][10], int m);
int main(){
	int a[10][10];
	int m;
	FILE *fp;
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
	printf("---Depth First Search---\n");
	for(int i=1 ; i<=m ; i++){
			for(int j=1 ; j<=m ; j++){
				printf(" %d ",a[i][j]);
			}
			printf("\n");
	}
	DFS(a,m);
}
void DFS(int a[10][10], int m){
	int S[10], d[10],x, t=0, k = 0; // S la mang stack, d la mang tham
	for(int i=1 ; i<=m ; i++){ 
		d[i] = 0;
	}
	printf("\nNhap vao phan tu dau tien: ");
	scanf("%d",&x);
	while(x>m){
		printf("Nhap sai, nhap lai!");
		printf("\nNhap vao phan tu dau tien: ");
		scanf("%d",&x);
	}
	S[0] = x;
	t++;
    while(t>0){
    	 k = S[t-1];
    	 t--; // Xoa k
    	if(d[k] == 0){ //Neu k chua duoc duyet 
    		printf(" %d ",k);
    		d[k] = -1; //Gan tru 1 coi nhu la da duyet qua 
    	}
    	//Tim ke cua k 
    	for(int i=m ; i>=1 ; i--){ 
    		if((a[i][k] != 0) && d[i]==0){ //Neu phan tu do da duoc duyet va dinh ke voi no chua duoc duyet thi dua dinh ke vao S
    			S[t] = i;
    			t++;
    		}
    	}
    }
}
