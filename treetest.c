#include"tree.h"

int main()
{
	int n=8,i;		//n表示初始字符串的个数
	char str[][2]={"a","b","c","d","e","f","g","h"};
	double fnum[]={0.07,0.19,0.02,0.06,0.32,0.03,0.21,0.1};
	char code[40];
	HTNode ht[M];//存哈夫曼树 
	HCode hcd[N];//存哈夫曼编码 
	for (i=0;i<n;i++) 
	{
		strcpy(ht[i].data,str[i]);
		ht[i].weight=fnum[i];
	}
	CreateHT(ht,n);
	CreateHCode(ht,hcd,n);
	DispHCode(ht,hcd,n);
	printf("\n");
	printf("  请输入编码："); 
	scanf("%s",code);
	Decode(ht,code);
	return 1;
}  
