#include <stdio.h>
#include "my_array_library.h"		

void print_All_Array (int arr[100][100],int row,int column){	// elemanların bastırılması
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			printf("%d ",arr[i][j]);		
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}


void input_Array(int arr[100][100],int row,int column){	// elemanların alınması
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			printf("%d. satirin %d. sutunu icin eleaman giriniz: ",i,j);	
			scanf("%d",&arr[i][j]);
		}
	}
	print_All_Array(arr,row,column);	// alınan elemanların tekrar bastırılması
}



void print_nth_mth(int arr[100][100],int row,int column){		// koordinatlara göre eleman bastırma
	int N,M;
	printf("Aradiginiz elemanin koordinatlarini giriniz.\n");
	printf("x: ");	scanf("%d",&N);
	printf("y: ");	scanf("%d",&M);
	
	if((N > row-1) || (M > column-1)){
		printf("Matris aradiginiz boyutlarda degil, dolayisiyla boyle bir deger yok");
	}
	else{
		printf("Aradiginiz elaman => %d dir.",arr[N][M]);
	}
	printf("\n");
	printf("\n");
}


void print_Index_Of_Element(int arr[100][100],int row,int column){ // elemanın indexini bastırma
	int key,kontrol = 0;int indexN = 0,indexM=0,i,j;
	
	printf("Koordinatlari bulunacak elemani giriniz: ");
	scanf("%d",&key);
	
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			if (arr[i][j] == key){
				indexN = i; indexM = j; kontrol++;
			}
		}
	}
	if (kontrol == 1){		// elemanın olup olmama dururmu
		printf("Aradiginiz elaman %d. satir %d. sutundadir",indexN,indexM);
	}
	else
		printf("Aradiginiz eleman bulunamadi");
		
	printf("\n");
	printf("\n");
}

void finder_Number_Of_Nonrepeat_Values(int arr[100][100],int row,int column){		// dizide sadece 1 adet bulunan elemanların sayısını bastırma
	int i,j,k,l; int numberNonRepeat, kontrol=0;
	
	for(i=0;i<row;i++){				// her bir eleman dizide tekrar arandı ve var olduğu adet kadar sayaç arttırıldı
		for(j=0;j<column;j++){
			for(k=0;k<row;k++){
				for(l=0;l<column;l++){
					if(arr[k][l] == arr[i][j]){
						kontrol++;
					}
				}
			}
			if(kontrol == 1){		// sayaç 1 se tek sayılar 1 attırıldı
				numberNonRepeat++;
				kontrol = 0;
			}
			else {
				kontrol = 0;
			}
		}
	}
	printf("Tekrar etmeyen sayilarin adedi %d",numberNonRepeat);
	printf("\n");
	printf("\n");
}

void finder_Min_Element(int arr[100][100],int row,int column){	// arrayin en küçük eleamnı bastırma
	int i,j; int min=arr[0][0];
	
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			if (arr[i][j]<min){
				min = arr[i][j];
			}
		}
	}
	printf("Dizinin en kucuk elemani %d dir.",min);
	printf("\n");
	printf("\n");	
}

void finder_Max_Element_Rows_Columns(int arr[100][100],int row,int column){	// her satirin ve sütünun  en büyük elemanı bastirildi
	int i,j,l,k,m; int maxRow=-999999; int maxColumn = -999999;
	l = 1;
	for(i=0;i<row;i++){
		for(j=0;j<row;j++){
			if(arr[i][j+1] > maxRow){
				maxRow = arr[i][j+1];
			}
			if(arr[j][i] > maxColumn){
				maxColumn = arr[j][i];
			}
		}
		printf("%d. satirin en buyuk elemani %d dir\n",i+1,maxRow);

		printf("%d. sutunun en buyuk eleamani %d dir\n",l,maxColumn);
		l++;
		printf("\n");

		maxRow = arr[i+1][0];
		maxColumn = arr[0][j+1];
	}
	printf("\n");
	printf("\n");
}

void sorter_Rows_Decending_By_BubbleSort(int arr[100][100],int row,int column){	// her satir büyükten küçüğe sıralandı
	int i,j,l,temp;
	
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			for(l=0;l<column;l++){
				if(arr[i][j] > arr[i][l]){
					temp = arr[i][l];
					arr[i][l] = arr[i][j];
					arr[i][j] = temp;
				}
			}
		}
	}
	printf("Her satir kendi icinde buyukten kucuge siralandi:\n");
	print_All_Array(arr,row,column);
}
	
void finder_Transpose_Of_Array(int arr[100][100],int row,int column){	// matrisin devriğini bastırma
	int i,j; int arr2[100][100];
	
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){				// koordinatlar terslenerek devriği alınması
			arr2[j][i] = arr[i][j];
		}
	}
	printf("Yukarida girilen arrayin devrigi asagidadir.\n");
	print_All_Array(arr2,column,row);
}

int finder_Product_Of_Two_Arrays(int arr[100][100],int row,int column,int arr2[100][100],int row2,int column2){
	int i,j,k; int arrProduct[100][100];

	printf("1. Matris >> \n");
	print_All_Array(arr,row,column);		// iki matrisin matris kurallarina göre çarpilmasi

	printf("2. Matris >> \n");
	print_All_Array(arr2,row2,column2);	

	if(column != row2){
		printf("Matris carpim kurallarina uymuyor.\n");
		return 0;
	}
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			for(k=0;k<column;k++){
				arrProduct[i][j]+= arr[i][k]*arr2[k][j];
			}
		}
	}
	printf("Iki matrisin carpimi >> \n");		// sonuç matrisinin bastirilmasi
	print_All_Array(arrProduct,row,column);	
}

void controller_Whether_Identity_Matrix_Not(int arr[100][100],int row,int column){		// birim matris kontrolü
	int i,j; int counterDiag = 0; int counterOutDiag = 0;

	if (row == column){
		for(i=0;i<row;i++){
			for(j=0;j<column;j++){		// n x n matriste olması gereken 1 ve 0 sayisina göre birim matris kontrolü
				if ((i == j)){
					if ((arr[i][j] == 1) && (arr[j][i] == 1))
						counterDiag++;								
				}
				else if (arr[i][j] == 0){
					counterOutDiag++;
				}
				else{
					continue;
				}
			}
		}
		if((counterDiag == row) && (counterOutDiag == row*column-row)){
			printf("Bu matris Birim Matristir.\n");
		}
		else{
			printf("Bu matris Birim Matris Degildir.\n");
		}
	}
	else{
		printf("Sadece kare matrisler için birim matris vardir.\n");
	}
	printf("\n");
	printf("\n");
}

void controller_Whether_Symmetric_Matrix_Not(int arr[100][100],int row,int column){
	int i,j; int counter = 0;
	
	if (row == column){
		for(i=0;i<row;i++){				// simetrik matriste bulunması gerek eşit sayı miktarı kontrolüyle simetrik matris kontolü
			for(j=0;j<column;j++){
				if (i  == j){				
				continue;
				}
				else if (arr[i][j] == arr[j][i]){
					counter++;
				}
				else{
					continue;
				}
			}
		}
		if(counter == (row*column - row)){
			printf("Girilen Matris Simetriktir.");
		}	
		else if(counter != (row*column - row)){
			printf("Girilen Matris Simetrik degildir.");
		}	
	}
	else{
		printf("Sadece kare matrislerin simetrigi vardir.");
	}
	printf("\n");
	printf("\n");
}
