#include<tm_avl_tree.h>
#include<stdio.h>
#include<stdlib.h>
int myComparator(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}
int main()
{
AVLTree *tree;
AVLTreeInOrderIterator InOrderIterator;
AVLTreePreOrderIterator PreOrderIterator;
AVLTreePostOrderIterator PostOrderIterator;
int num,succ,ch;
int *x;
char more;
tree=createAVLTree(&succ,myComparator);
if(succ==false) 
{
printf("Unable to create tree\n");
return 0;
}
while(1)
{
printf("1.Insert\n");
printf("2.InOrder traversal\n");
printf("3.Remove\n");
printf("4.Search\n");
printf("5.PreOrder traversal\n");
printf("6.PostOrder traversal\n");
printf("7.Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("Enter a number to insert in tree : ");
scanf("%d",&num);
fflush(stdin);
x=(int *)malloc(sizeof(int));
*x=num;
insertIntoAVLTree(tree,(void *)x,&succ);
if(succ) printf("Address of container that contains %d inserted in tree\n",*x);
else printf("Unable to insert %d in tree\n",*x);
}else if(ch==2)
{
printf("Inorder iteration starts\n");
InOrderIterator=getAVLTreeInOrderIterator(tree,&succ);
if(succ)
{
while(hasNextInOrderElementInAVLTree(&InOrderIterator))
{
x=(int *)getNextInOrderElementFromAVLTree(&InOrderIterator,&succ);
if(succ) printf("%d\n",*x);
}
}
}else if(ch==3)
{
printf("Enter a number to remove : ");
scanf("%d",&num);
fflush(stdin);
x=removeFromAVLTree(tree,&num,&succ);
if(succ) printf("%d found and removed\n",*x);
else printf("%d not found\n",num);
}else if(ch==4)
{
printf("Enter a number to search : ");
scanf("%d",&num);
fflush(stdin);
x=getFromAVLTree(tree,&num,&succ);
if(succ) printf("%d found\n",*x);
else printf("%d not found\n",num);
}else if(ch==5) 
{
printf("preOrder iteration starts\n");
PreOrderIterator=getAVLTreePreOrderIterator(tree,&succ);
if(succ)
{
while(hasNextPreOrderElementInAVLTree(&PreOrderIterator))
{
x=(int *)getNextPreOrderElementFromAVLTree(&PreOrderIterator,&succ);
printf("%d\n",*x);
}
}
}else if(ch==6)
{
printf("postOrder iteration starts\n");
PostOrderIterator=getAVLTreePostOrderIterator(tree,&succ);
if(succ)
{
while(hasNextPostOrderElementInAVLTree(&PostOrderIterator))
{
x=(int *)getNextPostOrderElementFromAVLTree(&PostOrderIterator,&succ);
if(succ) printf("%d\n",*x);
}
}
}else break;
}
destroyAVLTree(tree);
return 0;
}
