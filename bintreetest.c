#include"bintree.h"

int main()
{
 BiTree T;
 printf("输入二叉树中的数据元素：");
 CreateBiTree(&T);
 printf("先序遍历二叉树的序列是：");
 PreOrderTraverse(T, PrintElement);
 printf("\n");
 printf("中遍历二叉树的序列是：");
 InOrderTraverse(T, PrintElement);
 printf("\n");
 printf("后序遍历二叉树的序列是：");
 PostOrderTraverse(T, PrintElement);
 printf("\n");
 system("pause");
 return 0;
}
