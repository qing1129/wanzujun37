#include"bintree.h"

Status CreateBiTree(BiTree *T)
{
 TElemType ch;
 scanf("%c", &ch);
 if (ch == '#') *T = NULL;//空树
 else
 {
  if (!(*T = (BiTNode*)malloc(sizeof(BiTNode))))//开辟结点空间
  {
   printf("内存分配失败");
   exit(OVERFLOW);
  }
  (*T)->data = ch;//数据域赋值
  CreateBiTree(&(*T)->lchild);//创建左子树 注意：传递的是左子树结点的地址
  CreateBiTree(&(*T)->rchild);//创建右子树
 }
 return OK;
}


Status PrintElement(TElemType e)
{//输出元素e的值
 printf("%c", e);
 return OK;
}


Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
 if (T)
 {
  if (Visit(T->data))//访问根结点
   if (PreOrderTraverse(T->lchild, Visit))//访问左子树
    if (PreOrderTraverse(T->rchild, Visit))//访问右子树
     return OK;
  return ERROR;
 }
 else
  return OK;
}


Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
 if (T)
 {
  if (InOrderTraverse(T->lchild, Visit))//访问左子树
   if (Visit(T->data))//访问根结点
    if (InOrderTraverse(T->rchild, Visit))//访问右子树
     return OK;
  return ERROR;
 }
 else
  return OK;
}


Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
 if (T)
 {
  if (PostOrderTraverse(T->lchild, Visit))//访问左子树
   if (PostOrderTraverse(T->rchild, Visit))//访问右子树
    if (Visit(T->data))//访问根结点
     return OK;
  return ERROR;
 }
 else
  return OK;
}

