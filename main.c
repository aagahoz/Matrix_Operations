#include <stdio.h>
#include "my_array_library.h"

int main(int argc, char *argv[]) {
	int row, column;
	int array[100][100] = {{4,5,6},{7,8,4},{2,2,2}}; row = 3; column = 3;					// sistemde girili temel matrisler
	int testArray[100][100] = {{1,3,5},{7,9,11},{13,15,17}}; int row2 = 3; int column2 = 3; 	// product icin
	int operation=1; int newMatrisRequest=1; int newSecondMatrisRequest = 0;
	
	while(newMatrisRequest){
	printf("Kendi Matrisinizle islem yapmak icin 1, kayitli matrisle islem yapmak icin 0, cikmak icin -1 giriniz:  ");	// matris secimi
	scanf("%d",&newMatrisRequest);
	if((newMatrisRequest == 0) || (newMatrisRequest== 1) ){  // matris secim kontrolleri  yeni-eski
		break;
	}
	else if (newMatrisRequest != -1) {
		printf("Hatali Kod!!\n");
	}
	else if(newMatrisRequest == -1){
		printf("Program Sonlandirildi!!\n ");
		return 0;
	}
	}

	if (newMatrisRequest == 1){
		printf("Matrisin satir boyutunu giriniz: ");scanf("%d",&row);		
		printf("Matrisin sutun boyutunu giriniz: ");scanf("%d",&column);
		input_Array(array,row,column);
	}
	
	if (newMatrisRequest == 0){
		printf(">> Sistemde kayitli matris kullanilacak\n");
		printf("\n");
	}
	
	while(operation){		// döngü sağlanarak program sürekliliği

		printf("************************************************************************\n");		// işlem sorusu
		printf("	0- Cikmak icin\n");
		printf("	1- Matrisi Bastirmak icin\n");
		printf("	2- Yeni Matris Girmek icin\n");
		printf("	3- Koordinatlari girerek matris elemanini bulmak icin\n");
		printf("	4- Girilen matris elemanin koordinatlarini almak icin\n");
		printf("	5- Matriste sadece 1 adet bulunan elemanlarin sayisini almak icin icin\n");
		printf("	6- Matrisin en kucuk elemanini almak icin\n");
		printf("	7- Her bir matrisin sutunun ve satirinin en buyuk elemanini almak icin\n");
		printf("	8- Bubble Sort Algoritmasina gore matrisi yenilemek icin\n");
		printf("	9- Matrisin Transpose unu almak icin\n");
		printf("	10- Iki matrisi carpmak icin\n");
		printf("	11- Matrisin birim matris olup olmadigini kontrol etmek icin\n");
		printf("	12- Matrisin simetrik matris olup olmadigini kontrol etmek icin\n");

		printf("\n");	

		printf("\n");
		printf("Lutfen Yapmak Istediginiz Islemin Numarasini Giriniz >>  ");
		scanf("%d",&operation);	

		system("CLS");
		printf("\n");

		switch(operation){		// seçilecek çağrılacak fonksiyon seçimi
		case(0):
		printf("\nProgram Sonlandirildi!\n");
		break;	
		case(1):
			print_All_Array(array,row,column);  // matris bastırma
			break; 
		case(2):
		printf("Matrisin satir boyutunu giriniz: ");scanf("%d",&row);		// matris boyutu alma
		printf("Matrisin sutun boyutunu giriniz:");scanf("%d",&column);
		input_Array(array,row,column); // matris alma
			break;
		case(3):	
			print_nth_mth(array,row,column); // koordinatlara göre matris alma
			break;
		case(4):
			print_Index_Of_Element(array,row,column);		// elemanın konumu
			break;
		case(5):
			finder_Number_Of_Nonrepeat_Values(array,row,column);	// tekrar etmeyen eleman sayısı
			break;
		case(6):
			finder_Min_Element(array,row,column);	// matrisin en küçük elemanıa
			break;
		case(7):
			finder_Max_Element_Rows_Columns(array,row,column);	// her satır ve sütünün en büyük elemanını bastırma
			break;
		case(8):
			sorter_Rows_Decending_By_BubbleSort(array,row,column);  // satırları büyükten küçüğe sıralama
			break;
		case(9):
			finder_Transpose_Of_Array(array,row,column); // matrisin devriğini alma
			break;
		case(10):
			printf("2. Matris icin sistemde girili olan yerine kendi matrisinizi girecekseniz 1, istemiyorsaniz 0 yaziniz: ");
			scanf("%d",&newSecondMatrisRequest);
			if(newSecondMatrisRequest == 1){
				printf("Matrisin satir boyutunu giriniz: ");scanf("%d",&row2);		
				printf("Matrisin sutun boyutunu giriniz:");scanf("%d",&column2);
				input_Array(testArray,row2,column2);
			}
			finder_Product_Of_Two_Arrays(array,row,column,testArray,row2,column2);  // matris çarpımı
			break;
		case(11):
			controller_Whether_Identity_Matrix_Not(array,row,column);	// birim matris kontrolü
			break;
		case(12):			
			controller_Whether_Symmetric_Matrix_Not(array,row,column);	// simetrik matris kontrolü
			break;
		default:
			printf("Hatali Islem Kodu, Tekrar deneyin!!\n");
			printf("\n");
		}
		}
	printf("\n");
	system("pause");
	return 0;
}
