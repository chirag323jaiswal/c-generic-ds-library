#include<tm_avl_tree.h>
#include<stdlib.h>
AVLTree * createAVLTree(bool *success,int (*predicate)(void *,void *))
{
if(success) *success=false;
AVLTree *avlTree;
avlTree=(AVLTree *)malloc(sizeof(AVLTree));
if(avlTree==NULL || predicate==NULL) return NULL;
avlTree->start=NULL;
avlTree->predicate=predicate;
avlTree->size=0;
if(success) *success=true;
return avlTree;
} 
void insertIntoAVLTree(AVLTree *avlTree,void *ptr,bool *success) 
{
AVLTreeNode *j,*t;
Stack *stack;
int succ;
int weight;
if(success) *success=false;
if(avlTree==NULL) return;
if(avlTree->start==NULL)
{
t=(AVLTreeNode *)malloc(sizeof(AVLTreeNode));
if(t==NULL) return;
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
avlTree->start=t;
avlTree->size++;
if(success) *success=true;
return;
}
stack=createStack(&succ);
if(succ==false) return; 
j=avlTree->start;
while(1)
{
weight=avlTree->predicate(ptr,j->ptr);
if(weight==0) return;
pushOnStack(stack,j,&succ);
if(succ==false)
{
destroyStack(stack);
return;
}
if(weight<0)
{
if(j->left==NULL)
{
t=(AVLTreeNode *)malloc(sizeof(AVLTreeNode));
if(t==NULL) return;
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
j->left=t;
break;
}
else
{
j=j->left;
}
}
else
{
if(j->right==NULL)
{
t=(AVLTreeNode *)malloc(sizeof(AVLTreeNode));
if(t==NULL) return;
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
j->right=t;
break;
}
else
{
j=j->right;
}
}
}
if(success) *success=true;
avlTree->size++;
balanceAVLTree(avlTree,stack);
destroyStack(stack);
} 
int getSizeOfAVLTree(AVLTree *avlTree) 
{
if(avlTree==NULL) return 0;
return avlTree->size;
} 
void destroyAVLTree(AVLTree *avlTree) 
{
if(avlTree==NULL) return;
clearAVLTree(avlTree);
free(avlTree);
} 
AVLTreeInOrderIterator getAVLTreeInOrderIterator(AVLTree *avlTree,bool *success) 
{
int succ;
AVLTreeNode *t;
AVLTreeInOrderIterator avlTreeInOrderIterator;
avlTreeInOrderIterator.node=NULL;
avlTreeInOrderIterator.stack=NULL;
if(success) *success=false;
if(avlTree==NULL) return avlTreeInOrderIterator;
if(avlTree->start==NULL) 
{
if(success) *success=true;
return avlTreeInOrderIterator;
}
avlTreeInOrderIterator.stack=createStack(&succ);
if(succ==false) return avlTreeInOrderIterator;
t=avlTree->start;
while(t!=NULL)
{
pushOnStack(avlTreeInOrderIterator.stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(avlTreeInOrderIterator.stack);
avlTreeInOrderIterator.stack=NULL;
return avlTreeInOrderIterator;
}
t=t->left;
}
avlTreeInOrderIterator.node=(AVLTreeNode *)popFromStack(avlTreeInOrderIterator.stack,&succ);
if(success) *success=true;
return avlTreeInOrderIterator;
} 
bool hasNextInOrderElementInAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator) 
{
if(avlTreeInOrderIterator==NULL || avlTreeInOrderIterator->node==NULL) return false;
return true;
} 
void * getNextInOrderElementFromAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator,bool *success) 
{
AVLTreeNode *j,*t;
int succ;
if(success) *success=false;
if(avlTreeInOrderIterator==NULL || avlTreeInOrderIterator->node==NULL) return NULL;
j=avlTreeInOrderIterator->node;
t=j->right;
while(t!=NULL)
{
pushOnStack(avlTreeInOrderIterator->stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(avlTreeInOrderIterator->stack);
avlTreeInOrderIterator->stack==NULL;
avlTreeInOrderIterator->node==NULL;
if(success) *success=true;
return j->ptr;
}
t=t->left;
}
if(isStackEmpty(avlTreeInOrderIterator->stack))
{
destroyStack(avlTreeInOrderIterator->stack);
avlTreeInOrderIterator->stack==NULL;
avlTreeInOrderIterator->node=NULL;
}
else
{
avlTreeInOrderIterator->node=(AVLTreeNode *)popFromStack(avlTreeInOrderIterator->stack,&succ);
}
if(success) *success=true;
return j->ptr;
} 

