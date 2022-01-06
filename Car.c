
#include "Car.h"
#include "Given.h"


Tree* createCarTree(){
    return createTree();
}

void freeCar(void* freeMe)
{
  checked_free(((Car*)freeMe)->model);
  checked_free(((Car*)freeMe)->manufacturer);
  checked_free(((Car*)freeMe)->color);
}

int compareCar(void* car,void* root){
    return  strcmp(((Car*)car)->license, ((Car*)root)->license);
}

void addNewCar(Tree* tree)
{
    addNewNode(tree,givenCar,carCheck,freeCar,compareCar);
}

void printCar(void* printMe){
    printf("\nlicense - %s \nchassis - %s \nmanufacturer - %s \nmodel - %s \ncolor - %s \nyearOfManufacture - %s \nupRoad - %s \noldPrice - %s \ncurrentPrice - %s \nengineCapacity - %s\n",
           ((Car*)printMe)->license,((Car*)printMe)->chassis,((Car*)printMe)->manufacturer,((Car*)printMe)->model,((Car*)printMe)->color,
           ((Car*)printMe)->yearOfManufacture,((Car*)printMe)->upRoad,((Car*)printMe)->oldPrice,((Car*)printMe)->currentPrice,((Car*)printMe)->engineCapacity);
}

void printCars(Tree* tree){
    printTree(tree,printCar);
}

int deleteAllCars(Tree* tree){
    freeTree(tree,freeCar);
    return 0;
}

int compareLicense(void* car,void* license)
{
  return strcmp(((Car*)car)->license,(char*) license);
}

void deleteCar(Tree* tree)
{
  char* license = ALLOC(char,NumLicense + 1);

  do
  {
    printf("\nplease insert license of Car or '0' to Cancel");
    scanf("%s", license);

    if(strcmp(license,"0")==0)
      return;
    if(licenseCheck(license)==1)
      break;

  }while(strcmp(license,"0")!=0);

  removeNode(tree, compareLicense, freeCar, license);

}
int carNumberWithGivenCapacity_REC(Node* nodeCar,char* capacity)
{
  if(!nodeCar)
    return 0;

  if(!strcmp(((Car*)nodeCar->data)->engineCapacity,capacity))
  {
    return 1 + carNumberWithGivenCapacity_REC(nodeCar->left,capacity)
        + carNumberWithGivenCapacity_REC(nodeCar->right,capacity);
  }
  else
  {
    return carNumberWithGivenCapacity_REC(nodeCar->left,capacity)
        + carNumberWithGivenCapacity_REC(nodeCar->right,capacity);
  }
}

int carNumberWithGivenCapacity(Tree* tree)
{
  char capacity[NumEngineCapacity + 1];

  if (tree->root == NULL) {
    printf("\n- - Car data is empty - -\n");
    return 1;
  }

  do{
    printf("\nPlease insert valid Engine Capacity or '0' to cancel - ");
    scanf("%s", capacity);
  }while(engineCapacityCheck(capacity));

  if (strcmp(capacity, "0") == 0)
    return 0;

  printf("Number of cars with same capacity - %d",carNumberWithGivenCapacity_REC(tree->root,capacity));
  return 1;
}

int carNumberWithGivenYear_REC(Node* nodeCar,char* year,char* license)
{
  if(!nodeCar)
    return 0;

  if(!strcmp(((Car*)nodeCar->data)->yearOfManufacture,year) && !strcmp(((Car*)nodeCar->data)->license,license))
  {
    return 1 + carNumberWithGivenYear_REC(nodeCar->left,year,license)
        + carNumberWithGivenYear_REC(nodeCar->right,year,license);
  }
  else
  {
    return carNumberWithGivenYear_REC(nodeCar->left,year,license)
        + carNumberWithGivenYear_REC(nodeCar->right,year,license);
  }
}
