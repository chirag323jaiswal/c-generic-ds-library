#include<stdio.h>
#include<tm_sll.h>
int main()
{
int i1,i2,i3,i4,i5,y;
int *x;
bool succ;
SinglyLinkedList *list1;
SinglyLinkedListIterator iter;
i1=10;
i2=20;
i3=30;
i4=40;
i5=50;
list1=createSinglyLinkedList(&succ);
if(succ) printf("list1 created\n");
else printf("Unable to create list1");
addToSinglyLinkedList(list1,&i1,&succ);
if(succ) printf("%d added to list1\n",i1);
addToSinglyLinkedList(list1,&i2,&succ);
if(succ) printf("%d added to list1\n",i2);
addToSinglyLinkedList(list1,&i3,&succ);
if(succ) printf("%d added to list1\n",i3);
addToSinglyLinkedList(list1,&i4,&succ);
if(succ) printf("%d added to list1\n",i4);
addToSinglyLinkedList(list1,&i5,&succ);
if(succ) printf("%d added to list1\n",i5);
iter=getSinglyLinkedListIterator(list1,&succ);
if(succ) 
{
while(hasNextInSinglyLinkedList(&iter))
{
x=(int *)getNextElementFromSinglyLinkedList(&iter,&succ);
if(succ) printf("%d\n",*x);
}
}
return 0;
}