AVLTreePreOrderIterator getAVLTreePreOrderIterator(AVLTree *avlTree,bool *success)
{
int succ;
AVLTreeNode *t;
AVLTreePreOrderIterator avlTreePreOrderIterator;
avlTreePreOrderIterator.node=NULL;
avlTreePreOrderIterator.stack=NULL;
if(success) *success=false;
if(avlTree==NULL) return avlTreePreOrderIterator;
if(avlTree->start==NULL) 
{
if(success) *success=true;
return avlTreePreOrderIterator;
}
avlTreePreOrderIterator.stack=createStack(&succ);
if(succ==false) return avlTreePreOrderIterator;
avlTreePreOrderIterator.node=avlTree->start;
if(success) *success=true;
return avlTreePreOrderIterator;
}
bool hasNextPreOrderElementInAVLTree(AVLTreePreOrderIterator *avlTreePreOrderIterator)
{
if(avlTreePreOrderIterator==NULL || avlTreePreOrderIterator->node==NULL) return false;
return true;
}
void * getNextPreOrderElementFromAVLTree(AVLTreePreOrderIterator *avlTreePreOrderIterator,bool *success)
{
AVLTreeNode *j,*t;
int succ;
if(success) *success=false;
if(avlTreePreOrderIterator==NULL) return NULL;
if(avlTreePreOrderIterator->node==NULL) return NULL;
j=avlTreePreOrderIterator->node;
if(j->right!=NULL)
{
pushOnStack(avlTreePreOrderIterator->stack,(void *)j->right,&succ);
if(succ==false)
{
destroyStack(avlTreePreOrderIterator->stack);
avlTreePreOrderIterator->stack=NULL;
avlTreePreOrderIterator->node=NULL;
if(success) *success=true;
return j->ptr;
}
}
if(j->left!=NULL)
{
pushOnStack(avlTreePreOrderIterator->stack,(void *)j->left,&succ);
if(succ==false)
{
destroyStack(avlTreePreOrderIterator->stack);
avlTreePreOrderIterator->stack=NULL;
avlTreePreOrderIterator->node=NULL;
if(success) *success=true;
return j->ptr;
}
}
if(isStackEmpty(avlTreePreOrderIterator->stack))
{
destroyStack(avlTreePreOrderIterator->stack);
avlTreePreOrderIterator->stack=NULL;
avlTreePreOrderIterator->node=NULL;
}
else
{
avlTreePreOrderIterator->node=(AVLTreeNode *)popFromStack(avlTreePreOrderIterator->stack,&succ);
}
if(success) *success=true;
return j->ptr;
}
AVLTreePostOrderIterator getAVLTreePostOrderIterator(AVLTree *avlTree,bool *success)
{
AVLTreeNode *t;
int succ;
AVLTreePostOrderIterator avlTreePostOrderIterator;
avlTreePostOrderIterator.node=NULL;
avlTreePostOrderIterator.stack=NULL;
if(success) *success=false;
if(avlTree==NULL) return avlTreePostOrderIterator;
if(avlTree->start==NULL) 
{
if(success) *success=true;
return avlTreePostOrderIterator;
}
avlTreePostOrderIterator.stack=createStack(&succ);
if(succ==false) return avlTreePostOrderIterator;
t=avlTree->start;
while(1)
{
while(t!=NULL)
{
if(t->right!=NULL)
{
pushOnStack(avlTreePostOrderIterator.stack,(void *)t->right,&succ);
}
pushOnStack(avlTreePostOrderIterator.stack,(void *)t,&succ);
t=t->left;
} 
t=popFromStack(avlTreePostOrderIterator.stack,&succ);
if(!isStackEmpty(avlTreePostOrderIterator.stack) && t->right!=NULL && t->right==elementAtTopOfStack(avlTreePostOrderIterator.stack,&succ))
{
popFromStack(avlTreePostOrderIterator.stack,&succ);
pushOnStack(avlTreePostOrderIterator.stack,(void *)t,&succ);
t=t->right;
}
else
{
break;
}
}
avlTreePostOrderIterator.node=t;
if(success) *success=true;
return avlTreePostOrderIterator;
}
bool hasNextPostOrderElementInAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator)
{
if(avlTreePostOrderIterator==NULL || avlTreePostOrderIterator->node==NULL)
{
return false;
}
return true;
}
void * getNextPostOrderElementFromAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator,bool *success)
{
AVLTreeNode *t,*j;
int succ;
if(success) *success=false;
if(avlTreePostOrderIterator==NULL) return NULL;
if(avlTreePostOrderIterator->node==NULL) return NULL;
j=avlTreePostOrderIterator->node;
if(isStackEmpty(avlTreePostOrderIterator->stack))
{
avlTreePostOrderIterator->node=NULL;
destroyStack(avlTreePostOrderIterator->stack);
if(success) *success=true;
return j->ptr;
}
t=NULL;
while(1)
{
while(t!=NULL)
{
if(t->right!=NULL)
{
pushOnStack(avlTreePostOrderIterator->stack,(void *)t->right,&succ);
}
pushOnStack(avlTreePostOrderIterator->stack,(void *)t,&succ);
t=t->left;
} 
t=popFromStack(avlTreePostOrderIterator->stack,&succ);
if(!isStackEmpty(avlTreePostOrderIterator->stack) && t->right!=NULL && t->right==elementAtTopOfStack(avlTreePostOrderIterator->stack,&succ))
{
popFromStack(avlTreePostOrderIterator->stack,&succ);
pushOnStack(avlTreePostOrderIterator->stack,(void *)t,&succ);
t=t->right;
}
else
{
break;
}
}
avlTreePostOrderIterator->node=t;
if(success) *success=true;
return j->ptr;
}

