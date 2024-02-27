#ifndef __TM_STACK__H
#define __TM_STACK__H 1234
#include<tm_common.h>
#include<tm_sll.h>
typedef struct __$_tm_stack
{
SinglyLinkedList *singlyLinkedList;
}Stack;
Stack * createStack(bool *success);
void clearStack(Stack *stack);
void destroyStack(Stack *stack);
void pushOnStack(Stack *stack,void *ptr,bool *success);
void * popFromStack(Stack *stack,bool *success);
void * elementAtTopOfStack(Stack *stack,bool *success);
bool isStackEmpty(Stack *stack);
int getSizeOfStack(Stack *stack);
#endif