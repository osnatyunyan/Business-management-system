
#ifndef ASSIGMENT_7_CAR_H
#define ASSIGMENT_7_CAR_H

#define NumLicense 7
#define NumChassis 5
#define NumYearOfManufacture 4
#define NumUpRoad 4
#define MaxNumOldPrice 7
#define MaxNumCurrentPrice 7
#define NumEngineCapacity 4
#include "Tree.h"


typedef struct{
  char license[NumLicense+1];
  char chassis[NumChassis+1];
  char* manufacturer; /* Name of manufacturer */
  char* model; /* Name of model */
  char* color;
  char yearOfManufacture[NumYearOfManufacture+1];
  char upRoad[NumUpRoad+1]; /* year the car was upRoad */
  char oldPrice[MaxNumOldPrice+1]; /* price the car sold supplier */
  char currentPrice[MaxNumCurrentPrice+1];
  char engineCapacity[NumEngineCapacity+1];
}Car;


Tree* createCarTree(); /* Setting up a Car tree */

void addNewCar(Tree* treeCar); /* Adding a new car to the tree */

void freeCar(void* freeMe); /* free car data type from memory */

void printCars(Tree* tree); /*The function will print all cars*/

void deleteCar(Tree* tree); /* returns a unique field to search for inorder to delete from data base */

int deleteAllCars(Tree* tree); /* the function will delete all cars from the tree */

int carNumberWithGivenCapacity(Tree* tree); /* the function will return how many cars with the same given engine capacity*/

int carNumberWithGivenYear_REC(Node* nodeCar,char* year,char* license);/* recursive function which returns the amount of cars with given year and license */

int compareLicense(void* car,void* license); /* compares license field*/

int compareCar(void* car,void* root); /* compares car by license */

void printCar(void* printMe); /* print car */

#endif /*ASSIGMENT_7_CAR_H*/