void * getFromAVLTree(AVLTree *avlTree,void *ptr,bool *success) 
{
int weight;
AVLTreeNode *t;
if(success) *success=false;
if(avlTree==NULL || avlTree->start==NULL) return NULL;
t=avlTree->start;
while(t!=NULL)
{
weight=avlTree->predicate(ptr,t->ptr);
if(weight==0) 
{
if(success) *success=true;
return t->ptr;
}
if(weight<0) t=t->left;
else t=t->right;
}
return NULL;
}
void * removeFromAVLTree(AVLTree *avlTree,void *ptr,bool *success) 
{
int weight;
AVLTreeNode *t,*j,*e,*f;
AVLTreeNode **p2p;
Stack *stack;
Queue *queue;
void *foundPtr;
bool succ;
if(success) *success=false;
stack=createStack(&succ);
if(succ==false) return NULL;
queue=createQueue(&succ);
if(succ==false) return NULL;
if(avlTree==NULL || avlTree->start==NULL) return NULL;
t=avlTree->start;
while(t!=NULL)
{
weight=avlTree->predicate(ptr,t->ptr);
if(weight==0) break;
j=t;
pushOnStack(stack,(void *)j,&succ);
if(succ==false)
{
destroyStack(stack);
return NULL;
}
if(weight<0) t=t->left;
else t=t->right;
}
if(t==NULL) return NULL;
foundPtr=t->ptr;
if(avlTree->start==t) p2p=&(avlTree->start);
else if(j->left==t) p2p=&(j->left);
else p2p=&(j->right);
if(t->left==t->right) *p2p=NULL;
else
{
if(t->right!=NULL)
{
for(e=t->right;e->left!=NULL;e=e->left) 
{
addToQueue(queue,(void *)e,&succ);
if(succ==false)
{
destroyStack(stack);
destroyQueue(queue);
return NULL;
}
f=e;
}
pushOnStack(stack,(void *)e,&succ);
if(succ==false)
{
destroyStack(stack);
destroyQueue(queue);
return NULL;
}
while(!isQueueEmpty(queue))
{
pushOnStack(stack,(void *)removeFromQueue(queue,&succ),&succ);
if(succ==false)
{
destroyStack(stack);
destroyQueue(queue);
return NULL;
}
}
if(t->right==e)
{
e->left=t->left;
}
else
{
f->left=e->right;
e->left=t->left;
e->right=t->right;
} 
}
else
{
for(e=t->left;e->right!=NULL;e=e->right) 
{
addToQueue(queue,(void *)e,&succ);
if(succ==false)
{
destroyStack(stack);
destroyQueue(queue);
return NULL;
}
f=e;
}
pushOnStack(stack,(void *)e,&succ);
if(succ==false)
{
destroyStack(stack);
destroyQueue(queue);
return NULL;
}
while(!isQueueEmpty(queue))
{
pushOnStack(stack,(void *)removeFromQueue(queue,&succ),&succ);
if(succ==false)
{
destroyStack(stack);
destroyQueue(queue);
return NULL;
}
}
if(t->left==e)
{
e->right=t->right;
}
else
{
f->right=e->left;
e->right=t->right;
e->left=t->left;
} 
}
*p2p=e;
free(t);
avlTree->size--;
balanceAVLTree(avlTree,stack);
if(success) *success=true;
return foundPtr;
}  
int getHeightOfAVLTree(AVLTreeNode *root)
{
int leftTreeHeight,rightTreeHeight;
if(root==NULL) return 0;
leftTreeHeight=getHeightOfAVLTree(root->left);
rightTreeHeight=getHeightOfAVLTree(root->right);
return (leftTreeHeight>rightTreeHeight)?(leftTreeHeight+1):(rightTreeHeight+1);
}
void balanceAVLTree(AVLTree *avlTree,Stack *stack)
{
AVLTreeNode **p2p;
AVLTreeNode *lc,*rc,*lcrc,*rclc,*root,*parent;
int diff,lh,rh,succ;
if(stack==NULL) return;
if(isStackEmpty(stack)) return;
while(!isStackEmpty(stack))
{
root=(AVLTreeNode *)popFromStack(stack,&succ);
lh=getHeightOfAVLTree(root->left);
rh=getHeightOfAVLTree(root->right);
diff=lh-rh;
if(diff>=-1 && diff<=1) continue;
if(isStackEmpty(stack))
{
p2p=&(avlTree->start);
}
else
{
parent=elementAtTopOfStack(stack,&succ);
if(root==parent->left) p2p=&(parent->left);
else p2p=&(parent->right);
}
if(rh>lh)
{
rc=root->right;
if(getHeightOfAVLTree(rc->left)>getHeightOfAVLTree(rc->right))
{
rclc=rc->left;
rc->left=rclc->right;
rclc->right=rc;
root->right=rclc;
rc=root->right;
}
root->right=rc->left;
rc->left=root;
*p2p=rc;
}
else
{
lc=root->left;
if(getHeightOfAVLTree(lc->right)>getHeightOfAVLTree(lc->left))
{
lcrc=lc->right;
lc->right=lcrc->left;
lcrc->left=lc;
root->left=lcrc;
lc=root->left;
}
root->left=lc->right;
lc->right=root;
*p2p=lc;
}
}
}
void clearAVLTree(AVLTree *avlTree) 
{
AVLTreeNode *t;
Stack *stack;
bool success;
if(avlTree==NULL || avlTree->start==NULL) return;
stack=createStack(&success);
if(success==false) return; 
t=avlTree->start;
while(1)
{
while(t!=NULL)
{
if(t->right!=NULL)
{
pushOnStack(stack,(void *)t->right,&success);
if(success==false) return;
}
pushOnStack(stack,(void *)t,&success);
if(success==false) return;
t=t->left;
} 
t=popFromStack(stack,&success);
if(success==false) return;
if(!isStackEmpty(stack) && t->right!=NULL && t->right==elementAtTopOfStack(stack,&success))
{
popFromStack(stack,&success);
if(success==false) return;
pushOnStack(stack,(void *)t,&success);
if(success==false) return;
t=t->right;
}
else
{
free(t);
t=NULL;
}
if(isStackEmpty(stack)) break;
}
}
} 











