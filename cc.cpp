#include<stdio.h>
#include<stdlib.h>
#define vc 5000
int a[10][10], n, L[10], T[10],d[10],tam[10];
FILE *fp;
void DocFILE(FILE *fp, int a[10][10], int &n);
void DinhTreo(int a[10][10], int n);
void BFS(int a[10][10], int n);
void DFS(int a[10][10], int n);
void Dijkstra();
void KhoiTao(int s, int n);
int TimViTriMin(int n);
void CapNhatKe(int u);
void TimDuong(int f);
int main(){
	fp = fopen("D:\\DinhTreo.txt","r");
	if(fp == NULL){
		printf("\nTap tin khong ton tai");
	    exit(0);
	}
	DocFILE(fp,a,n);
	fclose(fp);
	/*DinhTreo(a,n);
	printf("\nDFS: ");
	DFS(a,n);
	printf("\nBFS: ");
	BFS(a,n);*/
	Dijkstra();
}
void DocFILE(FILE *fp, int a[10][10], int &n){
	fscanf(fp,"%d",&n);
	for(int i=1 ;i<=n ;i++){
		for(int j=1 ;j<=n ;j++){
			fscanf(fp,"%d",&a[i][j]);
		}
	}
	
	for(int i=1 ;i<=n ;i++){
		for(int j=1 ;j<=n ;j++){
			printf(" %d ",a[i][j]);
		}
		printf("\n");
	}
}
void DinhTreo(int a[10][10], int n){
int bac = 0, mangdinhtreo[10], dem=0;
bool check = false;
	for(int i=1 ;i<=n ;i++){
		for(int j=1 ;j<=n ;j++){
			if(a[i][j] !=0 && i!=j){
				bac += a[i][j];
			}
			else if(a[i][j] !=0 && i==j){
				bac += a[i][j]*2;
			}
			
		}
		printf("\nbac cua %d: %d ",i,bac);
		if(bac==1){
			 mangdinhtreo[dem] = i;
			 dem++;
			 check = true;
	    }
		bac=0;
	}
	if(check == true){
		printf("\nCac dinh treo la: ");
		for(int i=0 ; i<dem ; i++){
			printf(" %d ",mangdinhtreo[i]);
		}
	}
	else{
	    printf("\nDo thi khong co dinh treo!");
	}
}
void BFS(int a[10][10], int n){
	int S[10], d[10], x, t =0, k=0;
	printf("\nNhap vao phan tu bat dau: ");
	scanf("%d",&x);
	for(int i=1 ; i<=n ; i++){
		d[i] = 0;
	}
	
	S[0] =x ;
	t++;
	while(t>0){
		k = S[0];
		t--;
		if(d[k]==0){
			printf(" %d ",k);
			d[k] = -1;
		}
		
		for(int i=0 ;i<n ; i++){
			S[i]= S[i+1];
		}
		
		for(int i=1 ; i<=n ; i++){
			if(a[k][i]!=0 && d[i]==0){
				S[t] = i;
				t++;
			}
		}
	}
}
void DFS(int a[10][10], int n){
	int S[10], d[10], x,k=0, t=0;
	printf("\nNhap vao dinh bat dau: ");
	scanf("%d",&x);
	for(int i=1 ; i<=n ;i++){
		d[i] = 0;
	}
	S[0] = x;
	t++;
	while(t>0){
		k = S[t-1];
		t--;
		if(d[k]==0){
			printf(" %d ",k);
			d[k] = -1;
		}
		
		for(int i=n ; i>=1 ;i--){
			if(a[k][i] != 0 && d[i]==0){
				S[t] = i;
				t++;
			}
		}
	}
	
}
void Dijkstra(){
	int s,f,u,lap=0;
	printf("\nNhap vao phan tu bat dau: ");
	scanf("%d",&s);
	KhoiTao(s,n);
	while(lap!=n-1){
		printf("|Lap %d",lap+1);
		u = TimViTriMin(n);
		CapNhatKe(u);
		d[u] = -1;
		lap++;
	}
	printf("\nNhap vao dinh ket thuc: ");
	scanf("%d",&f);
	TimDuong(f);
}
void KhoiTao(int s, int n){ 
	for(int i=1 ; i<=n ; i++){
		L[i] = vc;
		d[i] = 0;
	}
	L[s] = 0;
}
int TimViTriMin(int n){
	int min = 1000, vt=0;
	for(int i=1 ; i<=n ; i++){
		if(L[i]<min && d[i]==0){
			min = L[i];
			vt = i;
		}
	}
	 return vt;
}
void CapNhatKe(int u){
	for(int i=1 ; i<=n ;i++){
		if(a[u][i]!=0 && d[i]==0){
			if(L[i] > L[u]+a[u][i]){
				L[i] = L[u]+a[u][i];
				T[u] = i;
			}
		}
	}
	
	for(int i=1 ; i<=n ; i++){
		printf("|%-7d",L[i]);
		if(i==n){
			printf("|\n");
		}
	}
}
void TimDuong(int f){
	int i=1,dem = 0 ,x;
	x = f;
	while(T[f]!=0){
		tam[i] = T[f];
		f = T[f];
		dem++;
		i++;
	}
	printf("\nDuong di ngan nhat co do dai: %d",L[x]);
	for(int i=dem ; i>=1 ; i--){
		printf(" %d=>",tam[i]);
	}
	printf("%d",x);
}
