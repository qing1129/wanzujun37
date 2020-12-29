#include"tree.h"

void CreateHT(HTNode ht[],int n0)	//建立哈夫曼树的函数 
{	
	int i,k,lnode,rnode;
	double min1,min2;
        const int INF=1e9+7;
	for (i=0;i<2*n0-1;i++)		
		ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
	for (i=n0;i<=2*n0-2;i++)		
	{	
		min1=min2=INF;//min1存最小的权值,min2存次小权值		
		lnode=rnode=-1;
		for (k=0;k<i;k++)//寻找ht里面未使用的最小的两个数 
			if (ht[k].parent==-1) 
			{	
				if(ht[k].weight<min1)
				{	
					min2=min1;//保证min1<=min2 
					rnode=lnode;
					min1=ht[k].weight;
					lnode=k;
				}
				else if(ht[k].weight<min2)
				{	
					min2=ht[k].weight;
					rnode=k; 
				}
			}
		ht[i].weight=ht[lnode].weight+ht[rnode].weight;
		ht[i].lchild=lnode;
		ht[i].rchild=rnode;
		ht[lnode].parent=i;
		ht[rnode].parent=i;
	}
}

void CreateHCode(HTNode ht[],HCode hcd[],int n0)	//构造哈夫曼树编码
{	
	int i,f,c;
	HCode hc;
	for (i=0;i<n0;i++)			
	{	
		hc.start=n0;c=i;
		f=ht[i].parent;
		while (f!=-1)				
		{	
			if (ht[f].lchild==c)
				hc.cd[hc.start--]='0';
			else				
				hc.cd[hc.start--]='1';
			c=f;
			f=ht[f].parent;	
		}
		hc.start++;			
		hcd[i]=hc;
	}
}

void DispHCode(HTNode ht[],HCode hcd[],int n0) 
{
	int i,k,temp=0;
	double sum=0;
	int j;
	printf("  输出");
	for(i=0;i<8;i++)
		printf("%s",ht[i].data);
	printf("的哈夫曼编码:\n");
	for (i=0;i<n0;i++)
	{
		printf("    %s:\t\t",ht[i].data);
		for (k=hcd[i].start;k<=n0;k++)
			printf("%c",hcd[i].cd[k]);
		printf("\n"); 
	}	
}

void Decode(HTNode ht[],char code[]) //解码 
{
	printf("\n\n  对“%s”解码：\n",code);
	int p=ht[0].parent;
	int m;//根 
	while(p!=-1)//找到根 
	{
		m=p;
		p=ht[m].parent;	
	}
	int t;
	int a1=0,a2=0;
	for(int i=0;i<strlen(code);)
	{
		a1=a2;
		t=m;
		while(ht[t].lchild!=-1&&ht[t].rchild!=-1&&i<strlen(code)) 
		{
			if(code[i]== '0')                
				t=ht[t].lchild;           
			else  if(code[i]== '1')             
				t=ht[t].rchild;
			i++;			    
		}
		a2=i;
		if(t==-1||ht[t].lchild!=-1&&ht[t].rchild!=-1)
		{
			int j=i-1;
			printf("   ");
			for(int j=a1;j<a2;j++)
				printf("%c",code[j]);
			printf(":\t错误\n");
		} 	
		else
		{
			printf("   ");
			for(int j=a1;j<a2;j++)
				printf("%c",code[j]);
			printf(":%6s\n",ht[t].data);
		}			
	} 
	printf("\n");
}
