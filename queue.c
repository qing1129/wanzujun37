#include "queue.h"
 void initList(List *list){
      list->head = NULL;
      list->tail = NULL;
      list->current = NULL;
  
      return;
  }
 
void inQueue(List *list, DataType data){
       //1、创建一个节点
     Node *node = (Node *)malloc(sizeof(Node));
     node->data = data;
     node->next = NULL;
 
     //2、插入节点准备
     if(list->head == NULL){
         list->head = node;
     }else{
         //node->next = list->head;
         list->tail->next = node;
     //3、插入节点
     }
     list->tail = node;
 
     return;
}
 
 void outQueue(List *list){
     list->head = list->head->next;

     return;
 }
 
     Node *frontQueue(List *list){
     Node *node = (Node *)malloc(sizeof(Node));
     node = list->head;
 
     return node;;
}
 
 int getLength(List *list){
     Node *node = (Node*)malloc(sizeof(Node));
     node = list->head;
     int i = 0;
     while(node != NULL){
         node = node->next;
         i++;
     }
 
     return i;
 }

 void dispList(List *list){
     Node *node = (Node *)malloc(sizeof(Node));
     node = list->head;
     int i = 0;
     while(node != NULL){
         printf("the %dth node: %d\n", i + 1, node->data);
         node = node->next;
         i++;
     }
     printf("display finished\n");
 
     return;
}
