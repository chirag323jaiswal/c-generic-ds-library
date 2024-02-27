#include<stdio.h>
#include<tm_stack.h>
int main()
{
Stack *stack;
int i1,i2,i3,i4,i5,i6,y;
int *x;
bool succ;
i1=10;
i2=20;
i3=30;
i4=40;
i5=50;
i6=60;
stack=createStack(&succ);
if(succ) printf("Stack created\n");
else printf("Unable to create stack\n");
pushOnStack(stack,&i1,&succ);
if(succ) printf("%d pushed on stack\n",i1);
pushOnStack(stack,&i2,&succ);
if(succ) printf("%d pushed on stack\n",i2);
pushOnStack(stack,&i3,&succ);
if(succ) printf("%d pushed on stack\n",i3);
pushOnStack(stack,&i4,&succ);
if(succ) printf("%d pushed on stack\n",i4);
pushOnStack(stack,&i5,&succ);
if(succ) printf("%d pushed on stack\n",i5);
pushOnStack(stack,&i6,&succ);
if(succ) printf("%d pushed on stack\n",i6);
printf("Size of stack is : %d\n",getSizeOfStack(stack));
x=(int *)elementAtTopOfStack(stack,&succ);
if(succ) printf("Element at top of stack is : %d\n",*x);
printf("popping from stack\n");
while(!isStackEmpty(stack))
{
x=(int *)popFromStack(stack,&succ);
if(succ) printf("%d popped from stack\n",*x);
}
clearStack(stack);
printf("Size of stack is : %d\n",getSizeOfStack(stack));
destroyStack(stack);
return 0;
}