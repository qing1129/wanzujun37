#include"stack.h"

void init(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if (pS->pTop==NULL)
    {
        printf("内存分配失败");
        exit(-1);
    } else
    {
        pS->pBottom = pS->pTop;     
        pS->pTop->next = NULL;
    }

}

int isEmpty(PSTACK pS)
{
    if (pS->pTop == pS->pBottom)    
    {
        return 1;
    }
    return 0;
}

void push(PSTACK pS, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (pNew == NULL)
    {
        printf("内存分配失败");
        exit(-1);
    }

    pNew->data=val;
    pNew->next=pS->pTop;      
    pS->pTop = pNew;            
}

void pop(PSTACK pS, int *val)
{
    if (isEmpty(pS))
    {
        printf("Stack is Empty");
        return;
    } else
    {
        PNODE q = pS->pTop;
        *val = q->data;
        pS->pTop = q->next;
        free(q);                 
        q = NULL;
    }
}

void clear(PSTACK pS)
{
    if (isEmpty(pS))
    {
        printf("Stack is Empty");
        return;
    } else
    {
        PNODE p = pS->pTop;
        PNODE q = NULL;
        while (p!=pS->pBottom)
        {
            q=p->next;
            free(p);
            p=q;
        }
        pS->pTop=pS->pBottom;     
    }
}

void show(PSTACK pS)
{
    if (isEmpty(pS))
    {
        printf("栈元素为空\n");
    } else
    {
        PNODE p = pS->pTop;
        while (p != pS->pBottom)
        {
            printf("%d,", p->data);
            p=p->next;
        }

        printf("\n");
    }
}

int GetTop(PSTACK pS)
{
	return pS->pTop->data;
}

int priority(Elemtype x){
        switch(x){
                case'+':
                case'-':
                case'=':return 1;
                case'*':
                case'/':return 2;
                case'(':return 3;
                }
}

double compute(double x, double y, Elemtype z){
        switch(z){
                case'+':return x+y;
                case'-':return x-y;
                case'*':return x*y;
                case'/':return x/y;
        }
}
int f() {  
    char s2[500], t[1001], op;
    double s1[500];
    int top1 = -1, top2 = -1;
    double x, y;
    gets(t);
    for (int i=0; i<strlen(t); i++) {
         if (t[i]>='0' && t[i]<='9') {
                  double value = 0;
                while (t[i]>='0' && t[i]<='9') {
                         value = 10*value + t[i] -'0';
                         i++;
                 }
         if (t[i] == '.') {
                 int r = 10;
                 i++;
                while (t[i]>='0' && t[i]<='9') {
                         value += (t[i]-'0')/r;
                         r = 10 * r;
                           i++;
                 }
         }
         s1[++top1] = value;
         }
     
           if (t[i] == ')') {
                 while (s2[top2] != '(') {
                        y = s1[top1--];
                         x = s1[top1--];
                         op = s2[top2--];
                       s1[++top1] = compute(x, y, op);
        }
         top2--;
         }  else {
                while (top2 != -1 && s2[top2] !='(' && priority(t[i])<=priority(s2[top2]))
                {
                        y = s1[top1--];
                        x = s1[top1--];
                          op = s2[top2--];
                         s1[++top1] = compute(x, y, op);
                }
        s2[++top2] = t[i];
        }
     }
          return s1[top1];

}     

































