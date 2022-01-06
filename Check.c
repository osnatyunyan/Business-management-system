#include "Check.h"
#include <ctype.h>
#include <stdlib.h>

int checkDateHelper(Date date) {
    if (strlen(date.day) != NumDay || !(checkInt(date.day, NumDay)) || atoi(date.day) > MAX_DAY ||
        atoi(date.day) < MIN_DAY_MONTH) {
        printf("your day is not valid\n");
        return 1;
    }
    if (strlen(date.month) != NumMonth || !(checkInt(date.month, NumMonth)) || atoi(date.month) > MAX_MONTH ||
        atoi(date.month) < MIN_DAY_MONTH) {
        printf("your month is not valid\n");
        return 1;
    }
    if (strlen(date.year) != NumYear || !(checkInt(date.year, NumYear)) || atoi(date.year) > MAX_YEAR ||
        atoi(date.year) < MIN_YEAR_RENT) {
        printf("your year is not valid\n");
        return 1;
    }
    return 0;
}

Date checkDate() {
    Date date;

    do {
        printf("\nPlease insert a year or '0' to cancel - (between 1980-2021 include) * 4 Digits *");
        scanf("%s", date.year);
        if (strcmp(date.year, "0") == 0) {
            return date;
        }

        printf("\nPlease insert a month or '0' to cancel - (between 01-12 include) * 2 Digits *");
        scanf("%s", date.month);
        if (strcmp(date.month, "0") == 0) {
            return date;
        }

        printf("\nPlease insert a  day or '0' to cancel - (between 01-31 include) * 2 Digits *");
        scanf("%s", date.day);
        if (strcmp(date.day, "0") == 0) {
            return date;
        }
    } while (checkDateHelper(date));

    return date;
}

int checkInt(char testMe[], int size) /* checks if all int */
{
    int i;
    for (i = 0; i < size; i++) {
        if (!(isdigit(testMe[i])))
            return 0;
    }
    return 1;
}

int checkChar(char testMe[], int size) /* checks if all char */
{
    int i;
    for (i = 0; i < size; i++) {
        if (!(isalpha(testMe[i])))
            return 0;
    }
    return 1;
}

int licenseCheck(char license[]) {
    if (strlen(license) != NumLicense || !(checkInt(license, NumLicense))) {
        printf("your license is not valid\n");
        return 0;
    }
    return 1;
}

int idCheck(char id[]) {
    if (strlen(id) != NumId || !(checkInt(id, NumId))) {
        printf("\nyour id is not valid\n");
        return 0;
    }
    return 1;
}

int engineCapacityCheck(char engine[]) {
    if (strlen(engine) != NumEngineCapacity || !(checkInt(engine, NumEngineCapacity))) {
        printf("\nyour engine capacity is not valid\n");
        return 1;
    }
    return 0;
}

int businessNameCheck(char businessName[]) {
    if (strlen(businessName) != NumBusinessName || !(checkInt(businessName, NumBusinessName))) {
        printf("\nyour business name is not valid\n");
        return 0;
    }
    return 1;
}

int yearOfManufactureCheck(char year[]) {
    if (strlen(year) != NumYearOfManufacture || !(checkInt(year, NumYearOfManufacture)) || atoi(year) > MAX_YEAR ||
        atoi(year) < MIN_YEAR) {
        printf("your year of Manufacture is not valid\n");
        return 1;
    }
    return 0;
}

int carCheck(void *newCar) {

    if (strlen(((Car *) newCar)->license) != NumLicense || !(checkInt(((Car *) newCar)->license, NumLicense))) {
        printf("your license is not valid\n");
        return 0;
    }

    if (strlen(((Car *) newCar)->chassis) != NumChassis || !(checkInt(((Car *) newCar)->chassis, NumChassis))) {
        printf("your chassis is not valid\n");
        return 0;
    }
    if (!(checkChar(((Car *) newCar)->manufacturer, strlen(((Car *) newCar)->manufacturer)))) {
        printf("your manufacturer is not valid\n");
        return 0;
    }
    if (strlen(((Car *) newCar)->currentPrice) > MaxNumCurrentPrice ||
        !(checkInt(((Car *) newCar)->currentPrice, strlen(((Car *) newCar)->currentPrice)))) {
        printf("your current Price is not valid\n");
        return 0;
    }
    if (strlen(((Car *) newCar)->engineCapacity) != NumEngineCapacity ||
        !(checkInt(((Car *) newCar)->engineCapacity, NumEngineCapacity))) {
        printf("your engine Capacity is not valid\n");
        return 0;
    }
    if (strlen(((Car *) newCar)->oldPrice) > MaxNumOldPrice ||
        !(checkInt(((Car *) newCar)->oldPrice, strlen(((Car *) newCar)->oldPrice)))) {
        printf("your old Price is not valid\n");
        return 0;
    }
    if (strlen(((Car *) newCar)->upRoad) != NumUpRoad || !(checkInt(((Car *) newCar)->upRoad, NumUpRoad))) {
        printf("your up Road is not valid\n");
        return 0;
    }
    if (strlen(((Car *) newCar)->yearOfManufacture) != NumYearOfManufacture ||
        !(checkInt(((Car *) newCar)->yearOfManufacture, NumYearOfManufacture)) ||
        atoi(((Car *) newCar)->yearOfManufacture) > MAX_YEAR || atoi(((Car *) newCar)->yearOfManufacture) < MIN_YEAR) {
        printf("your year of manufacture is not valid\n");
        return 0;
    }
    if (!(checkChar(((Car *) newCar)->model, strlen(((Car *) newCar)->model)))) {
        printf("your model is not valid\n");
        return 0;
    }
    if (!(checkChar(((Car *) newCar)->color, strlen(((Car *) newCar)->color)))) {
        printf("your color is not valid\n");
        return 0;
    }
    return 1;
}

