#include"stack.h"

int main()
{
    int val;
    STACK S;
    init(&S);
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    show(&S);
    pop(&S, &val);
    pop(&S, &val);
    pop(&S, &val);
    show(&S);
    printf("栈顶的元素为%d\n",GetTop(&S));
    clear(&S);
    show(&S);
    printf("请输入算式： \n");
    double a = f();
    printf("结果是：%.2f", a);
}

     		

























































    

