
#ifndef ASSIGMENT_7_MENU_H_
#define ASSIGMENT_7_MENU_H_

#include "Check.h"
#include "Testing.h"

int goMainMenu(); /* starts the main menu */

int carMenu(Tree* carTree); /* starts the car menu */

int supplierMenu(Tree* supplierTree); /* starts the supplier menu */

int clientMenu(Tree* clientList,Tree* carTree); /* starts the client menu */

#ifdef TESTING

int testingMenu(Tree* clientList,Tree* carTree,Tree* supplierTree); /* starts the testing menu */

#endif

#endif /*ASSIGMENT5_MENU_H_*/