int supplierCheck(void *newSupplier) {

    if (strlen(((Supplier *)((Supplier *)newSupplier))->businessName) != NumBusinessName ||
        !(checkInt(((Supplier *)newSupplier)->businessName, NumBusinessName))) {
        printf("your business name is not valid\n");
        return 0;
    }

    if (strlen(((Supplier *)newSupplier)->phoneNumber) != NumPhoneNumber || !(checkInt(((Supplier *)newSupplier)->phoneNumber, NumPhoneNumber))) {
        printf("your phone number is not valid\n");
        return 0;
    }
    if (strlen(((Supplier *)newSupplier)->numbersOfDeals) != NumNumbersOfDeals ||
        !(checkInt(((Supplier *)newSupplier)->numbersOfDeals, NumNumbersOfDeals))) {
        printf("your numbersOfDeals is not valid\n");
        return 0;
    }
    if (strlen(((Supplier *)newSupplier)->sumOfDeals) != NumSumOfDeals || !(checkInt(((Supplier *)newSupplier)->sumOfDeals, NumSumOfDeals))) {
        printf("your sumOfDeals is not valid\n");
        return 0;
    }
    return 1;
}

int clientCheck(void *newClient) {

    if (strlen(((Client*)newClient)->id) != NumId || !(checkInt(((Client*)newClient)->id, NumId))) {
        printf("your id is not valid\n");
        return 0;
    }


    if ((checkChar(((Client*)newClient)->name, strlen(((Client*)newClient)->name)) == 0)) {
        printf("your name is not valid\n");
        return 0;
    }
    if (!(checkChar(((Client*)newClient)->family, strlen(((Client*)newClient)->family)))) {
        printf("your family name is not valid\n");
        return 0;
    }


    if (strlen(((Client*)newClient)->license) != NumLicense || !(checkInt(((Client*)newClient)->license, NumLicense))) {
        printf("your license is not valid\n");
        return 0;
    }
    if (((Client*)newClient)->price < 99 || ((Client*)newClient)->price > 999) {
        printf("your price is not valid\n");
        return 0;
    }
    if (strlen(((Client*)newClient)->hour.minutes) != NumMinutes || !(checkInt(((Client*)newClient)->hour.minutes, NumMinutes)) ||
        atoi(((Client*)newClient)->hour.minutes) > MAX_MINUTES || atoi(((Client*)newClient)->hour.minutes) < MIN_MINUTES_HOUR) {
        printf("your minutes is not valid\n");
        return 0;
    }
    if (strlen(((Client*)newClient)->hour.hours) != NumHours || !(checkInt(((Client*)newClient)->hour.hours, NumHours)) ||
        atoi(((Client*)newClient)->date.day) > MAX_HOUR || atoi(((Client*)newClient)->date.day) < MIN_MINUTES_HOUR) {
        printf("your hours is not valid\n");
        return 0;
    }
    if (strlen(((Client*)newClient)->date.day) != NumDay || !(checkInt(((Client*)newClient)->date.day, NumDay)) ||
        atoi(((Client*)newClient)->date.day) > MAX_DAY || atoi(((Client*)newClient)->date.day) < MIN_DAY_MONTH) {
        printf("your day is not valid\n");
        return 0;
    }
    if (strlen(((Client*)newClient)->date.month) != NumMonth || !(checkInt(((Client*)newClient)->date.month, NumMonth)) ||
        atoi(((Client*)newClient)->date.month) > MAX_MONTH || atoi(((Client*)newClient)->date.month) < MIN_DAY_MONTH) {
        printf("your month is not valid\n");
        return 0;
    }
    if (strlen(((Client*)newClient)->date.year) != NumYear || !(checkInt(((Client*)newClient)->date.year, NumYear)) ||
        atoi(((Client*)newClient)->date.year) > MAX_YEAR || atoi(((Client*)newClient)->date.year) < MIN_YEAR_RENT) {
        printf("your year is not valid\n");
        return 0;
    }
    return 1;
}
