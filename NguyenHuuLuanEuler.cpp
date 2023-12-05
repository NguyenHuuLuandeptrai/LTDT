#include<stdio.h>
int a[10][10],n;
void ChuTrinhEuLer(int a[10][10], int n);
bool KiemTraDoThiEuLer(int a[10][10], int n);
int main(){
	FILE *fp;
	fp = fopen("C://Test.txt","r");
	if(fp==NULL){
		printf("\nTep khong ton tai!");
	}
	else{
		fscanf(fp,"%d",&n);
		for(int i=1; i<=n ; i++){
			for(int j=1; j<=n; j++){
				fscanf(fp,"%d",&a[i][j]);
			}
		}
		fclose(fp);
	}
	
	printf("\nMang trong file la: \n");
	for(int i=1; i<=n ; i++){
			for(int j=1; j<=n; j++){
				printf(" %d ",a[i][j]);
			}
			printf("\n");
	}
	

	
	if(KiemTraDoThiEuLer(a,n) == false){
		printf("\nKhong la chu trinh Euler");
	}
	else{
		printf("\nLa chu trinh Euler");
		ChuTrinhEuLer(a,n);
	}
}

bool KiemTraDoThiEuLer(int a[10][10], int n){
	int bac=0;
	for(int k=1; k<=n ; k++){
		for(int j = 1 ; j <= n; j++){
			if(a[k][j] != 0 && a[j][k]!=0){
				bac+=a[k][j];
			}
		}
	 if(bac%2 != 0){return false;}
	 bac = 0;
	}
	return true;
}

void ChuTrinhEuLer(int a[10][10], int n){
	int S[20], x, t=0,t1=0, std[20];
	printf("\nNhap dinh bat dau: ");
	scanf("%d",&x);
	S[t++] = x;	
	while(t!=0){
		int u = S[t-1];
		int k=0;
		for(int i=1 ; i<=n ; i++){
			if(a[u][i] != 0){
				S[t++] = i;
				a[u][i]--;
				a[i][u]--;
				k=1;
				break;	
			}
		}
		if(k==0){
			t--;
			std[t1++] = u;
		}
	}
	
	printf("\nChu trinh euler: ");
	for(int i=t1-1 ; i>=0 ; i--){
		printf(" %d ",std[i]);
		if(i>0){
			printf("=>");
		}
	} 
	
}
