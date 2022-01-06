
#include "Tree.h"
#include "Matam.h"

void* createTree() {
    Tree *newTree = ALLOC(Tree, 1);
    newTree->root = NULL;
    newTree->elementCount = 0;
    return newTree;
}

Node* removeNodeReq(Node* node,int(*compare)(void *, void *),void (*freeData)( void *),char* field,Node* tmp)
{
  if(!node)
    return node;
  else if(compare(node->data,field)>0)
    node->left = removeNodeReq(node->left,compare,freeData,field,tmp);
  else if(compare(node->data,field)<0)
    node->right = removeNodeReq(node->right,compare,freeData,field,tmp);

  else
  {
    if(!node->right && !node->left)
    {
      freeNode(node,freeData);
      node = NULL;
    }

    else if(!node->right)
    {
      tmp = node;
      node = node->left;
      freeNode(tmp,freeData);
    }

    else if(!node->left)
    {
      tmp = node;
      node = node->right;
      freeNode(tmp,freeData);
    }

    else
    {
      Node* nodeSwap = ALLOC(Node,1);
      tmp = node->left;

      while(tmp->right)
        tmp = tmp->right;

      nodeSwap->data = node->data;
      node->data = tmp->data;
      tmp->data = nodeSwap->data;

      node->left = removeNodeReq(node->left,compare,freeData,field,tmp);
      checked_free(nodeSwap);
    }
  }
  return node;
}

void removeNode(Tree* tree,int(*compare)(void *, void *),void (*freeData)( void *),char* field)
{
  Node* tmp = ALLOC(Node,1);
  
  if(!field)
  {
    checked_free(field);
    checked_free(tmp);
    printf("\n - - Field of search is not assigned - - \n");
    return;
  }

  tree->root = removeNodeReq(tree->root,compare,freeData,field,tmp);
  checked_free(field);
  checked_free(tmp);

  printf("\n - - Node was successfully deleted - - \n");
}

void* rec_add_Node(Node *root, Node *newNode, int(*compare)(void *, void *)) {
    if (!root) {
        return newNode;
    }
    if (compare(newNode->data, root->data) > 0) {
        root->right = rec_add_Node(root->right, newNode, compare);
    } else {
        root->left = rec_add_Node(root->left, newNode, compare);
    }
    return root;
}

void freeNode(Node* node,void (*freeData)( void *)){
    freeData(node->data);
    checked_free(node->data);
    checked_free(node);
}

void freeTreeRec(Node *root, Tree *tree,void (*freeData)( void *)) {
    if(!root)
        return;
    freeTreeRec(root->left,tree,freeData);
    freeTreeRec(root->right,tree,freeData);
    freeNode(root,freeData);
    tree->elementCount--;
}

int freeTree(Tree* tree,void (*freeData)( void *)){
    if(!tree)
    {
        printf("\n - - There is no data base - - \n");
        return 1;
    }
    freeTreeRec(tree->root,tree,freeData);
    tree->root=NULL;
    if(!tree->elementCount)
        printf("\n - - Tree data deleted - -\n");

  return 0;
}

void printTreeRec(Node* root,void (*printData)( void *)){
    if (!root) {
        return;
    }
  printData(root->data);
  printTreeRec(root->left,printData);
  printTreeRec(root->right,printData);
}

void printTree(Tree* tree,void (*printData)( void *)){
  if(!tree)
    {
     printf("\n - - There is no data base - - \n");
    }
    if (!tree->root){
        printf("\n- - - tree is empty - - -\n");
    }
    printTreeRec(tree->root,printData);
}

int addNewNode(Tree *tree, void *(*givenNode)(), int(*NodeCheck)(void *), void (*freeData)( void *),int(*compare)(void *, void *)) {
    Node *newNode = ALLOC(Node, 1);
    newNode->data = givenNode();

    if (NodeCheck(newNode->data) == 1) {
        newNode->right = NULL;
        newNode->left = NULL;
        tree->root = rec_add_Node(tree->root, newNode, compare);
        printf("\nNode was added into data\n");
        tree->elementCount++;

    }
    else {
        printf("\ndetails are not valid - "
               "Node was not added into data\n");
        freeNode(newNode,freeData);
    }
    return 1;
}

void findNodeHelper(LinkedList** head,Node* root,int(*compare)(void *, void *)){
    LinkedList *tmp=*head;
    LinkedList *prev;
    LinkedList *newNode=ALLOC(LinkedList ,1);
    newNode->data=root->data;
    if((*head)==NULL|| compare(newNode->data,tmp->data)<=0){
        newNode->next=*head;
        *head=newNode;
        return;
    }
    while (tmp){
        if (compare(newNode->data,tmp->data)>0){
            prev=tmp;
            tmp=tmp->next;
            continue;
        } else{
            newNode->next=tmp;
            prev->next=newNode;
            return;
        }
    }
    newNode->next=tmp;
    prev->next=newNode;

}

void findNodeRec(LinkedList **head,Node* root,int(*compare)(void *, void *),void * t){
  if(!root)
    return;

  findNodeRec(head,root->left,compare,t);

  if(compare(root->data,t)==0)
  {
    findNodeHelper(head,root,compare);
  }

  findNodeRec(head,root->right,compare,t);

}

void* findNode(Tree* tree,int(*compare)(void *, void *),void * t){
  LinkedList *head=NULL;
  if (!tree->root) {
    printf("\n- - Tree is empty - -\n");
    return NULL;
  }
  findNodeRec( &head,tree->root,compare,t);
  if (!head) {
    printf("There is no data like this in the System");
  }
  return head;
}

int treeToArrayRec(Node* node,void* arr[],int count)
{
  if(!node)
    return count;

  arr[count] = node->data;
  count++;
  if(node->left)
    count = treeToArrayRec(node->left,arr,count);
  if(node->right)
    count = treeToArrayRec(node->right,arr,count);
  return count;
}

void treeToArray(Tree* tree,void (*printData)( void *))
{
  int i;
  void** arr = ALLOC(void*,tree->elementCount);

  treeToArrayRec(tree->root,arr,0);
  for(i=0;i<tree->elementCount;i++)
    printData(arr[i]);
  checked_free(arr);
}

float averageKeyReq(Node* node,float (*dataCalc) (Node*))
{
  if(!node)
    return 0;
  return (dataCalc(node) + averageKeyReq(node->left,dataCalc) + averageKeyReq(node->right,dataCalc));
}

float averageKey(Tree* tree,float (*dataCalc) (Node*))
{
  return averageKeyReq(tree->root,dataCalc)/tree->elementCount;
}







