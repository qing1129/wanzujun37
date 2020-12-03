#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Node
{
    int data;
    struct Node * next;
} NODE, *PNODE;


typedef struct Stack
{
    PNODE pTop;            
    PNODE pBottom;      
} STACK, *PSTACK;

typedef char Elemtype;

void init(PSTACK pStack);  
void show(PSTACK pStack);    
int isEmpty(PSTACK pStack);
void push(PSTACK pStack, int val);     
void pop(PSTACK pStack, int *val);  
void clear(PSTACK pStack); 
int GetTop(PSTACK );
int priority(char );
double compute(double , double , char );
int f();
char *gets(char *);


