#include<stdio.h>
void Input(int a[], int n);
void Output(int a[], int n);
void Timphantuthux(int a[], int n);
void Timmax(int a[], int n);
void Timmin(int a[], int n);
void Timle(int a[], int n);
void TongMang(int a[], int n);
int main(){
	int a[50],n,x;
	printf("\nNhap vao so phan tu cua mang: ");
	scanf("%d",&n);
	Input(a,n);
	Output(a,n);
	Timphantuthux(a,n);
	Timmax(a,n);
	Timmin(a,n);
	Timle(a,n);
	TongMang(a,n);
}
void Input(int a[], int n){
	for(int i=0 ; i<n ; i++){
		printf("\nNhap a[%d]: ",i);
		scanf("%d",&a[i]);
	}
}
void Output(int a[], int n){
	printf("\nGia tri cac phan tu cua mang la: ");
	for(int i=0 ; i<n ; i++){
		printf(" %d ",a[i]);
	}
}
void Timphantuthux(int a[], int n){
	int x,dem=0;
	do{
		if(dem>0){
			printf("\nBan da nhap sai, hay nhap lai!");
		}
		printf("\nNhap vao gia tri x: ");
		scanf("%d",&x);
		dem++;
	}while(x<0||x>n-1);
	
	for(int i=0 ; i<n ; i++){
		if(x == i){
			printf("\nGia tri phan tu thu x = %d la: %d",x,a[i]);
		}
	}
}
void Timmax(int a[], int n){
	int max = a[0], vitri=0;
	for(int i=0 ; i<n ; i++){
		if(a[i]>max){
			max = a[i];
			vitri = i;
		}
	}
	printf("\nPhan tu lon nhat tai vi tri: a[%d] = %d",vitri,max);
}

void Timmin(int a[], int n){
	int min = a[0], vitri = 0;
	for(int i=0 ; i<n ; i++){
		if(a[i]<min){
			min = a[i];
			vitri = i;
		}
	}
	printf("\nPhan tu nho nhat tai vi tri: a[%d] = %d",vitri,min);
}

void Timle(int a[], int n){
	printf("\nCac so le trong mang la: ");
	for(int i=0; i<n ; i++){
		if(a[i]%2!=0){
			printf(" %d ",a[i]);
		}
	}
}

void TongMang(int a[], int n){
	int tong = 0;
	for(int i=0 ; i<n ; i++){
		tong+=a[i];
	}
	printf("\nTong cac phan tu trong mang la: %d",tong);
}
