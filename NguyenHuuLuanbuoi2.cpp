#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
bool CheckDoiXung(int a[10][10], int m);
bool CheckDonVoHuong(int a[10][10], int m);
bool CheckGiaDoThi(int a[10][10], int m);
bool CheckDonCoHuong(int a[10][10], int m);
int main(){
	FILE *fp;
	int m,a[10][10];
	fp = fopen("C:\\Test.txt","r");
	if(fp==NULL){
		printf("Khong tim thay tap tin");
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
	//Kiem tra 
	if(CheckDoiXung(a,m) == true){
		printf("\nDo thi doi xung qua duong cheo chinh!");
		if(CheckDonVoHuong(a,m) == true && CheckGiaDoThi(a,m) == false){
			printf("\n->Don do thi vo huong!");
		}
	    if(CheckGiaDoThi(a,m) == true && CheckDonVoHuong(a,m) == false){
			printf("\n->Gia do thi!");
		}
		if(CheckDonVoHuong(a,m) == false && CheckGiaDoThi(a,m) == false) {
			printf("\n->Da do thi vo huong!");
		}
		
	}
	else{
		printf("\nDo thi khong doi xung qua duong cheo chinh!");
		if(CheckDonCoHuong(a,m) == true){
			printf("->Don do thi co huong!");
		}
		else{
			printf("->Da do thi co huong!");
		}
	}
}
bool CheckDoiXung(int a[10][10], int m){
	//bool check = true;
	for(int i=1; i<=m ; i++){
		for(int j=1 ; j<=m ; j++){
			if(a[i][j] != a[j][i]){
				return false;
			}
		}    
	}
	return true;
}

bool CheckDonVoHuong(int a[10][10], int m){
	bool check = true;
	for(int i = 1 ; i<=m ; i++){
		for(int j=1 ; j<=m ; j++){
			if(a[i][j] > 1){
				check = false;
			}
			if(i==j){
				if(a[i][j] != 0){
					check = false;
				}
			}
		}
	}
	return check;
}
bool CheckGiaDoThi(int a[10][10], int m){
	bool check = false;
	for(int i=1 ; i<=m ; i++){
		for(int j=1; j<=m ; j++){
			if(i==j){
				if(a[i][j] != 0){
					check = true;
				}
			}
		}
   }
   return check;
}

bool CheckDonCoHuong(int a[10][10], int m){
	bool check = false;
	bool check2 = true;
	bool check3 = true;
	for(int i=1 ; i<=m ; i++){
		for(int j=1; j<=m ; j++){
			if(a[i][j] != a[j][i]){
				check = true;
			}
		}
    }
   
    for(int i=1 ; i<=m ; i++){
		for(int j=1; j<=m ; j++){
			if(a[i][j] > 1){
				check2 = false;
			}
		}
    }
    
    for(int i=1 ; i<=m ; i++){
		for(int j=1; j<=m ; j++){
			if(i == j){
				if(a[i][j] != 0){
					check3 = false;
				}
			}
		}
    }
   if(check == true && check2 == true && check3 == true){
   		return true;
   }
   return false;
}




