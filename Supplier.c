
#include "Supplier.h"
#include "Given.h"

Tree* createSupplierTree(){
    return createTree();
}

void freeSupplier(void *freeMe)
{
  checked_free(((Supplier*)freeMe)->nameSupplier);
}

int compareSupplier(void* supplier ,void* root){
    return strcmp(((Supplier *)supplier)->businessName, ((Supplier *)root)->businessName);
}

void addNewSupplier(Tree* tree)
{
    addNewNode(tree,givenSupplier,supplierCheck,freeSupplier,compareSupplier);
}

void printSupplier(void* printMe) {
    printf("\nname - %s\nbusinessName - %s\nphoneNumber - %s\nsumOfDeals - %s\nnumbersOfDeals - %s\n "
            ,((Supplier*)printMe)->nameSupplier,((Supplier*)printMe)->businessName,((Supplier*)printMe)->phoneNumber,((Supplier*)printMe)->sumOfDeals,((Supplier*)printMe)->numbersOfDeals);
}

void printSuppliers(Tree* tree){
    printTree(tree,printSupplier);
}

int deleteAllSuppliers(Tree* tree){
    freeTree(tree,freeSupplier);
    return 0;
}

float sumOfDealsType(Node* node)
{
  return atof(((Supplier*)node->data)->sumOfDeals);
}

float averageOfSupplierMoney(Tree* tree)
{
  return averageKey(tree,sumOfDealsType);
}

int threeGreatestHelper(Node* root, greatestScopes *g,double greatestSums[]) {
  if (!root) {
    return 0;
  }
  if (atof(((Supplier*)root->data)->sumOfDeals) > greatestSums[0]) {
    greatestSums[2] = greatestSums[1];
    greatestSums[1] = greatestSums[0];
    greatestSums[0] = atof(((Supplier*)root->data)->sumOfDeals);
    strcpy(g->businessName3, g->businessName2);
    strcpy(g->businessName2, g->businessName1);
    strcpy(g->businessName1, ((Supplier*)root->data)->businessName);
  }
  else if (atof(((Supplier*)root->data)->sumOfDeals) > greatestSums[1]) {
    greatestSums[2] = greatestSums[1];
    greatestSums[1] = atof(((Supplier*)root->data)->sumOfDeals);
    strcpy(g->businessName3, g->businessName2);
    strcpy(g->businessName2, ((Supplier*)root->data)->businessName);
  }
  else if (atof(((Supplier*)root->data)->sumOfDeals) > greatestSums[2]) {
    greatestSums[2] = atof(((Supplier*)root->data)->sumOfDeals);
    strcpy(g->businessName3, ((Supplier*)root->data)->businessName);
  }
  threeGreatestHelper(root->left, g, greatestSums);
  threeGreatestHelper(root->right, g, greatestSums);
  return 0;
}

int threeGreatestSuppliers(Tree * tree){
  double greatestSums[3] = {0,0,0};
  greatestScopes g;
  threeGreatestHelper(tree->root,&g,greatestSums);

  printf("\n\nThree greatest scopes - \nFirst = %s \nSecond = %s \nThird = %s",
         g.businessName1, g.businessName2, g.businessName3);

  return 0;
}

int compareBusiness(void* supplier,void* businessName)
{
  return strcmp(((Supplier *)supplier)->businessName,(char*) businessName);
}

void deleteSupplier(Tree* tree)
{

  char* businessName = ALLOC(char,NumBusinessName + 1);

  do
  {
    printf("\nplease insert business name of supplier or '0' to Cancel");
    scanf("%s", businessName);

    if(strcmp(businessName,"0")==0)
      return;
    if(businessNameCheck(businessName)==1)
      break;

  }while(strcmp(businessName,"0")!=0);

  removeNode(tree, compareBusiness, freeSupplier, businessName);

}

