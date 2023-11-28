#include<stdio.h>
#include<stdlib.h>
#define vocung 1000;
int a[10][10], n, L[10], d[10], T[10], tam[10];
void KhoiTao(int s,int n);
int TimViTriMin(int n);
void CapNhatKe(int u);
void Dijkstra();
int main(){
	FILE *fp;
	fp = fopen("C:\\Testth4.txt","r");
	if(fp==NULL){
		printf("\nKhong tim thay tep!");
		exit(0);
	}
	else{
		fscanf(fp,"%d",&n);
		for(int i=1 ; i<=n ; i++){
			for(int j=1; j<=n ; j++){
				fscanf(fp,"%d",&a[i][j]);
			}
		}
		fclose(fp);
	}
	//Xuat mang:
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			printf(" %d ",a[i][j]);
		}
		printf("\n");
	}
	//Goi ham
	Dijkstra();
	
}
void KhoiTao(int s,int n){
	for(int i=1 ; i<=n; i++){
		L[i] = vocung;
		d[i] = 0;
	}
	L[s] = 0;
}

int TimViTriMin(int n){
	int min = 5000, vt;
	for(int i=1 ; i<=n  ; i++){
		if(L[i]<min && d[i]==0){
			min = L[i];
			vt = i;
		}
	}
	return vt;
}

void CapNhatKe(int u){
	for(int i=1 ; i<=n ; i++){
			if(a[u][i]!=0  && (d[i]==0)){
				if(L[i] > (L[u]+a[u][i])){
			    	L[i] = L[u] + a[u][i];
					T[i] = u;
			    }  
			}			
	}
	
	for(int i=1 ; i<=n ;i++){
		if(i==n){
			printf("%-6d|",L[i]);
		}
		else{
			printf("%-2d\t|",L[i]);
		}
	}
	
}

void TimDuong(int f){
	int i=1, dem=0, x;
	x = f;
	while(T[f] != 0){
		tam[i] = T[f];
		f = T[f];
		i++;
		dem++;
	}
	
	printf("\nDuong di ngan nhat co do dai: %d\n",L[x]);
	for(int i=dem; i>=1; i--){
		printf(" %d =>>",tam[i]);
	}
	printf(" %d ",x);
	
}
void Dijkstra(){
	printf("\nNhap dinh xuat phat: ");
	int s,u,f,lap=0;
	scanf("%d",&s);
	while(s<1 || s>8){
		printf("Khong ton tai dinh ban vua nhap, vui long nhap lai!");
		printf("\nNhap dinh bat dau: ");
		scanf("%d",&s);
	}
	KhoiTao(s,n);
	printf("+----------------------------------------------------------------------+\n");
	printf("|                       ******* DIJKSTRA *******                       |\n");
	printf("+----------------------------------------------------------------------+\n");
	printf("|     |dinh 1\t|dinh 2\t|dinh 3\t|dinh 4\t|dinh 5\t|dinh 6\t|dinh 7\t|dinh 8|\n");
	printf("+----------------------------------------------------------------------+");
	while(lap != n-1){
		printf("\n|Lap %d| ",(lap+1));
		u = TimViTriMin(n);
		CapNhatKe(u);
		d[u] = -1;
		lap++;
	}
	printf("\n+----------------------------------------------------------------------+\n");
	printf("Nhap dinh ket thuc: ");
	scanf("%d",&f);
	while(f>n||f<1){
		printf("Khong ton tai dinh ban vua nhap, vui long nhap lai!");
		printf("\nNhap dinh ket thuc: ");
		scanf("%d",&f);
	}
	while(f==s){
		printf("\nBan da nhap trung voi diem xuat phat!");
		printf("\nNhap dinh ket thuc: ");
		scanf("%d",&f);
	}
	TimDuong(f);	
}
