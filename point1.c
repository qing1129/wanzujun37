#include"point1.h"

 void swap(int *ptr_var1, int *ptr_var2, int *ptr_var3) {
        
           int t;
           t = *ptr_var1;
           *ptr_var1 = *ptr_var2;
           *ptr_var2 = *ptr_var3;
           *ptr_var3 = t;        
  }
