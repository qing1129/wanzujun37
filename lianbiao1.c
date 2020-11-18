#include"lianbiao1.h"

//创建链表
void initList(Node *l){
	Node *head;
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	return ;
} 

//求链表的元素个数
int Size(Node *l) {
	Node *p = l->next;
	int k = 0;
	while (p) {
		k++;
		p = p->next;
	}
	return k;	
} 

//在链表1的第k个位置插入元素x
void Insert(Node *l, int k, DataType x) {
	if (k<1) exit(1);
	Node *p = l;
	int i = 0;
	while (p && i<k-1) {
		p = p->next;
		i++;
    }
	if (!p) exit(1);
	Node *s = (Node*)malloc(sizeof(Node));
	s->data = x;
	s->next = p->next;
	p->next = s;
} 


//删除链表1的第k个元素
void Delete(Node *l, DataType k) {
	if (k<1) exit(1);
	Node *p = l;
	int i = 0;
	while (p->next && i<k-1) {
		p = p->next;
		i++;
	}
	if (p->next==NULL) exit(1);
	Node *q = p->next;
	p->next = q->next;
	free(q);
} 


//判断链表是否为空
 int Empty(Node *l) {
	return l->next == NULL;
} 

//求链表1的第k个元素的值
 DataType GetData(Node *l, DataType k) {
	if (k<1) exit(1);
	Node *p = l;
	int i = 0;
	while (p && i<k) {
		p = p->next;
		i++;
	}
	if (!p) exit(1);
	return p->data;
}
//在链表1中查找值为x的元素
Node *Find(Node *l, DataType x)
{
	Node *p = l->next;
	while (p && p->data!=x)
	       p = p->next;
	    return p;
 } 
//输出链表
void Print(Node *l){
    Node *p = l->next;
     while(p){
     	printf("%s"," p->data");
     	p = p->next;
	 }
      printf("\n");
}
//清空链表
void ClearList(Node *l) {
	Node *p, *q;
	p = l->next;
	while(p) {
		q = p;
		p = p->next;
		free(q);
	}
	l->next = NULL;
}
DataType CreateList(Node *list,int n,int m) {
         Node *p = (Node*)malloc(sizeof(Node));
         Node *s,*t;
         p->data = 1;
         p->next = NULL;
         Node *q = p;
         for(int i=2; i<=n;++i){
             Node *r = (Node*)malloc(sizeof(Node));
             r->data = i;
             r->next = NULL;
             q->next = r;
                   q = r;
             }
             q->next = p;
             s = p;
             while(s->next !=s){
                   for(int i=1; i<m; ++i){
                           t = s;
                           s = s->next;
                       }
                       t->next = s->next;
                       free(s);
                       s = t->next;
                     }
          return s->data;
}
