#include"maopao.h"

int main() {
  int a[8] = {10,100,70,66,99,75,6,25};
  int i;
  int j;
  printf("第一次输入的数据为:\n");
      for (j=0; j<8; j++) {
         printf(" %d",a[j]);
         }
         printf("\n");
 printf("改变后为:\n");
//sort1(a, 8);
//sort2(a, 8);
//Insertsort(a, 8);
//Selectsort(a, 8);
QuickSort(a, 8);       
     for (i=0; i<8; i++) { 
       printf(" %d",a[i]);
}
       printf("\n");
   




























    return 0;
}

