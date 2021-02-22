//
// Created by Grisha on 20.02.2021.
//

#ifndef LAB1_NEW_MENU_H
#define LAB1_NEW_MENU_H

#endif //LAB1_NEW_MENU_H

#include "myVector.h"

myVector *getVector();

void printMenu();

void writeVector(myVector ***arr, int *len, struct myVector **vec);

void printArrVector(myVector ***arr, int len);

void removeArr(myVector ***arr, int *len);

void operationWithVector(myVector **arr, int len, myVector **res);