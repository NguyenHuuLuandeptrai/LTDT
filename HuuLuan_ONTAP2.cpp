#include<stdio.h>
void Input(int a[50][50], int m, int n);
void Output(int a[50][50], int m, int n);
void Maxtrenhangx(int a[50][50], int m, int n);
void Mintrencoty(int a[50][50], int m, int n);
void Tonghangk(int a[50][50], int m , int n);
void Tongcotm(int a[50][50], int m, int n);
void Tongchan(int a[50][50], int m, int n);
void Ktrduongcheo(int a[50][50], int m, int n);
void Ktrnhohonbang1(int a[50][50], int m, int n);
void Ktrdoixung(int a[50][50], int m, int n);
int main(){
	int a[50][50], m,n;
	printf("\nNhap vao so cot cua mang: ");
	scanf("%d",&m);
	printf("Nhap vao so dong cua mang: ");
	scanf("%d",&n);
	Input(a,m,n);
	Output(a,m,n);
	Maxtrenhangx(a,m,n);
	Mintrencoty(a,m,n);
	Tonghangk(a,m,n);
	Tongcotm(a,m,n);
	Tongchan(a,m,n);
	Ktrduongcheo(a,m,n);
	Ktrnhohonbang1(a,m,n);
	Ktrdoixung(a,m,n);
}
void Input(int a[50][50], int m, int n){
	for(int i=0 ; i<m ; i++){
		for(int j=0 ; j<n ; j++){
			printf("\nNhap vao a[%d][%d]= ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void Output(int a[50][50], int m, int n){
	printf("\nGia tri cac phan tu cua mang la:\n");
	for(int i=0 ; i<m ; i++){
		for(int j=0 ; j<n ; j++){
			printf(" %d ",a[i][j]);
		}
		printf("\n");
	}
}
void Maxtrenhangx(int a[50][50], int m, int n){
	int x = 0, max = 0,dem=0;
	do{
		if(dem>0){printf("\nBan da nhap sai, hay nhap lai!");
		}
		printf("\n\nNhap vao hang x(tim phan tu lon nhat tren hang x): ");
		scanf("%d",&x);
		dem++;
	}while(x<0||x>m-1);
	max = a[x][0];
		for(int j=0 ; j<n ; j++){
			if(a[x][j] > max){
				max = a[x][j];
			}
	}
	printf("Phan tu lon nhat tren hang %d la: %d ",x,max);
}
void Mintrencoty(int a[50][50], int m, int n){
	int y = 0 , min = 0, dem=0;
	do{
		if(dem>0){
			printf("\nBan da nhap sai, hay nhap lai!");
		}
		printf("\n\nNhap vao cot y(tim phan tu nho nhat tren cot y): ");
		scanf("%d",&y);
		dem++;
	}while(y<0||y>n-1);
	min = a[0][y];
	for(int i = 0 ; i<m ; i++){
			if(a[i][y] < min){
				min = a[i][y];
			}
	}
	printf("Phan tu nho nhat tren cot %d la: %d ",y,min);
}

void Tonghangk(int a[50][50], int m , int n){
	int k = 0, tong = 0, dem=0;
	do{
		if(dem>0){
			printf("\nBan da nhap sai, hay nhap lai!");
		}
		printf("\n\nNhap vao hang k(tinh tong tren hang k): ");
		scanf("%d",&k);
		dem++;
	}while(k<0||k>m-1);
	
	for(int j=0 ; j<n ; j++){
		tong += a[k][j];
	} 
	printf("Tong cac phan tu trong hang %d la: %d",k,tong);
}

void Tongcotm(int a[50][50], int m, int n){
	int M =0 , tong = 0, dem=0;
	do{
		if(dem>0){
			printf("\nBan da nhap sai, hay nhap lai!");
		}
		printf("\n\nNhap vao m(tinh tong tren cot m): ");
		scanf("%d",&M);
		dem++;
	}while(M<0||M>n-1);

	for(int i=0 ; i<m ; i++){
		tong += a[i][M];
	}
	printf("Tong cac phan tu trong cot %d la: %d",M,tong);
}

void Tongchan(int a[50][50], int m, int n){
	int tongchan = 0;
	for(int i=0 ; i<m ; i++){
		for(int j=0 ; j<n ; j++){
			if(a[i][j]%2==0){
				tongchan+=a[i][j];
			}
		}
	}
	printf("\n\nTong cac phan tu chan trong mang la: %d",tongchan);
}

void Ktrduongcheo(int a[50][50], int m, int n){
	bool check = true;
	for(int i = 0 ; i<m ; i++){
		for(int j = 0 ; j<n ; j++){
			if(i==j){
				if(a[i][j] != 0){
					check = false;
				}
			}
		}
	}
	if(check == true){
		printf("\n\nDuong cheo bang 0!");
	}
	else{
		printf("\n\nDuong cheo khac 0!");
	}
}

void Ktrnhohonbang1(int a[50][50], int m, int n){
	bool check = true;
	for(int i=0 ; i<m ; i++){
		for(int j = 0 ;j<n ; j++){
			if(a[i][j] > 1){
				check = false;
			}
		}
	}
	if(check == false){
		printf("\n\nNO(ton tai phan tu lon hon 1)");
	}
	else{
		printf("\n\nYES(moi phan tu nho hon bang 1)");
	}
}

void Ktrdoixung(int a[50][50], int m, int n){
	bool check = true;
	for(int i=0 ; i<m ; i++){
		for(int j=0 ; j<n ; j++){
			if(a[i][j] != a[j][i]){
				check = false;
			}
		}
	}
	if(check == true){
		printf("\n\nDoi xung!");
	}
	else{
		printf("\n\nKhong doi xung!");
	}
}

