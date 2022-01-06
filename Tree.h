
#ifndef ASSIGMENT7_TREE_H
#define ASSIGMENT7_TREE_H

typedef struct Node {
    void *data;
    struct Node *left;
    struct Node *right;
} Node;


typedef struct{
    Node * root;
    int elementCount;
} Tree;

typedef struct LinkedList{
    void* data;
    struct LinkedList *next;
}LinkedList;


void* createTree(); /* creates tree data base  */

int addNewNode(Tree *tree, void *(*givenNode)(), int(*NodeCheck)(void *), void (*freeData)( void *),int(*compare)(void *, void *));/* add generic node into data base */

void printTree(Tree* tree,void (*printData)( void *));/* prints tree data base */

int freeTree(Tree* tree,void (*freeData)( void *));/* destroys tree data base also realising all memory used */

void * findNode(Tree* tree,int(*compare)(void *, void *),void * t);/* finds a node using a specific field */

void removeNode(Tree* tree,int(*compare)(void *, void *),void (*freeData)( void *),char* field);/* removes node from data base */

void freeNode(Node* node,void (*freeData)( void *));/* realises node from memory */

void treeToArray(Tree* tree,void (*printData)( void *));/* transfers tree data base into array data base */

float averageKey(Tree* tree ,float (*dataCalc) (Node*));/* finds average by specified field */

void* rec_add_Node(Node *root, Node *newNode, int(*compare)(void *, void *)); /* recursive function, adds node into data base */

#endif
