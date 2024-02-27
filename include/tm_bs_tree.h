#ifndef __TM_BS_TREE__H
#define __TM_BS_TREE__H 1234
#include<tm_common.h>
#include<tm_stack.h>
typedef struct __$_tm_bs_tree_node
{
void *ptr;
struct __$_tm_bs_tree_node *left;
struct __$_tm_bs_tree_node *right;
}BSTreeNode;
typedef struct __$_tm_bs_tree
{
struct __$_tm_bs_tree_node *start;
int (*predicate)(void *,void *);
int size;
}BSTree;
typedef struct __$_tm_bs_tree_in_order_iterator
{
BSTreeNode *node;
Stack *stack;
}BSTreeInOrderIterator;
typedef struct __$_tm_bs_tree_pre_order_iterator
{
BSTreeNode *node;
Stack *stack;
}BSTreePreOrderIterator;
typedef struct __$_tm_bs_tree_post_order_iterator
{
BSTreeNode *node;
Stack *stack;
}BSTreePostOrderIterator;
BSTree * createBSTree(bool *success,int (*predicate)(void *,void *));
void insertIntoBSTree(BSTree *bsTree,void *ptr,bool *success);
void * removeFromBSTree(BSTree *bsTree,void *ptr,bool *success);
void * getFromBSTree(BSTree *bsTree,void *ptr,bool *success);
int getSizeOfBSTree(BSTree *bsTree);
void clearBSTree(BSTree *bsTree);
void destroyBSTree(BSTree *bsTree);
BSTreeInOrderIterator getBSTreeInOrderIterator(BSTree *bsTree,bool *success);
bool hasNextInOrderElementInBSTree(BSTreeInOrderIterator *bsTreeInOrderIterator);
void * getNextInOrderElementFromBSTree(BSTreeInOrderIterator *bsTreeInOrderIterator,bool *success);
BSTreePreOrderIterator getBSTreePreOrderIterator(BSTree *bsTree,bool *success);
bool hasNextPreOrderElementInBSTree(BSTreePreOrderIterator *bsTreePreOrderIterator);
void * getNextPreOrderElementFromBSTree(BSTreePreOrderIterator *bsTreePreOrderIterator,bool *success);
BSTreePostOrderIterator getBSTreePostOrderIterator(BSTree *bsTree,bool *success);
bool hasNextPostOrderElementInBSTree(BSTreePostOrderIterator *bsTreePostOrderIterator);
void * getNextPostOrderElementFromBSTree(BSTreePostOrderIterator *bsTreePostOrderIterator,bool *success);
int getHeightOfBSTree(BSTreeNode *root);
#endif