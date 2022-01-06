
#ifndef ASSIGMENT_7_CLIENT_H
#define ASSIGMENT_7_CLIENT_H
#define NumLicense 7
#define NumId 9
#define NumDay 2
#define NumMonth 2
#define NumYear 4
#define NumMinutes 2
#define NumHours 2

#include "Car.h"
#include "Tree.h"

typedef struct{
    char day[NumDay+1];
    char month[NumMonth+1];
    char year[NumYear+1];
}Date;

typedef struct{
    char minutes[NumMinutes+1];
    char hours[NumHours+1];
}Hour;

typedef struct {
    char *name;
    char *family;
    char id[NumId+1];
    char license[NumLicense+1];
    Hour hour;
    Date date;
    int price;
}Client;

Tree* createClientTree(); /* Setting up a clients tree */

void addNewClient(Tree* treeCar); /*Adding a new client to the tree*/

void freeClient(void * freeMe); /* free client data type from memory */

int printClientsCarForGivenRentDate(Tree* tree); /*Receives a date from the user and prints all the client who rented their car on that date*/

void deleteClient(Tree* tree); /*Deleting a client from the tree*/

int deleteAllClients(Tree* tree); /* the function will delete all clients from the tree */

int findClient(Tree* tree); /*Finding a client by ID card or car rental date*/

int clientNumberWithGivenCarYear(Tree* clientTree,Tree* carTree); /* the function will return the number of clients holding a car with the year provided*/

int compareClient(void* client,void* root);/* compares car by id */

void printClient(void* printMe);/* print client */

int compareClientById(void* client,void* id); /* compares id field*/


#endif
