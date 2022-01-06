
#include "Client.h"
#include "Given.h"

void freeClient(void *freeMe)
{
    checked_free(((Client*)freeMe)->name);
    checked_free(((Client*)freeMe)->family);
}

int compareClient(void* client,void* root){
    return strcmp(((Client *)client)->id, ((Client *)root)->id);
}

int compareClientById(void* client,void* id){
    return strcmp(((Client *)client)->id, (char *)id);
}

int compareClientByDate(void* client,void* date){
    if(strcmp(((Client*)client)->date.day,((Date *)date)->day)==0 && strcmp(((Client*)client)->date.month,((Date *)date)->month)==0 && strcmp(((Client*)client)->date.year,((Date *)date)->year)==0){
        return 0;
    }
    return 1;
}

Tree* createClientTree(){
    return createTree();
}

void addNewClient(Tree* tree)
{
    addNewNode(tree,givenClient,clientCheck,freeClient,compareClient);
}

int deleteAllClients(Tree* tree){
    freeTree(tree,freeClient);
    return 0;
}

int findClient(Tree* tree)
{
    char option;
    char ID[NumId + 1];
    char YEAR[NumYear+1];
    char MONTH[NumMonth+1];
    char DAY[NumDay+1];
    Date date;
    LinkedList *linkedClient = NULL;
    LinkedList *tmp = NULL;

    do{

        printf("\nBy which info would you like to find?\n");
        printf("\n1 - Info - By Date of rent"
               "\n2 - Info - By ID"
               "\n0 - Exit\n");

        scanf(" %c",&option);

        switch (option) {
            case '1':

                printf("\nplease insert year of car rental '0' to Cancel");
                scanf("%s",YEAR);

                printf("\nplease insert month of car rental '0' to Cancel");
                scanf("%s",MONTH);

                printf("\nplease insert day of car rental '0' to Cancel");
                scanf("%s",DAY);

                if(strcmp(YEAR,"0")==0 || strcmp(MONTH,"0")==0 || strcmp(DAY,"0")==0)
                    return 1;

                strcpy(date.year,YEAR);
                strcpy(date.month,MONTH);
                strcpy(date.day,DAY);

                linkedClient=findNode(tree, compareClientByDate, &date);

                tmp = linkedClient;
                while(tmp)
                {
                  printClient(tmp->data);
                  tmp = tmp->next;
                }

                break;

            case '2':
                do{
                    printf("\nplease insert id of Client or '0' to Cancel");
                    scanf("%s", ID);

                    if(strcmp(ID,"0")==0)
                        return 1;

                }
                while(!idCheck(ID));

               linkedClient = findNode(tree, compareClientById, &ID);
              tmp = linkedClient;
              while(tmp)
              {
                printClient(tmp->data);
                tmp = tmp->next;
             }
                break;

            case '0':
            if(linkedClient) {
                    while (linkedClient) {
                        tmp = linkedClient;
                        linkedClient = tmp->next;
                        checked_free(tmp);
                    }
                }
                break;

            default:
                printf("\nInvalid input"
                       "\nPlease try again\n");
        }
    }
    while(option != '0');
    return 0;
}

void printClient(void* printMe)
{
  printf("\nname - %s\nfamily - %s\nid - %s\nlicense - %s\n",((Client*)printMe)->name,
         ((Client*)printMe)->family,((Client*)printMe)->id,((Client*)printMe)->license);
}

int clientNumberWithGivenCarYear_Rec(Node *nodeClient,Tree* carTree,char *year)
{
  if(!nodeClient)
    return 0;

  if(carNumberWithGivenYear_REC(carTree->root,year,((Client*)nodeClient->data)->license) > 0)
  {
    return 1 + clientNumberWithGivenCarYear_Rec(nodeClient->left,carTree,year)
        + clientNumberWithGivenCarYear_Rec(nodeClient->right,carTree,year);
  }
  else
  {
    return clientNumberWithGivenCarYear_Rec(nodeClient->left,carTree,year)
        + clientNumberWithGivenCarYear_Rec(nodeClient->right,carTree,year);
  }
}

int clientNumberWithGivenCarYear(Tree* clientTree,Tree* carTree)
{
  char yearOfManufacture[NumYearOfManufacture + 1];
  do{

    printf("\nPlease insert a valid year of manufacture or '0' to cancel - ");
    scanf("%s", yearOfManufacture);

    if (strcmp(yearOfManufacture, "0") == 0)
      return 0;

  }while(yearOfManufactureCheck(yearOfManufacture));

  printf("Number of clients who own a car from the given year - %d",clientNumberWithGivenCarYear_Rec(clientTree->root,carTree,yearOfManufacture));
  return 1;
}

void printClientsCarGivenRentDateRec(Node* root,Date date){
    if (!root) {
        return ;
    }
    if(strcmp(((Client*)root->data)->date.year,date.year)==0 && strcmp(((Client*)root->data)->date.month,date.month)==0 && strcmp(((Client*)root->data)->date.day,date.day)==0){
        printf("\nname - %s\nfamily - %s\nid - %s\nlicense - %s\n",((Client*)root->data)->name,((Client*)root->data)->family,((Client*)root->data)->id,((Client*)root->data)->license);
    }
    printClientsCarGivenRentDateRec(root->left,date);
    printClientsCarGivenRentDateRec(root->right,date);
}

int printClientsCarForGivenRentDate(Tree* tree)
{

    Date date;

    if(!tree->root)
    {
      printf("\n- - - Clients tree is empty - - -\n");
      return 0;
    }

    date = checkDate();

    if(strcmp(date.year,"0") == 0 || strcmp(date.month,"0") == 0 || strcmp(date.day,"0") == 0)
      return 0;

    printClientsCarGivenRentDateRec(tree->root,date);
    return 1;
}

void deleteClient(Tree* tree)
{
  char* ID = ALLOC(char,NumId + 1);

  do
  {
    printf("\nplease insert ID num or '0' to Cancel");
    scanf("%s", ID);

    if(strcmp(ID,"0")==0)
      return;
    if(idCheck(ID)==1)
      break;

  }while(strcmp(ID,"0")!=0);

  removeNode(tree, compareClientById, freeClient, ID);

}
