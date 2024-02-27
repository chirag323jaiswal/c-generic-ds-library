#ifndef __TM_DLL__C
#define __TM_DLL__C 1234
#include<tm_dll.h>
#include<stdlib.h>
DoublyLinkedList * createDoublyLinkedList(bool *success)
{
DoublyLinkedList *doublyLinkedList;
if(success) *success=false;
doublyLinkedList=(DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
if(doublyLinkedList==NULL) return NULL;
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;
if(success) *success=true;
return doublyLinkedList;
}
void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success)
{
DoublyLinkedListNode *node;
if(success) *success=false;
if(doublyLinkedList==NULL) return;
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL) return;
node->ptr=ptr;
node->next=NULL;
node->previous=NULL;
if(doublyLinkedList->start==NULL)
{
doublyLinkedList->start=node;
doublyLinkedList->end=node;
}
else
{
doublyLinkedList->end->next=node;
node->previous=doublyLinkedList->end;
doublyLinkedList->end=node;
}
doublyLinkedList->size++;
if(success) *success=true;
}
void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,void *ptr,bool *success)
{
DoublyLinkedListNode *node,*p1;
int x;
if(success) *success=false;
if(doublyLinkedList==NULL) return;
if(index<0 || index>doublyLinkedList->size) return;
if(index==doublyLinkedList->size)
{
addToDoublyLinkedList(doublyLinkedList,ptr,success);
return;
}
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL) return;
node->ptr=ptr;
node->next=NULL;
node->previous=NULL;
if(index==0)
{
node->next=doublyLinkedList->start;
doublyLinkedList->start->previous=node;
doublyLinkedList->start=node;
doublyLinkedList->size++;
if(success) *success=true;
return;
}
p1=doublyLinkedList->start;
x=0;
while(x<index)
{
p1=p1->next;
x++;
}
node->next=p1;
node->previous=p1->previous;
p1->previous->next=node;
p1->previous=node;
doublyLinkedList->size++;
if(success) *success=true;
}
void * removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)
{
DoublyLinkedListNode *p1;
int x;
void *ptr=NULL;
if(success) *success=false;
if(doublyLinkedList==NULL) return NULL;
if(doublyLinkedList->start==NULL) return NULL;
if(index<0 || index>=doublyLinkedList->size) return NULL;
p1=doublyLinkedList->start;
x=0;
while(x<index)
{
p1=p1->next;
x++;
}
ptr=p1->ptr;
if(doublyLinkedList->start==p1 && doublyLinkedList->end==p1)
{
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
}else if(doublyLinkedList->start==p1)
{
doublyLinkedList->start=doublyLinkedList->start->next;
doublyLinkedList->start->previous=NULL;
}
else if(doublyLinkedList->end==p1)
{
doublyLinkedList->end=doublyLinkedList->end->previous;
doublyLinkedList->end->next=NULL;
}else
{
p1->previous->next=p1->next;
p1->next->previous=p1->previous;
}
free(p1);
doublyLinkedList->size--;
if(success) *success=true;
return ptr;
}
void * getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)
{
DoublyLinkedListNode *node;
int x;
if(success) *success=false;
if(doublyLinkedList==NULL) return NULL;
if(doublyLinkedList->start==NULL) return NULL;
if(index<0 || index>=doublyLinkedList->size) return NULL;
x=0;
node=doublyLinkedList->start;
while(x<index)
{
node=node->next;
x++;
}
if(success) *success=true;
return node->ptr;
}
void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList *sourceDoublyLinkedList,bool *success)
{
DoublyLinkedListNode *node,*t,*s,*e;
bool done;
if(success) *success=false;
if(targetDoublyLinkedList==NULL) return;
if(sourceDoublyLinkedList==NULL || sourceDoublyLinkedList->size==0) 
{
if(success) *success=true;
return;
}
s=NULL;
e=NULL;
t=sourceDoublyLinkedList->start;
done=true;
while(t!=NULL)
{
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL)
{
done=false;
break;
}
node->ptr=t->ptr;
node->next=NULL;
node->previous=NULL;
if(s==NULL)
{
s=node;
e=node;
}
else
{
e->next=node;
node->previous=e;
e=node;
}
t=t->next;
}
if(done==false)
{
while(s!=NULL)
{
node=s;
s=s->next;
free(node);
}
return;
}
if(targetDoublyLinkedList->start==NULL)
{
targetDoublyLinkedList->start=s;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size=sourceDoublyLinkedList->size;
}
else
{
targetDoublyLinkedList->end->next=s;
s->previous=targetDoublyLinkedList->end;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size+=sourceDoublyLinkedList->size;
}
if(success) *success=true;
}
int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL || doublyLinkedList->start==NULL) return 0;
return doublyLinkedList->size;
}
void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
DoublyLinkedListNode *node;
if(doublyLinkedList==NULL) return;
if(doublyLinkedList->start==NULL) return;
while(doublyLinkedList->start!=NULL)
{
node=doublyLinkedList->start;
doublyLinkedList->start=doublyLinkedList->start->next;
free(node);
}
doublyLinkedList->size=0;
}
void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL) return;
clearDoublyLinkedList(doublyLinkedList);
free(doublyLinkedList);
}
DoublyLinkedListForwardIterator getDoublyLinkedListForwardIterator(DoublyLinkedList *doublyLinkedList,bool *success)
{
DoublyLinkedListForwardIterator doublyLinkedListForwardIterator;
doublyLinkedListForwardIterator.node=NULL;
if(success) *success=false;
if(doublyLinkedList==NULL) return doublyLinkedListForwardIterator;
if(doublyLinkedList->start==NULL) 
{
if(success) *success=true;
return doublyLinkedListForwardIterator;
}
doublyLinkedListForwardIterator.node=doublyLinkedList->start;
if(success) *success=true;
return doublyLinkedListForwardIterator;
}
DoublyLinkedListReverseIterator getDoublyLinkedListReverseIterator(DoublyLinkedList *doublyLinkedList,bool *success)
{
DoublyLinkedListReverseIterator doublyLinkedListReverseIterator;
doublyLinkedListReverseIterator.node=NULL;
if(success) *success=false;
if(doublyLinkedList==NULL) return doublyLinkedListReverseIterator;
if(doublyLinkedList->start==NULL) 
{
if(success) *success=true;
return doublyLinkedListReverseIterator;
}
doublyLinkedListReverseIterator.node=doublyLinkedList->end;
if(success) *success=true;
return doublyLinkedListReverseIterator;
}
bool hasNextInDoublyLinkedList(DoublyLinkedListForwardIterator *doublyLinkedListForwardIterator)
{
if(doublyLinkedListForwardIterator==NULL) return false;
if(doublyLinkedListForwardIterator->node==NULL) return false;
return true;
}
bool hasPreviousInDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator)
{
if(doublyLinkedListReverseIterator==NULL) return false;
if(doublyLinkedListReverseIterator->node==NULL) return false;
return true;
}
void * getNextElementFromDoublyLinkedList(DoublyLinkedListForwardIterator *doublyLinkedListForwardIterator,bool *success)
{
void *ptr=NULL;
if(success) *success=false;
if(doublyLinkedListForwardIterator==NULL) return ptr;
if(doublyLinkedListForwardIterator->node==NULL) return ptr;
ptr=(void *)doublyLinkedListForwardIterator->node->ptr;
doublyLinkedListForwardIterator->node=doublyLinkedListForwardIterator->node->next;
if(success) *success=true;
return ptr;
}
void * getPreviousElementFromDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator,bool *success)
{
void *ptr=NULL;
if(success) *success=false;
if(doublyLinkedListReverseIterator==NULL) return ptr;
if(doublyLinkedListReverseIterator->node==NULL) return ptr;
ptr=(void *)doublyLinkedListReverseIterator->node->ptr;
doublyLinkedListReverseIterator->node=doublyLinkedListReverseIterator->node->previous;
if(success) *success=true;
return ptr;
}
#endif