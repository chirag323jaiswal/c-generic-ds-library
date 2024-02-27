#ifndef __TM_DLL__H
#define __TM_DLL__H 1234
#include<tm_common.h>
typedef struct __$_tm_dll_node
{
void *ptr;
struct __$_tm_dll_node *next;
struct __$_tm_dll_node *previous;
}DoublyLinkedListNode;
typedef struct __$_tm_dll
{
int size;
struct __$_tm_dll_node *start;
struct __$_tm_dll_node *end;
}DoublyLinkedList;
typedef struct __$_tm_dll_forward_iterator
{
struct __$_tm_dll_node *node;
}DoublyLinkedListForwardIterator;
typedef struct __$_tm_dll_reverse_iterator
{
struct __$_tm_dll_node *node;
}DoublyLinkedListReverseIterator;
DoublyLinkedList * createDoublyLinkedList(bool *success);
void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success);
void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,void *ptr,bool *success);
void * removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success);
void * getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success);
void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList *sourceDoublyLinkedList,bool *success);
int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
DoublyLinkedListForwardIterator getDoublyLinkedListForwardIterator(DoublyLinkedList *doublyLinkedList,bool *success);
bool hasNextInDoublyLinkedList(DoublyLinkedListForwardIterator *doublyLinkedListForwardIterator);
void * getNextElementFromDoublyLinkedList(DoublyLinkedListForwardIterator *doublyLinkedListForwardIterator,bool *success);
DoublyLinkedListReverseIterator getDoublyLinkedListReverseIterator(DoublyLinkedList *doublyLinkedList,bool *success);
bool hasPreviousInDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator);
void * getPreviousElementFromDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator,bool *success);
#endif