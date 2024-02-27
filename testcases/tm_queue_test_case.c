#include<tm_queue.h>
#include<stdio.h>
int main()
{
Queue *queue;
int i1,i2,i3,i4,i5,i6,y;
int *x;
bool succ;
i1=10;
i2=20;
i3=30;
i4=40;
i5=50;
i6=60;
queue=createQueue(&succ);
if(succ) printf("Queue created\n");
addToQueue(queue,&i1,&succ);
if(succ) printf("%d added to queue\n",i1);
addToQueue(queue,&i2,&succ);
if(succ) printf("%d added to queue\n",i2);
addToQueue(queue,&i3,&succ);
if(succ) printf("%d added to queue\n",i3);
addToQueue(queue,&i4,&succ);
if(succ) printf("%d added to queue\n",i4);
addToQueue(queue,&i5,&succ);
if(succ) printf("%d added to queue\n",i5);
addToQueue(queue,&i6,&succ);
if(succ) printf("%d added to queue\n",i6);
printf("Size of queue is : %d\n",getSizeOfQueue(queue));
x=(int *)elementAtFrontOfQueue(queue,&succ);
if(succ) printf("Element at front of queue : %d\n",*x);
else printf("Unable to print element at top of queue\n");
printf("Removing elements from queue\n");
while(!isQueueEmpty(queue))
{
x=(int *)removeFromQueue(queue,&succ);
if(succ) printf("%d removed from queue\n",*x);
}
destroyQueue(queue);
printf("Size of queue is : %d\n",getSizeOfQueue(queue));
return 0;
}