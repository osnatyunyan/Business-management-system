
#ifndef ASSIGMENT_7_SUPPLIER_H
#define ASSIGMENT_7_SUPPLIER_H

#define NumBusinessName 10
#define NumPhoneNumber 10
#define NumNumbersOfDeals 5
#define NumSumOfDeals 10
#include "Tree.h"

typedef struct{
char businessName[NumBusinessName+1];
char *nameSupplier;
char phoneNumber[NumPhoneNumber+1];
char numbersOfDeals[NumNumbersOfDeals+1];
char sumOfDeals[NumSumOfDeals+1];
}Supplier;

typedef struct{
  char businessName1[NumBusinessName+1];
  char businessName2[NumBusinessName+1];
  char businessName3[NumBusinessName+1];
}greatestScopes;

Tree* createSupplierTree(); /* Setting up a Supplier tree */

void addNewSupplier(Tree* treeSupplier); /*Adding a new client to the tree*/

void freeSupplier(void* freeMe); /* free supplier data from memory */

void printSuppliers(Tree* tree); /* Deleting a supplier from the tree*/

void deleteSupplier(Tree* tree);/* the function will delete supplier from the tree */

int deleteAllSuppliers(Tree* tree); /* the function will delete all suppliers from the tree */

int threeGreatestSuppliers(Tree* tree); /* the function will return the 3 business names of the suppliers with the greatest scope */

float averageOfSupplierMoney(Tree* tree); /* returns average of sum of deals of all suppliers in data */

int compareSupplier(void* supplier ,void* root);/* compares supplier by business name */

float sumOfDealsType(Node* node); /* convert sum of deals field from string to float */

int compareBusiness(void* supplier,void* businessName);/* compares business name field*/

#endif /*ASSIGMENT_7_SUPPLIER_H*/
