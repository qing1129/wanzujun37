#include"point1.h"

int main() {
	
	int var1, var2, var3;
	printf("请输入3个值：\n");
    scanf("%d%d%d",&var1, &var2, &var3);
    printf("var1=%d var2=%d var3=%d\n",var1, var2, var3);
    int *p1 = &var1; 
    int *p2 = &var2;
    int *p3 = &var3;
    printf("var1=%d, var2=%d, var3=%d\n",p1, p2, p3);
    swap(&var1 ,&var2, &var3);
    printf("var1=%d, var2=%d, var3=%d\n",var1, var2, var3);
    
    
	
	
} 
