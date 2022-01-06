
#include "Menu.h"


int goMainMenu()
{
  Tree* supplierTree = createSupplierTree();
  Tree* clientTree = createClientTree();
  Tree* carTree = createCarTree();
  char option;

  printf("\nWelcome to Awesome Car Renting Company");
  printf("\nwhat would you like to do today?");

  do{

    printf("\n1 - Car Menu"
           "\n2 - Supplier Menu"
           "\n3 - Client Menu"
           #ifdef TESTING
           "\n4 - Testing Menu"
           #endif
           "\n0 - Exit\n");

    scanf(" %c",&option);

    switch (option) {
      case '1':
        carMenu(carTree);
        break;

        case '2':
          supplierMenu(supplierTree);
          break;

        case '3':
           clientMenu(clientTree,carTree);
           break;

      #ifdef TESTING
      case '4':
        testingMenu(clientTree,carTree,supplierTree);
        break;
      #endif
      case '0':
        deleteAllClients(clientTree);
        deleteAllSuppliers(supplierTree);
        deleteAllCars(carTree);

        checked_free(carTree);
        checked_free(supplierTree);
        checked_free(clientTree);

        break;

      default:
        printf("\nInvalid input"
               "\nPlease try again\n");
    }

  } while(option != '0');

  check_for_exit();
  printf("\n - - Great Success! - -\n");

  return 0;
}

int carMenu(Tree* carTree) {
  char option;

  printf("\n-- Car Menu --");

    do {

        printf("\nwhat would you like to do?\n");
        printf("\n1 - Add new Car"
               "\n2 - Info - how many cars with same engine capacity?"
               "\n3 - Print Cars from data - Array style"
               "\n4 - Print Cars from data"
               "\n5 - Delete Car from data"
               "\n6 - Delete all Cars"
               "\n0 - Exit\n");

        scanf(" %c", &option);

        switch (option) {
            case '1':
                addNewCar(carTree);
                break;

            case '2':
              carNumberWithGivenCapacity(carTree);
              break;

            case '3':
                treeToArray(carTree,printCar);
                break;

            case '4':
                printCars(carTree);
                break;

            case '5':
                deleteCar(carTree);
                break;

            case '6':
                deleteAllCars(carTree);
                break;

            case '0':
                break;

            default:
                printf("\nInvalid input"
                       "\nPlease try again\n");
        }
    }
    while (option != '0');
    return 1;
}

int supplierMenu(Tree* supplierTree) {
    char option;

    printf("\n-- Supplier Menu --");

    do {

        printf("\nwhat would you like to do?\n");
        printf("\n1 - Add new Supplier"
               "\n2 - Info - Three Suppliers with the greatest scoop"
               "\n3 - Info - All suppliers average sum of deals"
               "\n4 - Print Supplier from data"
               "\n5 - Delete Supplier from data"
               "\n6 - Delete all Suppliers"
               "\n0 - Exit\n");

        scanf(" %c", &option);

        switch (option) {
            case '1':
                addNewSupplier(supplierTree);
                break;

            case '2':
              threeGreatestSuppliers(supplierTree);
              break;

          case '3':
              printf("\n The average of all sum of deals is %.3f\n",
                     averageOfSupplierMoney(supplierTree));
            break;

            case '4':
                printSuppliers(supplierTree);
                break;

            case '5':
                deleteSupplier(supplierTree);
                break;

            case '6':
                deleteAllSuppliers(supplierTree);
                break;

            case '0':
                break;

            default:
                printf("\nInvalid input"
                       "\nPlease try again\n");
        }
    }
    while (option != '0');
    return 1;
}

int clientMenu(Tree* clientTree,Tree* carTree)
{
  char option;
  printf("\n-- Client Menu --");

  do{

    printf("\nwhat would you like to do?\n");
    printf("\n1 - Add new Client"
           "\n2 - Info - how many clients have car"
           " with the same provided year of manufacture"
           "\n3 - Info - Find client by * date of rent * Or by * ID *"
           "\n4 - Print Client with same rent day"
           "\n5 - Delete Client from data"
           "\n6 - Delete all Clients"
           "\n0 - Exit\n");

    scanf(" %c",&option);

    switch (option) {
        case '1':
            addNewClient(clientTree);
            break;

        case '2':
            clientNumberWithGivenCarYear(clientTree,carTree);
            break;

        case '3':
            findClient(clientTree);
            break;

        case '4':
            printClientsCarForGivenRentDate(clientTree);
            break;

        case '5':
            deleteClient(clientTree);
            break;

        case '6':
            deleteAllClients(clientTree);
            break;

        case '0':
            break;

      default:
          printf("\nInvalid input"
               "\nPlease try again\n");
    }
  }
  while(option != '0');
  return 1;
}

#ifdef TESTING

int testingMenu(Tree* clientTree,Tree* carTree,Tree* supplierTree)
{
  char option;

  printf("\n-- Testing Menu --");

  do {

    printf("\nwhat would you like to do?\n");
    printf("\n1 - Add new Cars (5)"
           "\n2 - Add new clients(5)"
           "\n3 - Add new suppliers(5)"
           "\n4 - Add new Car"
           "\n5 - Add new Client"
           "\n6 - Add new Supplier"
           "\n0 - Exit\n");

    scanf(" %c", &option);

    switch (option) {
      case '1': /* Cars */
        addCars(carTree,compareCar,freeNode,freeCar);
        break;

      case '2': /* clients */
        addClients(clientTree,compareClient,freeNode,freeClient);
        break;

      case '3': /* suppliers */
        addSuppliers(supplierTree,compareSupplier,freeNode,freeSupplier);
        break;

      case '4': /* Car */
        addOneCar(carTree,compareCar,freeNode,freeCar);
        break;

      case '5': /* Client */
        addOneClients(clientTree,compareClient,freeNode,freeClient);
        break;

      case '6': /* Supplier */
        addOneSuppliers(supplierTree,compareSupplier,freeNode,freeSupplier);
        break;

      case '0':
        break;

      default:
        printf("\nInvalid input"
               "\nPlease try again\n");
    }
  }
  while (option != '0');
  return 1;
}

#endif

