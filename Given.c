
#include "Given.h"

void* givenCar()
{
  char manufacturer[100];
  char model[100];
  char color[100];
  Car* newCar=(Car *)ALLOC(Car,1);

  printf("\nplease insert manufacturer * Characters *\n");
  scanf("%s",manufacturer);

  newCar->manufacturer=(char*)ALLOC(char,strlen(manufacturer)+1);
  strcpy(newCar->manufacturer,manufacturer);

  printf("\nplease insert color * Characters *\n");
  scanf("%s",color);

  newCar->color=ALLOC(char,strlen(color)+1);
  strcpy(newCar->color,color);

  printf("\nplease insert model * Characters *\n");
  scanf("%s",model);

  newCar->model=(char*) ALLOC(char,strlen(model)+1);
  strcpy(newCar->model,model);

  printf("\nplease insert drivers license * 7 Digits *\n");
  scanf("%s",newCar->license);

  printf("\nplease insert chassis * 5 Digits *\n");
  scanf("%s",newCar->chassis);

  printf("\nplease insert year of manufacture (between 1930-2021 include) * 4 Digits *\n");
  scanf("%s",newCar->yearOfManufacture);

  printf("\nplease insert drivers upRoad (higher than year of manufacture) * 4 Digits *\n");
  scanf("%s",newCar->upRoad);

  printf("\nplease insert drivers oldPrice * max 7 Digits *\n");
  scanf("%s",newCar->oldPrice);

  printf("\nplease insert drivers currentPrice * max 7 Digits *\n");
  scanf("%s",newCar->currentPrice);

  printf("\nplease insert drivers engineCapacity * 4 Digits *\n");
  scanf("%s",newCar->engineCapacity);

  return newCar;
}

void * givenClient()
{
  char family[100];
  char name[100];
  Client* newClient=(Client *)ALLOC(Client,1);

  printf("please insert client's first name * Characters *");
  scanf("%s",name);

  newClient->name=ALLOC(char,strlen(name)+1);
  strcpy(newClient->name,name);

  printf("please insert client's last name * Characters *");
  scanf("%s",family);

  newClient->family=ALLOC(char,strlen(family)+1);
  strcpy(newClient->family,family);

  printf("please insert client's id * 9 Digits *");
  scanf("%s",newClient->id);

  printf("please insert car license * 7 Digits *");
  scanf("%s",newClient->license);

  /* Date  */

  printf("please insert day of renting (between 01-31 include) * 2 Digits *\n");
  scanf("%s",newClient->date.day);

  printf("please insert month of renting (between 01-12 include) * 2 Digits *\n");
  scanf("%s",newClient->date.month);

  printf("please insert year of renting (between 1980-2021 include) * 4 Digits *\n");
  scanf("%s",newClient->date.year);

  /* Hour  */

  printf("please insert time of renting - minutes (between 00-59 include) * 2 Digits *\n");
  scanf("%s",newClient->hour.minutes);

  printf("please insert time of renting - hours (between 00-23 include) * 2 Digits *\n");
  scanf("%s",newClient->hour.hours);

  printf("please insert car's renting price per day * 3 Digits *");
  scanf("%d", &newClient->price);

  return newClient;
}

void* givenSupplier()
{
  char s[100];
  Supplier* newSupplier=ALLOC(Supplier,1);

  printf("please insert supplier's business name * 10 Digits *");
  scanf("%s",newSupplier->businessName);

  printf("please insert supplier's name * Characters *");
  scanf("%s",s);

  newSupplier->nameSupplier=(char*)ALLOC( char ,strlen(s)+1);
  strcpy(newSupplier->nameSupplier,s);

  printf("please insert supplier's phone number * 10 Digits *");
  scanf("%s",newSupplier->phoneNumber);

  printf("please insert supplier's numbersOfDeals * 5 Digits * ");
  scanf("%s",newSupplier->numbersOfDeals);

  printf("please insert supplier's sumOfDeals * 10 Digit * ");
  scanf("%s",newSupplier->sumOfDeals);

  return newSupplier;
}
