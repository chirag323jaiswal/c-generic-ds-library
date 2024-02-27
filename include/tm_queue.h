#ifndef __TM_QUEUE__H
#define __TM_QUEUE__H 1234
#include<tm_common.h>
#include<tm_sll.h>
typedef struct __$_tm_queue
{
SinglyLinkedList *singlyLinkedList;
}Queue;
Queue * createQueue(bool *success);
void clearQueue(Queue *queue);
void destroyQueue(Queue *queue);
void addToQueue(Queue *queue,void *ptr,bool *success);
void * removeFromQueue(Queue *queue,bool *success);
void * elementAtFrontOfQueue(Queue *queue,bool *success);
bool isQueueEmpty(Queue *queue);
int getSizeOfQueue(Queue *queue);
#endif