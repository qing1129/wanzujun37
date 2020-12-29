#ifndef tree_h
#define tree_h
#include <stdio.h>
#include <string.h>
#define N 50
#define M 2*N-1	

typedef struct//哈夫曼树的存储结构 
{
	char data[6];
	double weight;	
	int parent;	
	int lchild;		
	int rchild;		
} HTNode;
typedef struct//存放哈夫曼码存储结构 
{
	char cd[N];		
	int start;
} HCode;

void CreateHT(HTNode ht[],int n0);
void CreateHCode(HTNode ht[],HCode hcd[],int n0);
void DispHCode(HTNode ht[],HCode hcd[],int n0);
void Decode(HTNode ht[],char code[]);


#endif















