# c-generic-ds-library

-- GENERICS --

Implemented Data Structures - 

1) Stack

2) Queue

3) Singly Linked List

4) Doubly Linked List

5) Binary Search Tree (BST)

6) Adelson-Velsky and Landis (AVL) Tree 

Header File Names - 

1) tm_stack.h

2) tm_queue.h

3) tm_sll.h

4) tm_dll.h

5) tm_bs_tree.h

6) tm_avl_tree.h

Library name - tm_ds.lib

To Compile - gcc demo.c -o demo.exe -I ..\include -L..\lib -ltm_ds

For Using Tree Data Structure Library - 

* User have to write the comparator function which will be used by the data structure to compare values.
  
* Comparator function should use the relational operators to compare the primary key values weight.

* Comparator function after comparision, should return one of the possible values (-1,0,1).

* Our DS will pass the two arguments of void * type to the comparator function.

* Our DS will assume 

    0 --> left == right

   -1 --> left < right

    1 --> left > right 
