#include<tm_bs_tree.h>
#include<stdlib.h>
BSTree * createBSTree(bool *success,int (*predicate)(void *,void *))
{
if(success) *success=false;
BSTree *bsTree;
bsTree=(BSTree *)malloc(sizeof(BSTree));
if(bsTree==NULL || predicate==NULL) return NULL;
bsTree->start=NULL;
bsTree->predicate=predicate;
bsTree->size=0;
if(success) *success=true;
return bsTree;
} 
void insertIntoBSTree(BSTree *bsTree,void *ptr,bool *success) 
{
BSTreeNode *j,*t;
int succ;
int weight;
if(success) *success=false;
if(bsTree==NULL) return;
if(bsTree->start==NULL)
{
t=(BSTreeNode *)malloc(sizeof(BSTreeNode));
if(t==NULL) return;
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
bsTree->start=t;
bsTree->size++;
if(success) *success=true;
return;
}
j=bsTree->start;
while(1)
{
weight=bsTree->predicate(ptr,j->ptr);
if(weight==0) return;
if(weight<0)
{
if(j->left==NULL)
{
t=(BSTreeNode *)malloc(sizeof(BSTreeNode));
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
t=(BSTreeNode *)malloc(sizeof(BSTreeNode));
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
bsTree->size++;
} 
int getSizeOfBSTree(BSTree *bsTree) 
{
if(bsTree==NULL) return 0;
return bsTree->size;
} 
void destroyBSTree(BSTree *bsTree) 
{
if(bsTree==NULL) return;
clearBSTree(bsTree);
free(bsTree);
} 
BSTreeInOrderIterator getBSTreeInOrderIterator(BSTree *bsTree,bool *success) 
{
int succ;
BSTreeNode *t;
BSTreeInOrderIterator bsTreeInOrderIterator;
bsTreeInOrderIterator.node=NULL;
bsTreeInOrderIterator.stack=NULL;
if(success) *success=false;
if(bsTree==NULL) return bsTreeInOrderIterator;
if(bsTree->start==NULL) 
{
if(success) *success=true;
return bsTreeInOrderIterator;
}
bsTreeInOrderIterator.stack=createStack(&succ);
if(succ==false) return bsTreeInOrderIterator;
t=bsTree->start;
while(t!=NULL)
{
pushOnStack(bsTreeInOrderIterator.stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(bsTreeInOrderIterator.stack);
bsTreeInOrderIterator.stack=NULL;
return bsTreeInOrderIterator;
}
t=t->left;
}
bsTreeInOrderIterator.node=(BSTreeNode *)popFromStack(bsTreeInOrderIterator.stack,&succ);
if(success) *success=true;
return bsTreeInOrderIterator;
} 
bool hasNextInOrderElementInBSTree(BSTreeInOrderIterator *bsTreeInOrderIterator) 
{
if(bsTreeInOrderIterator==NULL || bsTreeInOrderIterator->node==NULL) return false;
return true;
} 
void * getNextInOrderElementFromBSTree(BSTreeInOrderIterator *bsTreeInOrderIterator,bool *success) 
{
BSTreeNode *j,*t;
int succ;
if(success) *success=false;
if(bsTreeInOrderIterator==NULL || bsTreeInOrderIterator->node==NULL) return NULL;
j=bsTreeInOrderIterator->node;
t=j->right;
while(t!=NULL)
{
pushOnStack(bsTreeInOrderIterator->stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(bsTreeInOrderIterator->stack);
bsTreeInOrderIterator->stack==NULL;
bsTreeInOrderIterator->node==NULL;
if(success) *success=true;
return j->ptr;
}
t=t->left;
}
if(isStackEmpty(bsTreeInOrderIterator->stack))
{
destroyStack(bsTreeInOrderIterator->stack);
bsTreeInOrderIterator->stack==NULL;
bsTreeInOrderIterator->node=NULL;
}
else
{
bsTreeInOrderIterator->node=(BSTreeNode *)popFromStack(bsTreeInOrderIterator->stack,&succ);
}
if(success) *success=true;
return j->ptr;
} 
BSTreePreOrderIterator getBSTreePreOrderIterator(BSTree *bsTree,bool *success)
{
int succ;
BSTreeNode *t;
BSTreePreOrderIterator bsTreePreOrderIterator;
bsTreePreOrderIterator.node=NULL;
bsTreePreOrderIterator.stack=NULL;
if(success) *success=false;
if(bsTree==NULL) return bsTreePreOrderIterator;
if(bsTree->start==NULL) 
{
if(success) *success=true;
return bsTreePreOrderIterator;
}
bsTreePreOrderIterator.stack=createStack(&succ);
if(succ==false) return bsTreePreOrderIterator;
bsTreePreOrderIterator.node=bsTree->start;
if(success) *success=true;
return bsTreePreOrderIterator;
}
bool hasNextPreOrderElementInBSTree(BSTreePreOrderIterator *bsTreePreOrderIterator)
{
if(bsTreePreOrderIterator==NULL || bsTreePreOrderIterator->node==NULL) return false;
return true;
}
void * getNextPreOrderElementFromBSTree(BSTreePreOrderIterator *bsTreePreOrderIterator,bool *success)
{
BSTreeNode *j,*t;
int succ;
if(success) *success=false;
if(bsTreePreOrderIterator==NULL) return NULL;
if(bsTreePreOrderIterator->node==NULL) return NULL;
j=bsTreePreOrderIterator->node;
if(j->right!=NULL)
{
pushOnStack(bsTreePreOrderIterator->stack,(void *)j->right,&succ);
if(succ==false)
{
destroyStack(bsTreePreOrderIterator->stack);
bsTreePreOrderIterator->stack=NULL;
bsTreePreOrderIterator->node=NULL;
if(success) *success=true;
return j->ptr;
}
}
if(j->left!=NULL)
{
pushOnStack(bsTreePreOrderIterator->stack,(void *)j->left,&succ);
if(succ==false)
{
destroyStack(bsTreePreOrderIterator->stack);
bsTreePreOrderIterator->stack=NULL;
bsTreePreOrderIterator->node=NULL;
if(success) *success=true;
return j->ptr;
}
}
if(isStackEmpty(bsTreePreOrderIterator->stack))
{
destroyStack(bsTreePreOrderIterator->stack);
bsTreePreOrderIterator->stack=NULL;
bsTreePreOrderIterator->node=NULL;
}
else
{
bsTreePreOrderIterator->node=(BSTreeNode *)popFromStack(bsTreePreOrderIterator->stack,&succ);
}
if(success) *success=true;
return j->ptr;
}
BSTreePostOrderIterator getBSTreePostOrderIterator(BSTree *bsTree,bool *success)
{
BSTreeNode *t;
int succ;
BSTreePostOrderIterator bsTreePostOrderIterator;
bsTreePostOrderIterator.node=NULL;
bsTreePostOrderIterator.stack=NULL;
if(success) *success=false;
if(bsTree==NULL) return bsTreePostOrderIterator;
if(bsTree->start==NULL) 
{
if(success) *success=true;
return bsTreePostOrderIterator;
}
bsTreePostOrderIterator.stack=createStack(&succ);
if(succ==false) return bsTreePostOrderIterator;
t=bsTree->start;
while(1)
{
while(t!=NULL)
{
if(t->right!=NULL)
{
pushOnStack(bsTreePostOrderIterator.stack,(void *)t->right,&succ);
}
pushOnStack(bsTreePostOrderIterator.stack,(void *)t,&succ);
t=t->left;
} 
t=popFromStack(bsTreePostOrderIterator.stack,&succ);
if(!isStackEmpty(bsTreePostOrderIterator.stack) && t->right!=NULL && t->right==elementAtTopOfStack(bsTreePostOrderIterator.stack,&succ))
{
popFromStack(bsTreePostOrderIterator.stack,&succ);
pushOnStack(bsTreePostOrderIterator.stack,(void *)t,&succ);
t=t->right;
}
else
{
break;
}
}
bsTreePostOrderIterator.node=t;
if(success) *success=true;
return bsTreePostOrderIterator;
}
bool hasNextPostOrderElementInBSTree(BSTreePostOrderIterator *bsTreePostOrderIterator)
{
if(bsTreePostOrderIterator==NULL || bsTreePostOrderIterator->node==NULL)
{
return false;
}
return true;
}
void * getNextPostOrderElementFromBSTree(BSTreePostOrderIterator *bsTreePostOrderIterator,bool *success)
{
BSTreeNode *t,*j;
int succ;
if(success) *success=false;
if(bsTreePostOrderIterator==NULL) return NULL;
if(bsTreePostOrderIterator->node==NULL) return NULL;
j=bsTreePostOrderIterator->node;
if(isStackEmpty(bsTreePostOrderIterator->stack))
{
bsTreePostOrderIterator->node=NULL;
destroyStack(bsTreePostOrderIterator->stack);
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
pushOnStack(bsTreePostOrderIterator->stack,(void *)t->right,&succ);
}
pushOnStack(bsTreePostOrderIterator->stack,(void *)t,&succ);
t=t->left;
} 
t=popFromStack(bsTreePostOrderIterator->stack,&succ);
if(!isStackEmpty(bsTreePostOrderIterator->stack) && t->right!=NULL && t->right==elementAtTopOfStack(bsTreePostOrderIterator->stack,&succ))
{
popFromStack(bsTreePostOrderIterator->stack,&succ);
pushOnStack(bsTreePostOrderIterator->stack,(void *)t,&succ);
t=t->right;
}
else
{
break;
}
}
bsTreePostOrderIterator->node=t;
if(success) *success=true;
return j->ptr;
}
void * getFromBSTree(BSTree *bsTree,void *ptr,bool *success) 
{
int weight;
BSTreeNode *t;
if(success) *success=false;
if(bsTree==NULL || bsTree->start==NULL) return NULL;
t=bsTree->start;
while(t!=NULL)
{
weight=bsTree->predicate(ptr,t->ptr);
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
void * removeFromBSTree(BSTree *bsTree,void *ptr,bool *success) 
{
int weight;
BSTreeNode *t,*j,*e,*f;
BSTreeNode **p2p;
void *foundPtr;
if(success) *success=false;
if(bsTree==NULL || bsTree->start==NULL) return NULL;
t=bsTree->start;
while(t!=NULL)
{
weight=bsTree->predicate(ptr,t->ptr);
if(weight==0) break;
j=t;
if(weight<0) t=t->left;
else t=t->right;
}
if(t==NULL) return NULL;
foundPtr=t->ptr;
if(bsTree->start==t) p2p=&(bsTree->start);
else if(j->left==t) p2p=&(j->left);
else p2p=&(j->right);
if(t->left==t->right) *p2p=NULL;
else
{
if(t->right!=NULL)
{
for(e=t->right;e->left!=NULL;e=e->left) f=e;
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
*p2p=e;
}
else
{
for(e=t->left;e->right!=NULL;e=e->right) f=e;
if(e!=t->left)
{
f->right=e->left;
e->left=t->left;
}
*p2p=e;
}
}
free(t);
bsTree->size--;
if(success) *success=true;
return foundPtr;
}  
int getHeightOfBSTree(BSTreeNode *root)
{
int leftTreeHeight,rightTreeHeight;
if(root==NULL) return 0;
leftTreeHeight=getHeightOfBSTree(root->left);
rightTreeHeight=getHeightOfBSTree(root->right);
return (leftTreeHeight>rightTreeHeight)?(leftTreeHeight+1):(rightTreeHeight+1);
}
void clearBSTree(BSTree *bsTree) 
{
BSTreeNode *t;
Stack *stack;
bool success;
if(bsTree==NULL || bsTree->start==NULL) return;
stack=createStack(&success);
if(success==false) return; 
t=bsTree->start;
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











