#ifndef my_array_library_h_
#define my_array_library_h_
/*
fonksiyonların prototiplenmesi
*/

void input_Array(int arr[100][100],int row,int column);
void print_All_Array(int arr[100][100],int row,int column);
void print_nth_mth(int arr[100][100],int row,int column);
void print_Index_Of_Element(int arr[100][100],int row,int column);
void finder_Number_Of_Nonrepeat_Values(int arr[100][100],int row,int column);
void finder_Min_Element(int arr[100][100],int row,int column);
void finder_Max_Element_Rows_Columns(int arr[100][100],int row,int column);
void sorter_Rows_Decending_By_BubbleSort(int arr[100][100],int row,int column);
void finder_Transpose_Of_Array(int arr[100][100],int row,int column);
int finder_Product_Of_Two_Arrays(int arr[100][100],int row,int column,int arr2[100][100],int row2,int column2);
void controller_Whether_Identity_Matrix_Not(int arr[100][100],int row,int column); 
void controller_Whether_Symmetric_Matrix_Not(int arr[100][100],int row,int column);


#endif
