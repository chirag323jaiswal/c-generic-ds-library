#include<stdio.h>
#include<tm_dll.h>
int main()
{
DoublyLinkedList *list1;
DoublyLinkedListForwardIterator forward_iter;
DoublyLinkedListReverseIterator reverse_iter;
int i1,i2,i3,i4;
int *x;
bool succ;
i1=10;
i2=20;
i3=30;
i4=40;
list1=createDoublyLinkedList(&succ);
if(succ) printf("list1 created\n");
addToDoublyLinkedList(list1,(void *)&i1,&succ);
if(succ) printf("%d added to list1\n",i1);
addToDoublyLinkedList(list1,(void *)&i2,&succ);
if(succ) printf("%d added to list1\n",i2);
addToDoublyLinkedList(list1,(void *)&i3,&succ);
if(succ) printf("%d added to list1\n",i3);
addToDoublyLinkedList(list1,(void *)&i4,&succ);
if(succ) printf("%d added to list1\n",i4);
printf("Traversing from top to bottom\n");
forward_iter=getDoublyLinkedListForwardIterator(list1,&succ);
if(succ)
{
while(hasNextInDoublyLinkedList(&forward_iter))
{
x=getNextElementFromDoublyLinkedList(&forward_iter,&succ);
if(succ) printf("%d\n",*x);
}
}
printf("Traversing from bottom to top\n");
reverse_iter=getDoublyLinkedListReverseIterator(list1,&succ);
if(succ)
{
while(hasPreviousInDoublyLinkedList(&reverse_iter))
{
x=getPreviousElementFromDoublyLinkedList(&reverse_iter,&succ);
if(succ) printf("%d\n",*x);
}
}
return 0;
}