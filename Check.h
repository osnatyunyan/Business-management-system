
#ifndef ASSIGMENT_7_CHECK_H
#define ASSIGMENT_7_CHECK_H


#include <stdio.h>
#include <string.h>
#include "Car.h"
#include "Supplier.h"
#include "Client.h"
#include "Matam.h"

#define MAX_YEAR 2021
#define MIN_YEAR 1930
#define MIN_MINUTES_HOUR 0
#define MAX_MINUTES 59
#define MAX_HOUR 23
#define MIN_YEAR_RENT 1980
#define MIN_DAY_MONTH 1
#define MAX_DAY 31
#define MAX_MONTH 12


int carCheck(void* newCar ); /* checks if the given car is valid */

int clientCheck(void* newClient); /* checks if the given client is valid */

int supplierCheck(void* newSupplier ); /* checks if the given supplier is valid */

int checkInt(char testMe[],int size); /* checks if all int */

int checkChar(char testMe[],int size);/* checks if all char */

int licenseCheck(char license[]); /* check whether license is valid */

int idCheck(char id[]); /* check whether id is valid */

int businessNameCheck(char businessName[]); /* check whether business name is valid */

int engineCapacityCheck(char engine[]); /* check whether engine capacity is valid */

int yearOfManufactureCheck(char year[]); /* checks if year of manufacture is valid */

Date checkDate(); /*Receives dare and check if the date is valid*/

#endif /*ASSIGMENT_7_CHECK_H*/
